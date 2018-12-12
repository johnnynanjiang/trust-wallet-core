// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinTransactionOutput.h>
#include <TrustWalletCore/TWBitcoinScript.h>

#include "TWBinaryCoding.h"

struct TWBitcoinTransactionOutput {
    /// Transaction amount.
    uint64_t value;

    /// Usually contains the public key as a Bitcoin script setting up conditions to claim this output.
    TWBitcoinScript *script;
};

TWBitcoinTransactionOutput *_Nonnull TWBitcoinTransactionOutputCreate(uint64_t value, TWBitcoinScript *_Nullable script) {
    auto output = new TWBitcoinTransactionOutput{
        .value = value,
    };
    if (script != nullptr) {
        output->script = TWBitcoinScriptCreateCopy(script);
    } else {
        output->script = TWBitcoinScriptCreate();
    }
    return output;
}

void TWBitcoinTransactionOutputDelete(struct TWBitcoinTransactionOutput *_Nonnull output) {
    TWBitcoinScriptDelete(output->script);
    delete output;
}

bool TWBitcoinTransactionOutputEqual(struct TWBitcoinTransactionOutput *_Nonnull lhs, struct TWBitcoinTransactionOutput *_Nonnull rhs) {
    return lhs->value == rhs->value && TWBitcoinScriptEqual(lhs->script, rhs->script);
}

uint64_t TWBitcoinTransactionOutputAmount(struct TWBitcoinTransactionOutput *_Nonnull output) {
    return output->value;
}

TWBitcoinScript *TWBitcoinTransactionOutputScript(struct TWBitcoinTransactionOutput *_Nonnull output) {
    return output->script;
}

TWData *_Nonnull TWBitcoinTransactionOutputEncode(struct TWBitcoinTransactionOutput *_Nonnull output) {
    auto data = TWDataCreateWithSize(0);
    TWBitcoinTransactionOutputEncodeRaw(output, data);
    return data;
}

void TWBitcoinTransactionOutputEncodeRaw(struct TWBitcoinTransactionOutput *_Nonnull output, TWData *_Nonnull data) {
    uint8_t valueBytes[8];
    encode64(output->value, valueBytes);
    TWDataAppendBytes(data, valueBytes, 8);

    TWBitcoinScriptEncodeRaw(output->script, data);
}
