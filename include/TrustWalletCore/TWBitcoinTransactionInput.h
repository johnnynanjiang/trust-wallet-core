// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"
#include "TWBitcoinOutPoint.h"
#include "TWBitcoinScript.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_CLASS
struct TWBitcoinTransactionInput;

/// Setting `sequence` to this value for every input in a transaction disables `lockTime`.
static uint32_t TWBitcoinSequenceFinal = 0xffffffff;

/// Creates a transaction output with a value and a script.
TW_EXPORT_STATIC_METHOD
struct TWBitcoinTransactionInput *_Nonnull TWBitcoinTransactionInputCreate(struct TWBitcoinOutPoint previousOutput, struct TWBitcoinScript *_Nonnull script, uint32_t sequence);

TW_EXPORT_METHOD
void TWBitcoinTransactionInputDelete(struct TWBitcoinTransactionInput *_Nonnull input);

/// Reference to previous output transaction.
TW_EXPORT_PROPERTY
struct TWBitcoinOutPoint TWBitcoinTransactionInputPreviousOutput(struct TWBitcoinTransactionInput *_Nonnull input);

/// Unlock script.
TW_EXPORT_PROPERTY
struct TWBitcoinScript *_Nonnull TWBitcoinTransactionInputScript(struct TWBitcoinTransactionInput *_Nonnull input);

/// Input sequence number.
TW_EXPORT_PROPERTY
uint32_t TWBitcoinTransactionInputSequence(struct TWBitcoinTransactionInput *_Nonnull input);

/// Encodes the input.
TW_EXPORT_METHOD
TWData *_Nonnull TWBitcoinTransactionInputEncode(struct TWBitcoinTransactionInput *_Nonnull input);

TW_EXTERN_C_END
