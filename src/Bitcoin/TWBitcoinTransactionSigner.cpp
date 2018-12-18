// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinTransactionSigner.h>
#include <TrustWalletCore/TWBitcoinOpCodes.h>
#include <TrustWalletCore/TWHash.h>
#include <TrustWalletCore/TWPrivateKey.h>

#include <vector>

#include "TWBitcoinTransaction_Internal.h"
#include "TWBitcoinSigningProvider_Internal.h"
#include "TWBitcoinUnspentTransaction_Internal.h"
#include "TWBinaryCoding.h"

using namespace std;

struct TWBitcoinTransactionSigner {
    TWBitcoinSigningProvider *provider;
    TWBitcoinTransaction transaction;
    const uint32_t hashType;
    vector<TWBitcoinUnspentTransaction> utxos;

    vector<TWBitcoinTransactionInput> signedInputs;

    bool sign(TWBitcoinScriptSharedPtr& script, size_t index, TWBitcoinUnspentTransaction& utxo);
    vector<vector<uint8_t>> signStep(const TWBitcoinScript& script, size_t index, const TWBitcoinUnspentTransaction& utxo, uint32_t version);
    vector<uint8_t> createSignature(const TWBitcoinTransaction& transaction, const TWBitcoinScript& script, const array<uint8_t, TWPrivateKeySize>& key, size_t index, uint64_t amount, uint32_t version);
    vector<uint8_t> pushAll(const vector<vector<uint8_t>>& results);

    /// Encodes a small integer
    static uint8_t encodeNumber(int n) {
        assert(n >= 0 && n <= 16);
        if (n == 0) {
            return OP_0;
        }
        return OP_1 + uint8_t(n - 1);
    }
};

struct TWBitcoinTransactionSigner *_Nonnull TWBitcoinTransactionSignerCreate(struct TWBitcoinSigningProvider *_Nonnull provider, struct TWBitcoinTransaction *_Nonnull transaction, uint32_t hashType) {
    return new TWBitcoinTransactionSigner{
        .provider = provider,
        .transaction = *transaction,
        .hashType = hashType
    };
}

void TWBitcoinTransactionSignerDelete(struct TWBitcoinTransactionSigner *_Nonnull signer) {
    delete signer;
}

void TWBitcoinTransactionSignerAddUnspent(struct TWBitcoinTransactionSigner *_Nonnull signer, struct TWBitcoinOutPoint outPoint, struct TWBitcoinScript *_Nonnull script, uint64_t amount) {
    auto utxo = TWBitcoinUnspentTransaction{
        .outPoint = outPoint,
        .script = TWBitcoinScriptMakeUnique(TWBitcoinScriptCreateCopy(script)),
        .amount = amount
    };
    signer->utxos.push_back(move(utxo));
}

struct TWBitcoinTransaction *_Nullable TWBitcoinTransactionSignerSign(struct TWBitcoinTransactionSigner *_Nonnull signer) {
    signer->signedInputs.clear();
    copy(begin(signer->transaction.inputs), end(signer->transaction.inputs), back_inserter(signer->signedInputs));

    const bool hashSingle = ((signer->hashType & ~TWSignatureHashTypeAnyoneCanPay) == TWSignatureHashTypeSingle);
    for (auto i = 0; i < signer->utxos.size(); i += 1) {
        auto& utxo = signer->utxos[i];

        // Only sign TWSignatureHashTypeSingle if there's a corresponding output
        if (hashSingle && i >= signer->transaction.outputs.size()) {
            continue;
        }
        if (!signer->sign(utxo.script, i, utxo)) {
            return nullptr;
        }
    }

    auto tx = new TWBitcoinTransaction(signer->transaction.version, signer->transaction.lockTime);
    tx->inputs = move(signer->signedInputs);
    tx->outputs = signer->transaction.outputs;
    return tx;
}

bool TWBitcoinTransactionSigner::sign(TWBitcoinScriptSharedPtr& script, size_t index, TWBitcoinUnspentTransaction& utxo) {
    TWBitcoinScriptSharedPtr redeemScript;
    vector<vector<uint8_t>> witnessStack;

    uint32_t signatureVersion = [this]() {
        if ((hashType & TWSignatureHashTypeFork) != 0) {
            return WITNESS_V0;
        } else {
            return BASE;
        }
    }();
    auto results = signStep(*script, index, utxo, signatureVersion);
    auto txin = transaction.inputs[index];

    if (script->isPayToScriptHash()) {
        script = TWBitcoinScriptMakeShared(TWBitcoinScriptCreateWithBytes(results.front().data(), results.front().size()));
        results = signStep(*script, index, utxo, signatureVersion);
        results.push_back(script->bytes);
        redeemScript = script;
    }

    std::vector<uint8_t> data;
    if (script->matchPayToWitnessPublicKeyHash(data)) {
        auto witnessScript = TWBitcoinScript::buildPayToPublicKeyHash(results[0]);
        results = signStep(witnessScript, index, utxo, WITNESS_V0);
        witnessStack = results;
        results.clear();
    } else if (script->matchPayToWitnessScriptHash(data)) {
        auto witnessScript = TWBitcoinScript(results[0]);
        results = signStep(witnessScript, index, utxo, WITNESS_V0);
        results.push_back(move(witnessScript.bytes));

        witnessStack = results;
        results.clear();
    } else if (TWBitcoinScriptIsWitnessProgram(script.get())) {
        // Error: Unrecognized witness program.
        return false;
    }

    if (redeemScript) {
        results.push_back(redeemScript->bytes);
    }

    signedInputs[index] = TWBitcoinTransactionInput(txin.previousOutput, TWBitcoinScript(pushAll(results)), txin.sequence);
    signedInputs[index].scriptWitness = witnessStack;
    return true;
}

vector<vector<uint8_t>> TWBitcoinTransactionSigner::signStep(const TWBitcoinScript& script, size_t index, const TWBitcoinUnspentTransaction& utxo, uint32_t version) {
    auto transactionToSign = TWBitcoinTransaction(transaction.version, transaction.lockTime);
    transactionToSign.inputs = signedInputs;
    transactionToSign.outputs = transaction.outputs;

    std::vector<uint8_t> data;
    vector<vector<uint8_t>> keys;
    int required;

    if (script.matchPayToScriptHash(data)) {
        auto redeemScript = provider->scriptForScriptHash(data);
        if (redeemScript == nullptr) {
            // Error: Missing redeem script
            return {};
        }
        return {*redeemScript};
    } else if (script.matchPayToWitnessScriptHash(data)) {
        auto scripthash = TW::Hash::ripemd(data);
        auto redeemScript = provider->scriptForScriptHash(scripthash);
        if (redeemScript == nullptr) {
            // Error: Missing redeem script
            return {};
        }
        return {*redeemScript};
    } else if (script.matchPayToWitnessPublicKeyHash(data)) {
        return {data};
    } else if (script.isWitnessProgram()) {
        // Error: Invalid sutput script
        return {};
    } else if (script.matchMultisig(keys, required)) {
        auto results = vector<vector<uint8_t>>{{}}; // workaround CHECKMULTISIG bug
        for (auto& pubKey : keys) {
            if (results.size() >= required + 1) {
                break;
            }
            auto keyHash = TW::Hash::ripemd(TW::Hash::sha256(pubKey));
            auto key = provider->keyForPublicKeyHash(keyHash);
            if (!key) {
                // Error: missing key
                return {};
            }
            auto signature = createSignature(transactionToSign, script, *key, index, utxo.amount, version);
            if (signature.empty()) {
                // Error: Failed to sign
                return {};
            }
            results.push_back(signature);
        }
        results.resize(required + 1);
        return results;
    } else if (script.matchPayToPubkey(data)) {
        auto keyHash = TW::Hash::ripemd(TW::Hash::sha256(data));
        auto key = provider->keyForPublicKeyHash(keyHash);
        if (!key) {
            // Error: Missing key
            return {};
        }
        auto signature = createSignature(transactionToSign, script, *key, index, utxo.amount, version);
        if (signature.empty()) {
            // Error: Failed to sign
            return {};
        }
        return {signature};
    } else if (script.matchPayToPubkeyHash(data)) {
        auto key = provider->keyForPublicKeyHash(data);
        if (!key) {
            // Error: Missing keyxs
            return {};
        }

        auto pubkey = TWPrivateKey(*key).getPublicKey(true);
        auto signature = createSignature(transactionToSign, script, *key, index, utxo.amount, version);
        if (signature.empty()) {
            // Error: Failed to sign
            return {};
        }
        return {signature, pubkey};
    } else {
        // Error: Invalid output script
        return {};
    }
}

vector<uint8_t> TWBitcoinTransactionSigner::createSignature(const TWBitcoinTransaction& transaction, const TWBitcoinScript& script, const array<uint8_t, TWPrivateKeySize>& key, size_t index, uint64_t amount, uint32_t version) {
    auto sighash = transaction.getSignatureHash(script, index, hashType,  amount, static_cast<TWBitcoinSignatureVersion>(version));
    auto pk = TWPrivateKey(key);
    auto sig = pk.signAsDER(vector<uint8_t>(begin(sighash), end(sighash)));
    if (sig.empty()) {
        return {};
    }
    sig.push_back(static_cast<uint8_t>(hashType));
    return sig;
}

vector<uint8_t> TWBitcoinTransactionSigner::pushAll(const vector<vector<uint8_t>>& results) {
    auto data = vector<uint8_t>{};
    for (auto& result : results) {
        if (result.empty()) {
            data.push_back(OP_0);
        } else if (result.size() == 1 && result[0] >= 1 && result[0] <= 16) {
            data.push_back(encodeNumber(result[0]));
        } else if (result.size() < OP_PUSHDATA1) {
            data.push_back(static_cast<uint8_t>(result.size()));
        } else if (result.size() <= 0xff) { // swiftlint:disable:this empty_count
            data.push_back(OP_PUSHDATA1);
            data.push_back(static_cast<uint8_t>(result.size()));
        } else if (result.size() <= 0xffff) { // swiftlint:disable:this empty_count
            data.push_back(OP_PUSHDATA2);
            encode16(result.size(), data);
        } else {
            data.push_back(OP_PUSHDATA4);
            encode32(result.size(), data);
        }
        std::copy(begin(result), end(result), back_inserter(data));
    }
    return data;
}
