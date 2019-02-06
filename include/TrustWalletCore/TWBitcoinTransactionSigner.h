// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"
#include "TWProto.h"

TW_EXTERN_C_BEGIN

/// Helper class to sign Bitcoin transactions.
TW_EXPORT_CLASS
struct TWBitcoinTransactionSigner;

/// Creates a transaction signer with input data (serialized from BitcoinSigningInput)
TW_EXPORT_STATIC_METHOD
struct TWBitcoinTransactionSigner *_Nonnull TWBitcoinTransactionSignerCreate(ProtoBitcoinSigningInput input);

TW_EXPORT_METHOD
void TWBitcoinTransactionSignerDelete(struct TWBitcoinTransactionSigner *_Nonnull signer);

/// Signs the transaction.
///
/// On success the result will contain a BitcoinSigningOutput.
TW_EXPORT_METHOD
ProtoResult TWBitcoinTransactionSignerSign(struct TWBitcoinTransactionSigner *_Nonnull signer);

TW_EXTERN_C_END
