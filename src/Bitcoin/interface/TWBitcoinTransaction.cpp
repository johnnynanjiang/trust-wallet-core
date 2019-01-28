// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinTransaction.h>

#include "../OutPoint.h"
#include "../Transaction.h"

#include <TrustWalletCore/TWBitcoin.h>
#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWHash.h>

#include <vector>

using namespace TW::Bitcoin;

TWBitcoinScript *buildScript(TWBech32Address address);

struct TWBitcoinTransaction *_Nonnull TWBitcoinTransactionCreate(int version, uint32_t lockTime) {
    auto output = new TWBitcoinTransaction{ TW::Bitcoin::Transaction(static_cast<int32_t>(version), lockTime) };
    return output;
}

void TWBitcoinTransactionDelete(struct TWBitcoinTransaction *_Nonnull transaction) {
    delete transaction;
}

int32_t TWBitcoinTransactionVersion(struct TWBitcoinTransaction *_Nonnull transaction) {
    return transaction->impl.version;
}

uint32_t TWBitcoinTransactionLockTime(struct TWBitcoinTransaction *_Nonnull transaction) {
    return transaction->impl.lockTime;
}

size_t TWBitcoinTransactionInputCount(struct TWBitcoinTransaction *_Nonnull transaction) {
    return transaction->impl.inputs.size();
}

const TWBitcoinTransactionInput *_Nonnull TWBitcoinTransactionGetInput(struct TWBitcoinTransaction *_Nonnull transaction, size_t index) {
    return reinterpret_cast<const TWBitcoinTransactionInput *>(&transaction->impl.inputs[index]);
}

size_t TWBitcoinTransactionOutputCount(struct TWBitcoinTransaction *_Nonnull transaction) {
    return transaction->impl.outputs.size();
}

const TWBitcoinTransactionOutput *_Nonnull TWBitcoinTransactionGetOutput(struct TWBitcoinTransaction *_Nonnull transaction, size_t index) {
    return reinterpret_cast<const TWBitcoinTransactionOutput *>(&transaction->impl.outputs[index]);
}

void TWBitcoinTransactionAddOutput(struct TWBitcoinTransaction *_Nonnull transaction, uint64_t value, TWBitcoinScript *_Nonnull script) {
    transaction->impl.outputs.emplace_back(value, script->impl);
}

TWData *_Nonnull TWBitcoinTransactionEncode(struct TWBitcoinTransaction *_Nonnull transaction, bool witness) {
    auto data = std::vector<uint8_t>{};
    transaction->impl.encode(witness, data);
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
