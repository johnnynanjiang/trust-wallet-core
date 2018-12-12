// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinUnspentTransaction.h>
#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWBitcoinTransactionOutput.h>

#include "TWBinaryCoding.h"

struct TWBitcoinUnspentTransaction {
    /// Transaction out point.
    TWBitcoinOutPoint outPoint;

    /// Script setting up conditions to claim this output.
    TWBitcoinScript *script;

    /// Output amount.
    uint64_t amount;
};

struct TWBitcoinUnspentTransaction *_Nonnull TWBitcoinUnspentTransactionCreateWithOutput(struct TWBitcoinOutPoint outPoint, struct TWBitcoinTransactionOutput *_Nonnull output) {
    auto utxo = new TWBitcoinUnspentTransaction{
        .outPoint = outPoint,
        .script = TWBitcoinScriptCreateCopy(TWBitcoinTransactionOutputScript(output)),
        .amount = TWBitcoinTransactionOutputAmount(output)
    };
    return utxo;
}

struct TWBitcoinUnspentTransaction *_Nonnull TWBitcoinUnspentTransactionCreate(TWData *_Nonnull hash, uint32_t index, struct TWBitcoinScript *_Nonnull script, uint64_t amount) {
    auto utxo = new TWBitcoinUnspentTransaction{
        .outPoint = TWBitcoinOutPoint{},
        .script = TWBitcoinScriptCreateCopy(script),
        .amount = amount
    };
    TWBitcoinOutPointInitWithHash(&utxo->outPoint, hash, index);
    return utxo;
}

void TWBitcoinUnspentTransactionDelete(struct TWBitcoinUnspentTransaction *_Nonnull utxo) {
    TWBitcoinScriptDelete(utxo->script);
    delete utxo;
}

struct TWBitcoinOutPoint TWBitcoinUnspentTransactionOutPoint(struct TWBitcoinUnspentTransaction *_Nonnull utxo) {
    return utxo->outPoint;
}

struct TWBitcoinTransactionOutput *_Nonnull TWBitcoinUnspentTransactionOutput(struct TWBitcoinUnspentTransaction *_Nonnull utxo) {
    return TWBitcoinTransactionOutputCreate(utxo->amount, utxo->script);
}

uint64_t TWBitcoinUnspentTransactionAmount(struct TWBitcoinUnspentTransaction *_Nonnull utxo) {
    return utxo->amount;
}
