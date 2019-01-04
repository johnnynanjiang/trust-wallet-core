// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"

TW_EXTERN_C_BEGIN

struct TWBitcoinSigningProvider;

/// Helper class to sign Bitcoin transactions.
TW_EXPORT_CLASS
struct TWBitcoinTransactionSigner;

TW_EXPORT_STATIC_METHOD
struct TWBitcoinTransactionSigner *_Nonnull TWBitcoinTransactionSignerCreate(struct TWBitcoinSigningProvider *_Nonnull provider, struct TWBitcoinTransaction *_Nonnull transaction, uint32_t hashType);

TW_EXPORT_METHOD
void TWBitcoinTransactionSignerDelete(struct TWBitcoinTransactionSigner *_Nonnull signer);

/// Makes an unspent transaction available to the signer.
TW_EXPORT_METHOD
void TWBitcoinTransactionSignerAddUnspent(struct TWBitcoinTransactionSigner *_Nonnull signer, struct TWBitcoinOutPoint outPoint, struct TWBitcoinScript *_Nonnull script, uint64_t amount);

/// Signs the transaction.
TW_EXPORT_METHOD
struct TWBitcoinTransaction *_Nullable TWBitcoinTransactionSignerSign(struct TWBitcoinTransactionSigner *_Nonnull signer);

TW_EXTERN_C_END
