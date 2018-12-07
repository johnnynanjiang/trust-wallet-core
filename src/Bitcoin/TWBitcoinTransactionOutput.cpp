// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinTransactionOutput.h>

#include "TWBinaryCoding.h"

struct TWBitcoinTransactionOutput {
    /// Transaction amount.
    uint64_t value;

    /// Usually contains the public key as a Bitcoin script setting up conditions to claim this output.
    TWBitcoinScript *script;
};

TWBitcoinTransactionOutput *_Nonnull TWBitcoinTransactionOutputCreate(uint64_t value, TWBitcoinScript *_Nonnull script) {
    auto output = new TWBitcoinTransactionOutput{
        .value = value,
        .script = TWBitcoinScriptCreateCopy(script)
    };
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
    uint8_t valueBytes[8];
    encode64(output->value, valueBytes);
    auto data = TWDataCreateWithBytes(valueBytes, 8);

    auto scriptData = TWBitcoinScriptEncode(output->script);
    TWDataAppendData(data, scriptData);
    TWDataDelete(scriptData);

    return data;
}
