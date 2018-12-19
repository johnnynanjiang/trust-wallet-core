// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "TWBitcoinTransaction_Internal.h"

#include <TrustWalletCore/TWBitcoin.h>
#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWBitcoinUnspentTransaction.h>
#include <TrustWalletCore/TWHash.h>

#include <TrezorCrypto/segwit_addr.h>
#include <vector>

#include "TWBinaryCoding.h"

using namespace std;

TWBitcoinScript *buildScript(TWBech32Address address);

struct TWBitcoinTransaction *_Nonnull TWBitcoinTransactionCreate(int version, uint32_t lockTime) {
    auto output = new TWBitcoinTransaction(static_cast<int32_t>(version), lockTime);
    return output;
}

void TWBitcoinTransactionDelete(struct TWBitcoinTransaction *_Nonnull transaction) {
    delete transaction;
}

int32_t TWBitcoinTransactionVersion(struct TWBitcoinTransaction *_Nonnull transaction) {
    return transaction->version;
}

uint32_t TWBitcoinTransactionLockTime(struct TWBitcoinTransaction *_Nonnull transaction) {
    return transaction->lockTime;
}

size_t TWBitcoinTransactionInputCount(struct TWBitcoinTransaction *_Nonnull transaction) {
    return transaction->inputs.size();
}

struct TWBitcoinTransactionInput *_Nonnull TWBitcoinTransactionGetInput(struct TWBitcoinTransaction *_Nonnull transaction, size_t index) {
    return &transaction->inputs[index];
}

void TWBitcoinTransactionAddInput(struct TWBitcoinTransaction *_Nonnull transaction, struct TWBitcoinOutPoint previousOutput, struct TWBitcoinScript *script, uint32_t sequence) {
    transaction->inputs.emplace_back(previousOutput, *script, sequence);
}

size_t TWBitcoinTransactionOutputCount(struct TWBitcoinTransaction *_Nonnull transaction) {
    return transaction->outputs.size();
}

struct TWBitcoinTransactionOutput *_Nonnull TWBitcoinTransactionGetOutput(struct TWBitcoinTransaction *_Nonnull transaction, size_t index) {
    return &transaction->outputs[index];
}

void TWBitcoinTransactionAddOutput(struct TWBitcoinTransaction *_Nonnull transaction, uint64_t value, TWBitcoinScript *_Nonnull script) {
    transaction->outputs.emplace_back(value, *script);
}

TWData *_Nonnull TWBitcoinTransactionEncode(struct TWBitcoinTransaction *_Nonnull transaction, bool witness) {
    auto data = vector<uint8_t>{};
    transaction->encode(witness, data);
    return TWDataCreateWithBytes(data.data(), data.size());
}

TWData *_Nonnull TWBitcoinTransactionHash(struct TWBitcoinTransaction *_Nonnull transaction) {
    auto data = TWBitcoinTransactionEncode(transaction, false);
    auto result = TWHashSHA256SHA256(data);
    TWDataDelete(data);
    return result;
}

TWData *_Nonnull TWBitcoinTransactionWitnessHash(struct TWBitcoinTransaction *_Nonnull transaction) {
    auto data = TWBitcoinTransactionEncode(transaction, true);
    auto result = TWHashSHA256SHA256(data);
    TWDataDelete(data);
    return result;
}

TWString *_Nonnull TWBitcoinTransactionIdentifier(struct TWBitcoinTransaction *_Nonnull transaction) {
    auto data = TWBitcoinTransactionEncode(transaction, false);
    auto hash = TWHashSHA256SHA256(data);
    TWDataDelete(data);
    TWDataReverse(hash);
    auto string = TWStringCreateWithHexData(hash);
    TWDataDelete(hash);
    return string;
}

TWString *_Nonnull TWBitcoinTransactionWitnessIdentifier(struct TWBitcoinTransaction *_Nonnull transaction) {
    auto data = TWBitcoinTransactionEncode(transaction, true);
    auto hash = TWHashSHA256SHA256(data);
    TWDataDelete(data);
    TWDataReverse(hash);
    auto string = TWStringCreateWithHexData(hash);
    TWDataDelete(hash);
    return string;
}

vector<uint8_t> TWBitcoinTransaction::getPreImage(const TWBitcoinScript& scriptCode, int index, uint32_t hashType, uint64_t amount) const {
    assert(index < inputs.size());

    auto data = vector<uint8_t>{};

    // Version
    encode32(version, data);

    // Input prevouts (none/all, depending on flags)
    if ((hashType & TWSignatureHashTypeAnyoneCanPay) == 0) {
        auto hashPrevouts = getPrevoutHash();
        copy(begin(hashPrevouts), end(hashPrevouts), back_inserter(data));
    } else {
        fill_n(back_inserter(data), 32, 0);
    }

    // Input nSequence (none/all, depending on flags)
    if ((hashType & TWSignatureHashTypeAnyoneCanPay) == 0 && !TWSignatureHashTypeIsSingle(hashType) && !TWSignatureHashTypeIsNone(hashType)) {
        auto hashSequence = getSequenceHash();
        copy(begin(hashSequence), end(hashSequence), back_inserter(data));
    } else {
        fill_n(back_inserter(data), 32, 0);
    }

    // The input being signed (replacing the scriptSig with scriptCode + amount)
    // The prevout may already be contained in hashPrevout, and the nSequence
    // may already be contain in hashSequence.
    reinterpret_cast<const TW::Bitcoin::OutPoint&>(inputs[index].previousOutput).encode(data);
    scriptCode.encode(data);

    encode64(amount, data);
    encode32(inputs[index].sequence, data);

    // Outputs (none/one/all, depending on flags)
    if (!TWSignatureHashTypeIsSingle(hashType) && !TWSignatureHashTypeIsNone(hashType)) {
        auto hashOutputs = getOutputsHash();
        copy(begin(hashOutputs), end(hashOutputs), back_inserter(data));
    } else if (TWSignatureHashTypeIsSingle(hashType) && index < outputs.size()) {
        auto outputData = std::vector<uint8_t>{};
        outputs[index].encode(outputData);
        auto hashOutputs = TW::Hash::sha256(TW::Hash::sha256(outputData));
        copy(begin(hashOutputs), end(hashOutputs), back_inserter(data));
    } else {
        fill_n(back_inserter(data), 32, 0);
    }

    // Locktime
    encode32(lockTime, data);

    // Sighash type
    encode32(hashType, data);

    return data;
}

vector<uint8_t> TWBitcoinTransaction::getPrevoutHash() const {
    auto data = vector<uint8_t>{};
    for (auto& input : inputs) {
        auto& outpoint = reinterpret_cast<const TW::Bitcoin::OutPoint&>(input.previousOutput);
        outpoint.encode(data);
    }
    auto hash = TW::Hash::sha256(TW::Hash::sha256(data));
    return hash;
}

vector<uint8_t> TWBitcoinTransaction::getSequenceHash() const {
    auto data = vector<uint8_t>{};
    for (auto& input : inputs) {
        encode32(TWBitcoinTransactionInputSequence(&input), data);
    }
    auto hash = TW::Hash::sha256(TW::Hash::sha256(data));
    return hash;
}

vector<uint8_t> TWBitcoinTransaction::getOutputsHash() const {
    auto data = vector<uint8_t>{};
    for (auto& output : outputs) {
        output.encode(data);
    }
    auto hash = TW::Hash::sha256(TW::Hash::sha256(data));
    return hash;
}


void TWBitcoinTransaction::encode(bool witness, vector<uint8_t>& data) {
    encode32(version, data);
    
    if (witness) {
        // Use extended format in case witnesses are to be serialized.
        data.push_back(0);
        data.push_back(1);
    }

    TWWriteCompactSize(inputs.size(), data);
    for (auto& input : inputs) {
        input.encode(data);
    }

    TWWriteCompactSize(outputs.size(), data);
    for (auto& output : outputs) {
        output.encode(data);
    }

    if (witness) {
        for (auto& input : inputs) {
            input.encodeWitness(data);
        }
    }

    encode32(lockTime, data);
}

vector<uint8_t> TWBitcoinTransaction::getSignatureHash(const TWBitcoinScript& scriptCode, size_t index, uint32_t hashType, uint64_t amount, TWBitcoinSignatureVersion version) const {
    switch (version) {
    case BASE:
        return getSignatureHashBase(scriptCode, index, hashType);
    case WITNESS_V0:
        return getSignatureHashWitnessV0(scriptCode, index, hashType, amount);
    }
}

/// Generates the signature hash for Witness version 0 scripts.
vector<uint8_t> TWBitcoinTransaction::getSignatureHashWitnessV0(const TWBitcoinScript& scriptCode, size_t index, uint32_t hashType, uint64_t amount) const {
    auto preimage = getPreImage(scriptCode, index, hashType, amount);
    auto hash = TW::Hash::sha256(TW::Hash::sha256(preimage));
    return hash;
}

/// Generates the signature hash for for scripts other than witness scripts.
vector<uint8_t> TWBitcoinTransaction::getSignatureHashBase(const TWBitcoinScript& scriptCode, size_t index, uint32_t hashType) const {
    assert(index < inputs.size());

    auto data = vector<uint8_t>{};

    encode32(version, data);

    auto serializedInputCount = (hashType & TWSignatureHashTypeAnyoneCanPay) != 0 ? 1 : inputs.size();
    TWWriteCompactSize(serializedInputCount, data);
    for (auto subindex = 0; subindex < serializedInputCount; subindex += 1) {
        serializeInput(subindex, scriptCode, index, hashType, data);
    }

    auto hashNone = (hashType & 0x1f) == TWSignatureHashTypeNone;
    auto hashSingle = (hashType & 0x1f) == TWSignatureHashTypeSingle;
    auto serializedOutputCount = hashNone ? 0 : (hashSingle ? index+1 : outputs.size());
    TWWriteCompactSize(serializedOutputCount, data);
    for (auto subindex = 0; subindex < serializedOutputCount; subindex += 1) {
        if (hashSingle && subindex != index) {
            auto output = TWBitcoinTransactionOutput(-1, {});
            output.encode(data);
        } else {
            outputs[subindex].encode(data);
        }
    }

    // Locktime
    encode32(lockTime, data);

    // Sighash type
    encode32(hashType, data);

    auto hash = TW::Hash::sha256(TW::Hash::sha256(data));
    return hash;
}

void TWBitcoinTransaction::serializeInput(size_t subindex, const TWBitcoinScript& scriptCode, size_t index, uint32_t hashType, vector<uint8_t>& data) const {
    // In case of SIGHASH_ANYONECANPAY, only the input being signed is serialized
    if ((hashType & TWSignatureHashTypeAnyoneCanPay) != 0) {
        subindex = index;
    }

    reinterpret_cast<const TW::Bitcoin::OutPoint&>(inputs[subindex].previousOutput).encode(data);

    // Serialize the script
    if (subindex != index) {
        TWWriteCompactSize(0, data);
    } else {
        scriptCode.encode(data);
    }

    // Serialize the nSequence
    auto hashNone = (hashType & 0x1f) == TWSignatureHashTypeNone;
    auto hashSingle = (hashType & 0x1f) == TWSignatureHashTypeSingle;
    if (subindex != index && (hashSingle || hashNone)) {
        encode32(0, data);
    } else {
        encode32(inputs[subindex].sequence, data);
    }
}

TWBitcoinTransaction *TWBitcoinTransactionBuild(struct TWBech32Address address, uint64_t amount, uint64_t fee, struct TWBech32Address changeAddress, struct TWBitcoinUnspentTransaction *utxos[], size_t utxoCount) {
    uint64_t totalAmount = 0;
    for (auto i = 0; i < utxoCount; i += 1) {
        totalAmount += TWBitcoinUnspentTransactionAmount(utxos[i]);
    }
    auto change = totalAmount - amount - fee;

    auto lockingScriptTo = buildScript(address);
    if (lockingScriptTo == nullptr) {
        return nullptr;
    }

    auto transaction = TWBitcoinTransactionCreate(1, 0);
    TWBitcoinTransactionAddOutput(transaction, amount, lockingScriptTo);
    TWBitcoinScriptDelete(lockingScriptTo);

    if (change > 0) {
        auto lockingScriptChange = buildScript(changeAddress);
        if (lockingScriptChange == nullptr) {
            return nullptr;
        }
        TWBitcoinTransactionAddOutput(transaction, change, lockingScriptChange);
        TWBitcoinScriptDelete(lockingScriptChange);
    }

    for (auto i = 0; i < utxoCount; i += 1) {
        TWBitcoinTransactionAddInput(transaction, TWBitcoinUnspentTransactionOutPoint(utxos[i]), nullptr, UINT32_MAX);
    }
    
    return transaction;
}

TWBitcoinScript *buildScript(TWBech32Address address) {
    auto data = TWBech32AddressData(address);

    int ver;
    uint8_t prog[40];
    size_t prog_len;
    segwit_data(&ver, prog, &prog_len, TWDataBytes(data), TWDataSize(data));
    auto script = TWBitcoinScriptBuildPayToWitnessPubkeyHashRaw(prog);
    
    TWDataDelete(data);
    return script;
}
