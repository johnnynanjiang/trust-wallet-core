// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef TRUST_STELLAR_CONSTANTS_H
#define TRUST_STELLAR_CONSTANTS_H

#include <stdint.h>

namespace stellar {
    const uint32_t VERSION_ACCOUNT_ID = 6 << 3;
    const uint32_t VERSION_SEED = 18 << 3;
    const uint32_t VERSION_SHA256_HASH = 23 << 3;

    const uint32_t SIZE_VERSION = 1;
    const uint32_t SIZE_PAYLOAD = 32;
    const uint32_t SIZE_CHECKSUM = 2;
    const uint32_t SIZE_ENCODED_PUBLIC_KEY = 35;
}

#endif