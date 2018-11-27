// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef TW_DATA_H
#define TW_DATA_H

#include "TWBase.h"
#include "TWString.h"

TW_EXTERN_C_BEGIN

struct TWString;

/// Defines a immutable block of data.
///
/// This gets translated to `Data` in Swift and `byte[]` in Java.
struct TWData {
    /// Pointer to the beginning of the data.
    const uint8_t *bytes;

    /// Number of bytes.
    size_t len;
};

/// Creates a block of data from a hexadecimal string.
struct TWData TWDataCreateWithHexString(struct TWString hex);

/// Deletes a block of data created with a `TWDataCreate*` method.
void TWDataDelete(struct TWData data);

TW_EXTERN_C_END

#endif // TW_DATA_H
