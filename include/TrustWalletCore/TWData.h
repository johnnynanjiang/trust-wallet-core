// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef TW_DATA_H
#define TW_DATA_H

#include <stddef.h>

/// Defines a immutable block of data.
///
/// This gets translated to `Data` in Swift and `byte[]` in Java.
struct TWData {
    /// Pointer to the beginning of the data.
    const uint8_t *bytes;

    /// Number of bytes.
    size_t len;
};

/// Defines a immutable string.
///
/// This gets translated to `String` in both Swift and Java.
struct TWString {
    /// Pointer to the beginning of the UTF8 string bytes.
    const char *bytes;

    /// Number of bytes.
    size_t len;
};

#endif // TW_DATA_H
