// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"

TW_EXTERN_C_BEGIN

struct TWBitcoinScript;

TW_EXPORT_CLASS
struct TWBitcoinTransactionOutput;

/// Creates a transaction output with a value and a script.
TW_EXPORT_STATIC_METHOD
struct TWBitcoinTransactionOutput *_Nonnull TWBitcoinTransactionOutputCreate(uint64_t value, struct TWBitcoinScript *_Nullable script);

TW_EXPORT_METHOD
void TWBitcoinTransactionOutputDelete(struct TWBitcoinTransactionOutput *_Nonnull output);

/// Compares two outputs for equality.
TW_EXPORT_STATIC_METHOD
bool TWBitcoinTransactionOutputEqual(struct TWBitcoinTransactionOutput *_Nonnull lhs, struct TWBitcoinTransactionOutput *_Nonnull rhs);

/// Output amount.
TW_EXPORT_PROPERTY
uint64_t TWBitcoinTransactionOutputAmount(struct TWBitcoinTransactionOutput *_Nonnull output);

/// Script with the conditions to get this output.
TW_EXPORT_PROPERTY
struct TWBitcoinScript *_Nonnull TWBitcoinTransactionOutputScript(struct TWBitcoinTransactionOutput *_Nonnull output);

/// Encodes the output.
TW_EXPORT_METHOD
TWData *_Nonnull TWBitcoinTransactionOutputEncode(struct TWBitcoinTransactionOutput *_Nonnull output);

/// Encodes the output into the provided buffer.
void TWBitcoinTransactionOutputEncodeRaw(struct TWBitcoinTransactionOutput *_Nonnull output, TWData *_Nonnull data);

TW_EXTERN_C_END
