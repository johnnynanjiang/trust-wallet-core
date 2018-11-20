// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef TW_PRIVATEKEY_H
#define TW_PRIVATEKEY_H

#include "TWBase.h"
#include "TWData.h"
#include "TWPublicKey.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_CLASS
struct TWPrivateKey;

static const size_t TWPrivateKeySize = 32;

TW_EXPORT_STATIC_METHOD
struct TWPrivateKey *_Nonnull TWPrivateKeyCreate(void);

TW_EXPORT_METHOD
void TWPrivateKeyDelete(struct TWPrivateKey *_Nonnull pk);

TW_EXPORT_STATIC_METHOD
struct TWPrivateKey *_Nullable TWPrivateKeyCreateWithData(struct TWData data);

TW_EXPORT_STATIC_METHOD
bool TWPrivateKeyIsValid(struct TWData data);

TW_EXPORT_METHOD
void TWPrivateKeyCopyBytes(struct TWPrivateKey *_Nonnull pk, uint8_t *_Nonnull output);

/// Returns the public key associated with this pirvate key.
TW_EXPORT_METHOD
struct TWPublicKey TWPrivateKeyGetPublicKey(struct TWPrivateKey *_Nonnull pk, bool compressed);

/// Signs a digest using ECDSA secp256k1.
///
/// The output needs to have capacity for 65 bytes.
TW_EXPORT_METHOD
bool TWPrivateKeySign(struct TWPrivateKey *_Nonnull pk, struct TWData digest, uint8_t *_Nonnull output);

/// Signs a digest using ECDSA secp256k1. The result is encoded with DER.
///
/// The output needs to have capacity for up to 72 bytes. The actual output size is returned.
TW_EXPORT_METHOD
size_t TWPrivateKeySignAsDER(struct TWPrivateKey *_Nonnull pk, struct TWData digest, uint8_t *_Nonnull output);

TW_EXTERN_C_END

#endif // TW_PRIVATEKEY_H
