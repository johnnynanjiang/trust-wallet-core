// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinTransactionOutput.h>

#include "../TransactionOutput.h"

using namespace TW::Bitcoin;

TWBitcoinTransactionOutput *_Nonnull TWBitcoinTransactionOutputCreate(uint64_t value, TWBitcoinScript *_Nullable script) {
    auto output = new TWBitcoinTransactionOutput{ TransactionOutput(value, script ? script->impl : Script()) };
    return output;
}

void TWBitcoinTransactionOutputDelete(struct TWBitcoinTransactionOutput *_Nonnull output) {
    delete output;
}

bool TWBitcoinTransactionOutputEqual(const struct TWBitcoinTransactionOutput *_Nonnull lhs, const struct TWBitcoinTransactionOutput *_Nonnull rhs) {
    return lhs->impl.value == rhs->impl.value && lhs->impl.script == rhs->impl.script;
}

uint64_t TWBitcoinTransactionOutputAmount(const struct TWBitcoinTransactionOutput *_Nonnull output) {
    return output->impl.value;
}

const TWBitcoinScript *TWBitcoinTransactionOutputScript(const struct TWBitcoinTransactionOutput *_Nonnull output) {
    return reinterpret_cast<const TWBitcoinScript *>(&output->impl.script);
}

TWData *_Nonnull TWBitcoinTransactionOutputEncode(const struct TWBitcoinTransactionOutput *_Nonnull output) {
    auto data = std::vector<uint8_t>{};
    output->impl.encode(data);
    return TWDataCreateWithBytes(data.data(), data.size());
}
