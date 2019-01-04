// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"
#include "TWString.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_CLASS
struct TWUInt256;

TW_EXPORT_STATIC_PROPERTY
struct TWUInt256 *_Nonnull TWUInt256Zero(void);

TW_EXPORT_STATIC_PROPERTY
struct TWUInt256 *_Nonnull TWUInt256One(void);

TW_EXPORT_STATIC_METHOD
struct TWUInt256 *_Nullable TWUInt256CreateWithData(TWData *_Nonnull data);

TW_EXPORT_STATIC_METHOD
struct TWUInt256 *_Nonnull TWUInt256CreateWithUInt32(uint32_t);

TW_EXPORT_STATIC_METHOD
struct TWUInt256 *_Nonnull TWUInt256CreateWithUInt64(uint64_t);

TW_EXPORT_METHOD
void TWUInt256Delete(struct TWUInt256 *_Nonnull value);

TW_EXPORT_PROPERTY
bool TWUInt256IsZero(struct TWUInt256 *_Nonnull value);

TW_EXPORT_PROPERTY
uint32_t TWUInt256UInt32Value(struct TWUInt256 *_Nonnull value);

TW_EXPORT_PROPERTY
uint64_t TWUInt256UInt64Value(struct TWUInt256 *_Nonnull value);

TW_EXPORT_PROPERTY
TWData *_Nonnull TWUInt256Data(struct TWUInt256 *_Nonnull value);

TW_EXPORT_STATIC_METHOD
bool TWUInt256Equal(struct TWUInt256 *_Nonnull lhs, struct TWUInt256 *_Nonnull rhs);

TW_EXPORT_STATIC_METHOD
bool TWUInt256Less(struct TWUInt256 *_Nonnull lhs, struct TWUInt256 *_Nonnull rhs);

TW_EXPORT_METHOD
TWString *_Nonnull TWUInt256Format(struct TWUInt256 *_Nonnull, int decimals, int exponent);

TW_EXTERN_C_END
