// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWZcashTransaction.h>

#include "../Bitcoin/OutPoint.h"
#include "Transaction.h"

#include <TrustWalletCore/TWBitcoin.h>
#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWHash.h>

#include <vector>

using namespace TW::Bitcoin;

struct TWZcashTransaction *_Nonnull TWZcashTransactionCreate() {
    auto output = new TWZcashTransaction{ TW::Zcash::Transaction() };
    return output;
}

void TWZcashTransactionDelete(struct TWZcashTransaction *_Nonnull transaction) {
    delete transaction;
}

int32_t TWZcashTransactionVersion(struct TWZcashTransaction *_Nonnull transaction) {
    return transaction->impl.version;
}

uint32_t TWZcashTransactionLockTime(struct TWZcashTransaction *_Nonnull transaction) {
    return transaction->impl.lockTime;
}

size_t TWZcashTransactionInputCount(struct TWZcashTransaction *_Nonnull transaction) {
    return transaction->impl.inputs.size();
}

const TWBitcoinTransactionInput *_Nonnull TWZcashTransactionGetInput(struct TWZcashTransaction *_Nonnull transaction, size_t index) {
    return reinterpret_cast<const TWBitcoinTransactionInput *>(&transaction->impl.inputs[index]);
}

size_t TWZcashTransactionOutputCount(struct TWZcashTransaction *_Nonnull transaction) {
    return transaction->impl.outputs.size();
}

const TWBitcoinTransactionOutput *_Nonnull TWZcashTransactionGetOutput(struct TWZcashTransaction *_Nonnull transaction, size_t index) {
    return reinterpret_cast<const TWBitcoinTransactionOutput *>(&transaction->impl.outputs[index]);
}

void TWZcashTransactionAddOutput(struct TWZcashTransaction *_Nonnull transaction, uint64_t value, TWBitcoinScript *_Nonnull script) {
    transaction->impl.outputs.emplace_back(value, script->impl);
}

TWData *_Nonnull TWZcashTransactionEncode(struct TWZcashTransaction *_Nonnull transaction) {
    auto data = std::vector<uint8_t>{};
    transaction->impl.encode(data);
    return TWDataCreateWithBytes(data.data(), data.size());
}

TWData *_Nonnull TWZcashTransactionHash(struct TWZcashTransaction *_Nonnull transaction) {
    auto data = TWZcashTransactionEncode(transaction);
    auto result = TWHashBlake2b(data, 32);
    TWDataDelete(data);
    return result;
}


TWString *_Nonnull TWZcashTransactionIdentifier(struct TWZcashTransaction *_Nonnull transaction) {
    auto data = TWZcashTransactionEncode(transaction);
    auto hash = TWHashBlake2b(data, 32);
    TWDataDelete(data);
    TWDataReverse(hash);
    auto string = TWStringCreateWithHexData(hash);
    TWDataDelete(hash);
    return string;
}
