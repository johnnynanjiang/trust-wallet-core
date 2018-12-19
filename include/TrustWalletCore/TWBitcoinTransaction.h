// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"
#include "TWBech32Address.h"
#include "TWBitcoin.h"
#include "TWBitcoinOutPoint.h"

TW_EXTERN_C_BEGIN

struct TWBitcoinTransactionInput;
struct TWBitcoinTransactionOutput;
struct TWBitcoinUnspentTransaction;

TW_EXPORT_CLASS
struct TWBitcoinTransaction;

/// Creates a transaction with a version and a lock time.
TW_EXPORT_STATIC_METHOD
struct TWBitcoinTransaction *_Nonnull TWBitcoinTransactionCreate(int version, uint32_t lockTime);

/// Deletes a transaction object.
TW_EXPORT_METHOD
void TWBitcoinTransactionDelete(struct TWBitcoinTransaction *_Nonnull transaction);

/// Transaction lock time.
TW_EXPORT_PROPERTY
uint32_t TWBitcoinTransactionLockTime(struct TWBitcoinTransaction *_Nonnull transaction);

/// Number of inputs to this transaction.
TW_EXPORT_PROPERTY
size_t TWBitcoinTransactionInputCount(struct TWBitcoinTransaction *_Nonnull transaction);

/// Returns the input at the specified index.
TW_EXPORT_METHOD
struct TWBitcoinTransactionInput *_Nonnull TWBitcoinTransactionGetInput(struct TWBitcoinTransaction *_Nonnull transaction, size_t index);

/// Appends an input.
TW_EXPORT_METHOD
void TWBitcoinTransactionAddInput(struct TWBitcoinTransaction *_Nonnull transaction, struct TWBitcoinOutPoint previousOutput, struct TWBitcoinScript *_Nullable script, uint32_t sequence);

/// Number of outputs for this transaction.
TW_EXPORT_PROPERTY
size_t TWBitcoinTransactionOutputCount(struct TWBitcoinTransaction *_Nonnull transaction);

/// Returns the output at the specified index.
TW_EXPORT_METHOD
struct TWBitcoinTransactionOutput *_Nonnull TWBitcoinTransactionGetOutput(struct TWBitcoinTransaction *_Nonnull transaction, size_t index);

/// Appends an output.
TW_EXPORT_METHOD
void TWBitcoinTransactionAddOutput(struct TWBitcoinTransaction *_Nonnull transaction, uint64_t value, struct TWBitcoinScript *_Nonnull script);

/// Encodes the transaction.
TW_EXPORT_METHOD
TWData *_Nonnull TWBitcoinTransactionEncode(struct TWBitcoinTransaction *_Nonnull transaction, bool witness);

/// Transaction hash.
TW_EXPORT_PROPERTY
TWData *_Nonnull TWBitcoinTransactionHash(struct TWBitcoinTransaction *_Nonnull transaction);

/// Transaction wtiness hash.
TW_EXPORT_PROPERTY
TWData *_Nonnull TWBitcoinTransactionWitnessHash(struct TWBitcoinTransaction *_Nonnull transaction);

/// Transaction identifier.
TW_EXPORT_PROPERTY
TWString *_Nonnull TWBitcoinTransactionIdentifier(struct TWBitcoinTransaction *_Nonnull transaction);

/// Transaction witness identifier.
TW_EXPORT_PROPERTY
TWString *_Nonnull TWBitcoinTransactionWitnessIdentifier(struct TWBitcoinTransaction *_Nonnull transaction);

/// Builds a transaction.
struct TWBitcoinTransaction *_Nullable TWBitcoinTransactionBuild(struct TWBech32Address address, uint64_t amount, uint64_t fee, struct TWBech32Address changeAddress, struct TWBitcoinUnspentTransaction *_Nonnull utxos[_Nonnull], size_t utxoCount);

/// Returns the transaction hash used for signing.
TWData *_Nonnull TWBitcoinTransactionGetSignatureHash(const struct TWBitcoinTransaction *_Nonnull transaction, const struct TWBitcoinScript *_Nonnull scriptCode, size_t index, uint32_t hashType, uint64_t amount, enum TWBitcoinSignatureVersion version);

TW_EXTERN_C_END
