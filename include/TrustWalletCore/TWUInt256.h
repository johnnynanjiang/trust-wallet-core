// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef TW_INT256_H
#define TW_INT256_H

#include "TWBase.h"
#include "TWData.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_CLASS
struct TWUInt256;

TW_EXPORT_STATIC_PROPERTY
struct TWUInt256 *_Nonnull TWUInt256Zero(void);

TW_EXPORT_STATIC_PROPERTY
struct TWUInt256 *_Nonnull TWUInt256One(void);

TW_EXPORT_STATIC_METHOD
struct TWUInt256 *_Nullable TWUInt256CreateWithData(struct TWData data);

TW_EXPORT_STATIC_METHOD
struct TWUInt256 *_Nonnull TWUInt256CreateWithUInt32(uint32_t number);

TW_EXPORT_STATIC_METHOD
struct TWUInt256 *_Nonnull TWUInt256CreateWithUInt64(uint64_t number);

TW_EXPORT_METHOD
void TWUInt256Delete(struct TWUInt256 *_Nonnull handle);

TW_EXPORT_PROPERTY
bool TWUInt256IsZero(struct TWUInt256 *_Nonnull);

TW_EXPORT_PROPERTY
uint32_t TWUInt256UInt32Value(struct TWUInt256 *_Nonnull);

TW_EXPORT_PROPERTY
uint64_t TWUInt256UInt64Value(struct TWUInt256 *_Nonnull);

TW_EXPORT_METHOD
void TWUInt256CopyData(struct TWUInt256 *_Nonnull, uint8_t *_Nonnull data);

TW_EXPORT_STATIC_METHOD
bool TWUInt256Equal(struct TWUInt256 *_Nonnull, struct TWUInt256 *_Nonnull);

TW_EXPORT_STATIC_METHOD
bool TWUInt256Less(struct TWUInt256 *_Nonnull, struct TWUInt256 *_Nonnull);

TW_EXPORT_METHOD
size_t TWUInt256Format(struct TWUInt256 *_Nonnull, int decimals, int exponent, char *_Nonnull output, size_t outlen);

TW_EXTERN_C_END

#endif // TW_INT256_H
