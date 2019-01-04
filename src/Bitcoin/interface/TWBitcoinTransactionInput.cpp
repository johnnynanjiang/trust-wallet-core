// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinTransactionInput.h>

#include "../OutPoint.h"
#include "../TransactionInput.h"

using namespace TW::Bitcoin;

struct TWBitcoinTransactionInput *_Nonnull TWBitcoinTransactionInputCreate(struct TWBitcoinOutPoint previousOutput, struct TWBitcoinScript *_Nullable script, uint32_t sequence) {
    auto prevOut = reinterpret_cast<OutPoint&>(previousOutput);
    auto inputImpl = TransactionInput(prevOut, script ? script->impl : Script(), sequence);
    return new TWBitcoinTransactionInput{ inputImpl };
}

void TWBitcoinTransactionInputDelete(struct TWBitcoinTransactionInput *_Nonnull input) {
    delete input;
}

struct TWBitcoinOutPoint TWBitcoinTransactionInputPreviousOutput(const struct TWBitcoinTransactionInput *_Nonnull input) {
    return reinterpret_cast<const TWBitcoinOutPoint&>(input->impl.previousOutput);
}

const struct TWBitcoinScript *TWBitcoinTransactionInputScript(const struct TWBitcoinTransactionInput *_Nonnull input) {
    return reinterpret_cast<const struct TWBitcoinScript *>(&input->impl.script);
}

uint32_t TWBitcoinTransactionInputSequence(const struct TWBitcoinTransactionInput *_Nonnull input) {
    return input->impl.sequence;
}

TWData *_Nonnull TWBitcoinTransactionInputEncode(const struct TWBitcoinTransactionInput *_Nonnull input) {
    auto data = std::vector<uint8_t>{};
    input->impl.encode(data);
    return TWDataCreateWithBytes(data.data(), data.size());
}
