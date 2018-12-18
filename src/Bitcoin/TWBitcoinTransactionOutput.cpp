// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinTransactionOutput.h>
#include <TrustWalletCore/TWBitcoinScript.h>

#include "TWBinaryCoding.h"

TWBitcoinTransactionOutput *_Nonnull TWBitcoinTransactionOutputCreate(uint64_t value, TWBitcoinScript *_Nullable script) {
    auto output = new TWBitcoinTransactionOutput(value, script ? *script : TWBitcoinScript());
    return output;
}

void TWBitcoinTransactionOutputDelete(struct TWBitcoinTransactionOutput *_Nonnull output) {
    delete output;
}

bool TWBitcoinTransactionOutputEqual(const struct TWBitcoinTransactionOutput *_Nonnull lhs, const struct TWBitcoinTransactionOutput *_Nonnull rhs) {
    return lhs->value == rhs->value && lhs->script == rhs->script;
}

uint64_t TWBitcoinTransactionOutputAmount(const struct TWBitcoinTransactionOutput *_Nonnull output) {
    return output->value;
}

const TWBitcoinScript *TWBitcoinTransactionOutputScript(const struct TWBitcoinTransactionOutput *_Nonnull output) {
    return &output->script;
}

TWData *_Nonnull TWBitcoinTransactionOutputEncode(const struct TWBitcoinTransactionOutput *_Nonnull output) {
    auto data = std::vector<uint8_t>{};
    output->encode(data);
    return TWDataCreateWithBytes(data.data(), data.size());
}

void TWBitcoinTransactionOutput::encode(std::vector<uint8_t>& data) const {
    encode64(value, data);
    script.encode(data);
}
