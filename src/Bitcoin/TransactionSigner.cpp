// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "TransactionSigner.h"

#include "TransactionInput.h"
#include "TransactionOutput.h"
#include "TWBinaryCoding.h"
#include "UnspentSelector.h"
#include "../Hash.h"
#include "../HexCoding.h"

using namespace TW;
using namespace TW::Bitcoin;

Transaction TransactionSigner::build() {
    utxos = UnspentSelector::select(input.utxo(), input.amount());
    if (utxos.empty()) {
        return {};
    }

    const auto fee = UnspentSelector::calculateFee(utxos.size(), 2);
    Amount totalAmount = 0;
    for (auto& utxo : utxos) {
        totalAmount += utxo.amount();
    }
    assert(totalAmount >= input.amount() + fee);

    auto lockingScriptTo = Script::buildForAddress(input.to_address());
    if (lockingScriptTo.empty()) {
        return {};
    }

    auto tx = Transaction(1, 0);
    tx.outputs.push_back(TransactionOutput(input.amount(), lockingScriptTo));

    auto change = totalAmount - input.amount() - fee;
    if (change > 0) {
        auto lockingScriptChange = Script::buildForAddress(input.change_address());
        tx.outputs.push_back(TransactionOutput(change, lockingScriptChange));
    }

    const auto emptyScript = Script();
    for (auto& utxo : utxos) {
        tx.inputs.emplace_back(utxo.out_point(), emptyScript, UINT32_MAX);
    }

    return tx;
}

std::unique_ptr<Transaction> TransactionSigner::sign() {
    signedInputs.clear();
    std::copy(std::begin(transaction.inputs), std::end(transaction.inputs), std::back_inserter(signedInputs));

    const bool hashSingle = ((input.hash_type() & ~TWSignatureHashTypeAnyoneCanPay) == TWSignatureHashTypeSingle);
    for (auto i = 0; i < utxos.size(); i += 1) {
        auto& utxo = utxos[i];

        // Only sign TWSignatureHashTypeSingle if there's a corresponding output
        if (hashSingle && i >= transaction.outputs.size()) {
            continue;
        }
        auto script = Script(utxo.script().begin(), utxo.script().end());
        if (!sign(script, i, utxo)) {
            return nullptr;
        }
    }

    auto tx = std::make_unique<Transaction>(transaction.version, transaction.lockTime);
    tx->inputs = move(signedInputs);
    tx->outputs = transaction.outputs;
    return tx;
}

bool TransactionSigner::sign(Script script, size_t index, const TW::proto::BitcoinUnspentTransaction& utxo) {
    Script redeemScript;
    std::vector<std::vector<uint8_t>> witnessStack;

    uint32_t signatureVersion = [this]() {
        if ((input.hash_type() & TWSignatureHashTypeFork) != 0) {
            return WITNESS_V0;
        } else {
            return BASE;
        }
    }();
    auto results = signStep(script, index, utxo, signatureVersion);
    if (results.empty()) {
        return false;
    }
    auto txin = transaction.inputs[index];

    if (script.isPayToScriptHash()) {
        script = Script(results.front().begin(), results.front().end());
        results = signStep(script, index, utxo, signatureVersion);
        results.push_back(script.bytes);
        redeemScript = script;
    }

    std::vector<uint8_t> data;
    if (script.matchPayToWitnessPublicKeyHash(data)) {
        auto witnessScript = Script::buildPayToPublicKeyHash(results[0]);
        results = signStep(witnessScript, index, utxo, WITNESS_V0);
        witnessStack = results;
        results.clear();
    } else if (script.matchPayToWitnessScriptHash(data)) {
        auto witnessScript = Script(results[0].begin(), results[0].end());
        results = signStep(witnessScript, index, utxo, WITNESS_V0);
        results.push_back(move(witnessScript.bytes));

        witnessStack = results;
        results.clear();
    } else if (script.isWitnessProgram()) {
        // Error: Unrecognized witness program.
        return false;
    }

    if (!redeemScript.bytes.empty()) {
        results.push_back(redeemScript.bytes);
    }

    signedInputs[index] = TransactionInput(txin.previousOutput, Script(pushAll(results)), txin.sequence);
    signedInputs[index].scriptWitness = witnessStack;
    return true;
}

std::vector<std::vector<uint8_t>> TransactionSigner::signStep(Script script, size_t index, const TW::proto::BitcoinUnspentTransaction& utxo, uint32_t version) {
    auto transactionToSign = Transaction(transaction.version, transaction.lockTime);
    transactionToSign.inputs = signedInputs;
    transactionToSign.outputs = transaction.outputs;

    std::vector<uint8_t> data;
    std::vector<std::vector<uint8_t>> keys;
    int required;

    if (script.matchPayToScriptHash(data)) {
        auto redeemScript = scriptForScriptHash(data);
        if (redeemScript.empty()) {
            // Error: Missing redeem script
            return {};
        }
        return {redeemScript};
    } else if (script.matchPayToWitnessScriptHash(data)) {
        auto scripthash = TW::Hash::ripemd(data);
        auto redeemScript = scriptForScriptHash(scripthash);
        if (redeemScript.empty()) {
            // Error: Missing redeem script
            return {};
        }
        return {redeemScript};
    } else if (script.matchPayToWitnessPublicKeyHash(data)) {
        return {data};
    } else if (script.isWitnessProgram()) {
        // Error: Invalid sutput script
        return {};
    } else if (script.matchMultisig(keys, required)) {
        auto results = std::vector<std::vector<uint8_t>>{{}}; // workaround CHECKMULTISIG bug
        for (auto& pubKey : keys) {
            if (results.size() >= required + 1) {
                break;
            }
            auto keyHash = TW::Hash::ripemd(TW::Hash::sha256(pubKey));
            auto key = keyForPublicKeyHash(keyHash);
            if (key.empty()) {
                // Error: missing key
                return {};
            }
            auto signature = createSignature(transactionToSign, script, key, index, utxo.amount(), version);
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
        auto key = keyForPublicKeyHash(keyHash);
        if (key.empty()) {
            // Error: Missing key
            return {};
        }
        auto signature = createSignature(transactionToSign, script, key, index, utxo.amount(), version);
        if (signature.empty()) {
            // Error: Failed to sign
            return {};
        }
        return {signature};
    } else if (script.matchPayToPubkeyHash(data)) {
        auto key = keyForPublicKeyHash(data);
        if (key.empty()) {
            // Error: Missing keyxs
            return {};
        }

        auto pubkey = PrivateKey(key).getPublicKey(true);
        auto signature = createSignature(transactionToSign, script, key, index, utxo.amount(), version);
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

std::vector<uint8_t> TransactionSigner::createSignature(const Transaction& transaction, const Script& script, const std::vector<uint8_t>& key, size_t index, Amount amount, uint32_t version) {
    auto sighash = transaction.getSignatureHash(script, index, input.hash_type(),  amount, static_cast<TWBitcoinSignatureVersion>(version));
    auto pk = PrivateKey(key);
    auto sig = pk.signAsDER(std::vector<uint8_t>(begin(sighash), end(sighash)));
    if (sig.empty()) {
        return {};
    }
    sig.push_back(static_cast<uint8_t>(input.hash_type()));
    return sig;
}

std::vector<uint8_t> TransactionSigner::pushAll(const std::vector<std::vector<uint8_t>>& results) {
    auto data = std::vector<uint8_t>{};
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

std::vector<uint8_t> TransactionSigner::keyForPublicKeyHash(const std::vector<uint8_t>& hash) const {
    for (auto& key : input.private_key()) {
        auto publicKey = PrivateKey(key).getPublicKey(true);
        auto keyHash = TW::Hash::ripemd(TW::Hash::sha256(publicKey));
        if (std::equal(std::begin(keyHash), std::end(keyHash), std::begin(hash), std::end(hash))) {
            return std::vector<uint8_t>(key.begin(), key.end());
        }
    }
    return {};
}

std::vector<uint8_t> TransactionSigner::scriptForScriptHash(const std::vector<uint8_t>& hash) const {
    auto hashString = hex(hash.begin(), hash.end());
    auto it = input.scripts().find(hashString);
    if (it == input.scripts().end()) {
        // Error: Missing redeem script
        return {};
    }
    return std::vector<uint8_t>(it->second.begin(), it->second.end());
}
