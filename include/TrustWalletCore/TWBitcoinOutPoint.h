// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"
#include "TWPublicKey.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_STRUCT
struct TWBitcoinOutPoint {
    /// The hash of the referenced transaction.
    uint8_t hash[32];

    /// The index of the specific output in the transaction. The first output is 0, etc.
    uint32_t index;
};

/// Initializes an out-point with a hash and an index.
TW_EXPORT_STATIC_METHOD
bool TWBitcoinOutPointInitWithHash(struct TWBitcoinOutPoint *_Nonnull outPoint, TWData *_Nonnull hash, uint32_t index);

/// Compares two out-points for equality.
TW_EXPORT_STATIC_METHOD
bool TWBitcoinOutPointEqual(struct TWBitcoinOutPoint lhs, struct TWBitcoinOutPoint rhs);

/// Out-point's hash.
TW_EXPORT_PROPERTY
TWData *_Nonnull TWBitcoinOutPointHash(struct TWBitcoinOutPoint outPoint);

/// Out-point's index.
TW_EXPORT_PROPERTY
uint32_t TWBitcoinOutPointIndex(struct TWBitcoinOutPoint outPoint);

/// Encodes the out-point.
TW_EXPORT_METHOD
TWData *_Nonnull TWBitcoinOutPointEncode(struct TWBitcoinOutPoint outPoint);

TW_EXTERN_C_END
