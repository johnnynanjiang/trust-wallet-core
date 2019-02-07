// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"
#include "TWZcashTAddress.h"
#include "TWBitcoin.h"

TW_EXTERN_C_BEGIN

struct TWBitcoinTransactionInput;
struct TWBitcoinTransactionOutput;

TW_EXPORT_CLASS
struct TWZcashTransaction;

/// Creates a transaction with a version and a lock time.
TW_EXPORT_STATIC_METHOD
struct TWZcashTransaction *_Nonnull TWZcashTransactionCreate();

/// Deletes a transaction object.
TW_EXPORT_METHOD
void TWZcashTransactionDelete(struct TWZcashTransaction *_Nonnull transaction);

/// Transaction lock time.
TW_EXPORT_PROPERTY
uint32_t TWZcashTransactionLockTime(struct TWZcashTransaction *_Nonnull transaction);

/// Number of inputs to this transaction.
TW_EXPORT_PROPERTY
size_t TWZcashTransactionInputCount(struct TWZcashTransaction *_Nonnull transaction);

/// Number of outputs for this transaction.
TW_EXPORT_PROPERTY
size_t TWZcashTransactionOutputCount(struct TWZcashTransaction *_Nonnull transaction);

/// Encodes the transaction.
TW_EXPORT_METHOD
TWData *_Nonnull TWZcashTransactionEncode(struct TWZcashTransaction *_Nonnull transaction);

/// Transaction hash.
TW_EXPORT_PROPERTY
TWData *_Nonnull TWZcashTransactionHash(struct TWZcashTransaction *_Nonnull transaction);

/// Transaction identifier.
TW_EXPORT_PROPERTY
TWString *_Nonnull TWZcashTransactionIdentifier(struct TWZcashTransaction *_Nonnull transaction);

TW_EXTERN_C_END
