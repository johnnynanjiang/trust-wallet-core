// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef TW_PUBLICKEY_H
#define TW_PUBLICKEY_H

#include "TWBase.h"
#include "TWData.h"

TW_EXTERN_C_BEGIN

static const size_t TWPublicKeyCompressedSize = 33;
static const size_t TWPublicKeyUncompressedSize = 65;

TW_EXPORT_STRUCT
struct TWPublicKey {
    uint8_t bytes[TWPublicKeyUncompressedSize];
};

TW_EXPORT_STATIC_METHOD
bool TWPublicKeyInitWithData(struct TWPublicKey *_Nonnull pk, struct TWData data);

TW_EXPORT_STATIC_METHOD
bool TWPublicKeyIsValid(struct TWData data);

TW_EXPORT_PROPERTY
bool TWPublicKeyIsCompressed(struct TWPublicKey pk);

TW_EXPORT_PROPERTY
struct TWPublicKey TWPublicKeyCompressed(struct TWPublicKey from);

TW_EXPORT_PROPERTY
size_t TWPublicKeyData(struct TWPublicKey pk, uint8_t result[_Nonnull TWPublicKeyUncompressedSize]);

TW_EXTERN_C_END

#endif // TW_PUBLICKEY_H
