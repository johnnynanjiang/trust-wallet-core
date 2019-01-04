// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"
#include "TWBitcoinOutPoint.h"

TW_EXTERN_C_BEGIN

struct TWBitcoinScript;
struct TWBitcoinTransactionOutput;

TW_EXPORT_CLASS
struct TWBitcoinUnspentTransaction;

TW_EXPORT_STATIC_METHOD
struct TWBitcoinUnspentTransaction *_Nonnull TWBitcoinUnspentTransactionCreateWithOutput(struct TWBitcoinOutPoint outpoint, struct TWBitcoinTransactionOutput *_Nonnull output);

TW_EXPORT_STATIC_METHOD
struct TWBitcoinUnspentTransaction *_Nonnull TWBitcoinUnspentTransactionCreate(TWData *_Nonnull hash, uint32_t index, struct TWBitcoinScript *_Nonnull script, uint64_t amount);

TW_EXPORT_METHOD
void TWBitcoinUnspentTransactionDelete(struct TWBitcoinUnspentTransaction *_Nonnull utxo);

TW_EXPORT_PROPERTY
struct TWBitcoinOutPoint TWBitcoinUnspentTransactionOutPoint(struct TWBitcoinUnspentTransaction *_Nonnull utxo);

TW_EXPORT_PROPERTY
struct TWBitcoinTransactionOutput *_Nonnull TWBitcoinUnspentTransactionOutput(struct TWBitcoinUnspentTransaction *_Nonnull utxo);

TW_EXPORT_PROPERTY
uint64_t TWBitcoinUnspentTransactionAmount(struct TWBitcoinUnspentTransaction *_Nonnull utxo);

TW_EXTERN_C_END
