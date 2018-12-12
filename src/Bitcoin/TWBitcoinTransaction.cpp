// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinTransaction.h>
#include <TrustWalletCore/TWBitcoin.h>
#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWBitcoinTransactionInput.h>
#include <TrustWalletCore/TWBitcoinTransactionOutput.h>
#include <TrustWalletCore/TWBitcoinUnspentTransaction.h>
#include <TrustWalletCore/TWHash.h>

#include <TrezorCrypto/segwit_addr.h>
#include <vector>

#include "TWBinaryCoding.h"

template <typename T>
using unique = std::unique_ptr<T, void (*)(T*)>;

TWData *getSignatureHash(struct TWBitcoinTransaction *transaction, TWBitcoinScript *scriptCode, int index, uint32_t hashType, uint64_t amount, TWBitcoinSignatureVersion version);
/// Generates the signature hash for Witness version 0 scripts.
TWData *getSignatureHashWitnessV0(struct TWBitcoinTransaction *transaction, TWBitcoinScript *scriptCode, int index, uint32_t hashType, uint64_t amount);
/// Generates the signature hash for for scripts other than witness scripts.
TWData *getSignatureHashBase(struct TWBitcoinTransaction *transaction, TWBitcoinScript *scriptCode, int index, uint32_t hashType);
void serializeInput(struct TWBitcoinTransaction *transaction, int, TWBitcoinScript*, int, uint32_t, TWData*);
TWBitcoinScript *buildScript(TWBech32Address address);

struct TWBitcoinTransaction {
    /// Transaction data format version (note, this is signed)
    int32_t version;

    /// The block number or timestamp at which this transaction is unlocked
    ///
    ///     | Value          | Description
    ///     |----------------|------------
    ///     |  0             | Not locked
    ///     | < 500000000    | Block number at which this transaction is unlocked
    ///     | >= 500000000   | UNIX timestamp at which this transaction is unlocked
    ///
    /// If all inputs have final (`0xffffffff`) sequence numbers then `lockTime` is irrelevant. Otherwise, the
    /// transaction may not be added to a block until after `lockTime`.
    uint32_t lockTime;

    /// A list of 1 or more transaction inputs or sources for coins
    std::vector<unique<TWBitcoinTransactionInput>> inputs;

    /// A list of 1 or more transaction outputs or destinations for coins
    std::vector<unique<TWBitcoinTransactionOutput>> outputs;
};

struct TWBitcoinTransaction *_Nonnull TWBitcoinTransactionCreate(int32_t version, uint32_t lockTime) {
    auto output = new TWBitcoinTransaction{
        .version = version,
        .lockTime = lockTime
    };
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
    return transaction->inputs[index].get();
}

void TWBitcoinTransactionAddInput(struct TWBitcoinTransaction *_Nonnull transaction, struct TWBitcoinOutPoint previousOutput, struct TWBitcoinScript *script, uint32_t sequence) {
    TWBitcoinTransactionInput *input = TWBitcoinTransactionInputCreate(previousOutput, script, sequence);
    transaction->inputs.push_back(unique<TWBitcoinTransactionInput>(input, TWBitcoinTransactionInputDelete));
}

size_t TWBitcoinTransactionOutputCount(struct TWBitcoinTransaction *_Nonnull transaction) {
    return transaction->outputs.size();
}

struct TWBitcoinTransactionOutput *_Nonnull TWBitcoinTransactionGetOutput(struct TWBitcoinTransaction *_Nonnull transaction, size_t index) {
    return transaction->outputs[index].get();
}

void TWBitcoinTransactionAddOutput(struct TWBitcoinTransaction *_Nonnull transaction, uint64_t value, TWBitcoinScript *_Nonnull script) {
    auto output = TWBitcoinTransactionOutputCreate(value, script);
    transaction->outputs.push_back(unique<TWBitcoinTransactionOutput>(output, TWBitcoinTransactionOutputDelete));
}

TWData *_Nonnull TWBitcoinTransactionEncode(struct TWBitcoinTransaction *_Nonnull transaction, bool witness) {
    auto data = TWDataCreateWithSize(0);
    TWBitcoinTransactionEncodeRaw(transaction, witness, data);
    return data;
}

void TWBitcoinTransactionEncodeRaw(struct TWBitcoinTransaction *_Nonnull transaction, bool witness, TWData *_Nonnull data) {
    uint8_t versionData[4];
    encode32(transaction->version, versionData);
    TWDataAppendBytes(data, versionData, 4);

    if (witness) {
        // Use extended format in case witnesses are to be serialized.
        TWDataAppendByte(data, 0);
        TWDataAppendByte(data, 1);
    }

    TWWriteCompactSize(transaction->inputs.size(), data);
    for (auto& input : transaction->inputs) {
        TWBitcoinTransactionInputEncodeRaw(input.get(), data);
    }

    TWWriteCompactSize(transaction->outputs.size(), data);
    for (auto& output : transaction->outputs) {
        TWBitcoinTransactionOutputEncodeRaw(output.get(), data);
    }

    if (witness) {
        for (auto& input : transaction->inputs) {
            TWBitcoinTransactionInputEncodeWitness(input.get(), data);
        }
    }

    uint8_t lockTimeData[4];
    encode32(transaction->lockTime, lockTimeData);
    TWDataAppendBytes(data, lockTimeData, 4);
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

TWData *getPrevoutHash(struct TWBitcoinTransaction *_Nonnull transaction) {
    auto data = TWDataCreateWithSize(0);
    for (auto& input : transaction->inputs) {
        TWBitcoinOutPointEncodeRaw(TWBitcoinTransactionInputPreviousOutput(input.get()), data);
    }
    auto hash = TWHashSHA256SHA256(data);
    TWDataDelete(data);
    return hash;
}

TWData *getSequenceHash(struct TWBitcoinTransaction *_Nonnull transaction) {
    auto data = TWDataCreateWithSize(0);
    for (auto& input : transaction->inputs) {
        uint8_t sequenceData[4];
        encode32(TWBitcoinTransactionInputSequence(input.get()), sequenceData);
        TWDataAppendBytes(data, sequenceData, 4);
    }
    auto hash = TWHashSHA256SHA256(data);
    TWDataDelete(data);
    return hash;
}

TWData *getOutputsHash(struct TWBitcoinTransaction *_Nonnull transaction) {
    auto data = TWDataCreateWithSize(0);
    for (auto& output : transaction->outputs) {
        TWBitcoinTransactionOutputEncodeRaw(output.get(), data);
    }
    auto hash = TWHashSHA256SHA256(data);
    TWDataDelete(data);
    return hash;
}

TWData *getPreImage(struct TWBitcoinTransaction *transaction, TWBitcoinScript *scriptCode, int index, uint32_t hashType, uint64_t amount) {
    assert(index < transaction->inputs.size());

    auto data = TWDataCreateWithSize(0);

    uint8_t zeros[32];
    memset(zeros, 0, 32);

    // Version
    uint8_t versionData[4];
    encode32(transaction->version, versionData);
    TWDataAppendBytes(data, versionData, 4);

    // Input prevouts (none/all, depending on flags)
    if ((hashType & TWSignatureHashTypeAnyoneCanPay) == 0) {
        auto hashPrevouts = getPrevoutHash(transaction);
        TWDataAppendData(data, hashPrevouts);
        TWDataDelete(hashPrevouts);
    } else {
        TWDataAppendBytes(data, zeros, 32);
    }

    // Input nSequence (none/all, depending on flags)
    if ((hashType & TWSignatureHashTypeAnyoneCanPay) == 0 && !TWSignatureHashTypeIsSingle(hashType) && !TWSignatureHashTypeIsNone(hashType)) {
        auto hashSequence = getSequenceHash(transaction);
        TWDataAppendData(data, hashSequence);
        TWDataDelete(hashSequence);
    } else {
        TWDataAppendBytes(data, zeros, 32);
    }

    // The input being signed (replacing the scriptSig with scriptCode + amount)
    // The prevout may already be contained in hashPrevout, and the nSequence
    // may already be contain in hashSequence.
    TWBitcoinOutPointEncodeRaw(TWBitcoinTransactionInputPreviousOutput(transaction->inputs[index].get()), data);
    TWBitcoinScriptEncodeRaw(scriptCode, data);

    uint8_t amountData[8];
    encode64(amount, amountData);
    TWDataAppendBytes(data, amountData, 8);

    uint8_t sequenceData[4];
    encode32(TWBitcoinTransactionInputSequence(transaction->inputs[index].get()), sequenceData);
    TWDataAppendBytes(data, sequenceData, 4);

    // Outputs (none/one/all, depending on flags)
    if (!TWSignatureHashTypeIsSingle(hashType) && !TWSignatureHashTypeIsNone(hashType)) {
        auto hashOutputs = getOutputsHash(transaction);
        TWDataAppendData(data, hashOutputs);
        TWDataDelete(hashOutputs);
    } else if (TWSignatureHashTypeIsSingle(hashType) && index < transaction->outputs.size()) {
        auto data = TWBitcoinTransactionOutputEncode(transaction->outputs[index].get());
        auto hashOutputs = TWHashSHA256SHA256(data);
        TWDataDelete(data);
        TWDataAppendData(data, hashOutputs);
        TWDataDelete(hashOutputs);
    } else {
        TWDataAppendBytes(data, zeros, 32);
    }

    // Locktime
    uint8_t locktimeData[4];
    encode32(transaction->lockTime, locktimeData);
    TWDataAppendBytes(data, locktimeData, 4);

    // Sighash type
    uint8_t sigHashTypeData[4];
    encode32(hashType, sigHashTypeData);
    TWDataAppendBytes(data, sigHashTypeData, 4);

    return data;
}

TWData *_Nonnull TWBitcoinTransactionGetSignatureHash(struct TWBitcoinTransaction *_Nonnull transaction, TWBitcoinScript *_Nonnull scriptCode, size_t index, uint32_t hashType, uint64_t amount, TWBitcoinSignatureVersion version) {
    switch (version) {
    case BASE:
        return getSignatureHashBase(transaction, scriptCode, index, hashType);
    case WITNESS_V0:
        return getSignatureHashWitnessV0(transaction, scriptCode, index, hashType, amount);
    }
}

/// Generates the signature hash for Witness version 0 scripts.
TWData *getSignatureHashWitnessV0(struct TWBitcoinTransaction *transaction, TWBitcoinScript *scriptCode, int index, uint32_t hashType, uint64_t amount) {
    auto preimage = getPreImage(transaction, scriptCode, index, hashType, amount);
    auto hash = TWHashSHA256SHA256(preimage);
    TWDataDelete(preimage);
    return hash;
}

/// Generates the signature hash for for scripts other than witness scripts.
TWData *getSignatureHashBase(struct TWBitcoinTransaction *transaction, TWBitcoinScript *scriptCode, int index, uint32_t hashType) {
    assert(index < transaction->inputs.size());

    auto data = TWDataCreateWithSize(0);

    uint8_t versionData[4];
    encode32(transaction->version, versionData);
    TWDataAppendBytes(data, versionData, 4);

    auto serializedInputCount = (hashType & TWSignatureHashTypeAnyoneCanPay) != 0 ? 1 : transaction->inputs.size();
    TWWriteCompactSize(serializedInputCount, data);
    for (auto subindex = 0; subindex < serializedInputCount; subindex += 1) {
        serializeInput(transaction, subindex, scriptCode, index, hashType, data);
    }

    auto containsNone = (hashType & TWSignatureHashTypeNone) != 0;
    auto containsSingle = (hashType & TWSignatureHashTypeSingle) != 0;
    auto serializedOutputCount = containsNone ? 0 : (containsSingle ? index+1 : transaction->outputs.size());
    TWWriteCompactSize(serializedOutputCount, data);
    for (auto subindex = 0; subindex < serializedOutputCount; subindex += 1) {
        if (containsSingle && subindex != index) {
            auto output = TWBitcoinTransactionOutputCreate(-1, nullptr);
            TWBitcoinTransactionOutputEncodeRaw(output, data);
        } else {
            TWBitcoinTransactionOutputEncodeRaw(transaction->outputs[index].get(), data);
        }
    }

    // Locktime
    uint8_t locktimeData[4];
    encode32(transaction->lockTime, locktimeData);
    TWDataAppendBytes(data, locktimeData, 4);

    // Sighash type
    uint8_t sigHashTypeData[4];
    encode32(hashType, sigHashTypeData);
    TWDataAppendBytes(data, sigHashTypeData, 4);

    auto hash = TWHashSHA256SHA256(data);
    TWDataDelete(data);
    return hash;
}

void serializeInput(struct TWBitcoinTransaction *transaction, int subindex, TWBitcoinScript *scriptCode, int index, uint32_t hashType, TWData *data) {
    // In case of SIGHASH_ANYONECANPAY, only the input being signed is serialized
    if ((hashType & TWSignatureHashTypeAnyoneCanPay) != 0) {
        subindex = index;
    }

    TWBitcoinOutPointEncodeRaw(TWBitcoinTransactionInputPreviousOutput(transaction->inputs[index].get()), data);

    // Serialize the script
    if (subindex != index) {
        TWWriteCompactSize(0, data);
    } else {
        TWBitcoinScriptEncodeRaw(scriptCode, data);
    }

    // Serialize the nSequence
    uint8_t sequenceData[4];
    auto containsNone = (hashType & TWSignatureHashTypeNone) != 0;
    auto containsSingle = (hashType & TWSignatureHashTypeSingle) != 0;
    if (subindex != index && (containsSingle || containsNone)) {
        encode32(0, sequenceData);
    } else {
        encode32(TWBitcoinTransactionInputSequence(transaction->inputs[subindex].get()), sequenceData);
    }
    TWDataAppendBytes(data, sequenceData, 4);
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
