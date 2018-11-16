// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef TW_PRIVATEKEY_H
#define TW_PRIVATEKEY_H

#include "TWBase.h"
#include "TWData.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_CLASS
struct TWPrivateKey;

static const size_t TWPrivateKeySize = 32;

TW_EXPORT_STATIC_METHOD
struct TWPrivateKey *_Nonnull TWPrivateKeyCreate(void);

TW_EXPORT_METHOD
void TWPrivateKeyDelete(struct TWPrivateKey *_Nonnull pk);

TW_EXPORT_STATIC_METHOD
struct TWPrivateKey *_Nullable TWPrivateKeyCreateWithData(const struct TWData *_Nonnull data);

TW_EXPORT_STATIC_METHOD
bool TWPrivateKeyIsValid(const struct TWData *_Nonnull data);

TW_EXPORT_METHOD
void TWPrivateKeyCopyBytes(struct TWPrivateKey *_Nonnull pk, uint8_t *_Nonnull output);

TW_EXTERN_C_END

#endif // TW_PRIVATEKEY_H
