// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef TW_STRING_H
#define TW_STRING_H

#include "TWBase.h"
#include "TWData.h"

TW_EXTERN_C_BEGIN

struct TWData;

/// Defines a immutable string.
///
/// This gets translated to `String` in both Swift and Java.
struct TWString {
    /// Pointer to the beginning of the UTF8 string bytes.
    const char *bytes;

    /// Number of bytes.
    size_t len;
};

/// Creates a hexadecimal string from a block of data.
struct TWString TWStringCreateWithHexData(struct TWData data);

/// Deletes a string created with a `TWStringCreate*` method.
void TWStringDelete(struct TWString string);

TW_EXTERN_C_END

#endif // TW_STRING_H
