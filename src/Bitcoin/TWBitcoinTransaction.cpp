// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinTransaction.h>
#include <TrustWalletCore/TWHash.h>
#include <TrustWalletCore/TWString.h>
#include <vector>

#include "TWBinaryCoding.h"

template <typename T>
using unique = std::unique_ptr<T, void (*)(T*)>;

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
