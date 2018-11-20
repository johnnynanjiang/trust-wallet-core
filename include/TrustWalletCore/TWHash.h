// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef TW_HASH_H
#define TW_HASH_H

#include "TWBase.h"
#include "TWData.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_CLASS
struct TWPrivateKey;

static const size_t TWHashSHA1Length = 20;
static const size_t TWHashSHA256Length = 32;
static const size_t TWHashSHA512Length = 64;
static const size_t TWHashRipemdLength = 20;

/// Computes the SHA1 of a block of data.
TW_EXPORT_STATIC_METHOD
void TWHashSHA1(struct TWData data, uint8_t[_Nonnull TWHashSHA1Length]);

TW_EXPORT_STATIC_METHOD
void TWHashSHA256(struct TWData data, uint8_t[_Nonnull TWHashSHA256Length]);

TW_EXPORT_STATIC_METHOD
void TWHashSHA512(struct TWData data, uint8_t[_Nonnull TWHashSHA512Length]);

TW_EXPORT_STATIC_METHOD
void TWHashKeccak256(struct TWData data, uint8_t *_Nonnull);

TW_EXPORT_STATIC_METHOD
void TWHashKeccak512(struct TWData data, uint8_t *_Nonnull);

TW_EXPORT_STATIC_METHOD
void TWHashSHA3_256(struct TWData data, uint8_t *_Nonnull);

TW_EXPORT_STATIC_METHOD
void TWHashSHA3_512(struct TWData data, uint8_t *_Nonnull);

TW_EXPORT_STATIC_METHOD
void TWHashRIPEMD(struct TWData data, uint8_t[_Nonnull TWHashRipemdLength]);

TW_EXPORT_STATIC_METHOD
void TWHashBlake2b(struct TWData data, uint8_t *_Nonnull, size_t);

TW_EXTERN_C_END

#endif // TW_HASH_H
