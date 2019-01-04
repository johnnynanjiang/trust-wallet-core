// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"

TW_EXTERN_C_BEGIN

struct TWBitcoinScript;
struct TWPrivateKey;

/// Provides private keys and redeem scripts necessary for singing transactions.
TW_EXPORT_CLASS
struct TWBitcoinSigningProvider;

TW_EXPORT_STATIC_METHOD
struct TWBitcoinSigningProvider *_Nonnull TWBitcoinSigningProviderCreate();

TW_EXPORT_METHOD
void TWBitcoinSigningProviderDelete(struct TWBitcoinSigningProvider *_Nonnull provider);

/// Adds a new private key.
TW_EXPORT_METHOD
void TWBitcoinSigningProviderAddKey(struct TWBitcoinSigningProvider *_Nonnull provider, struct TWPrivateKey *_Nonnull key);

/// Adds a new redeem script for the provided script hash.
TW_EXPORT_METHOD
void TWBitcoinSigningProviderAddRedeemScript(struct TWBitcoinSigningProvider *_Nonnull provider, TWData *_Nonnull hash, struct TWBitcoinScript *_Nonnull script);

TW_EXTERN_C_END
