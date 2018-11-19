// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef TW_DATA_H
#define TW_DATA_H

#include <stddef.h>

/// Defines a block of data.
///
/// This gets translated to `Data` in Swift and `byte[]` in Java.
struct TWData {
    const uint8_t *bytes;
    size_t len;
};

#endif // TW_DATA_H
