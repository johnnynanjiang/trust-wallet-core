// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWData.h>

#include <string.h>

static inline uint8_t value(uint8_t c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;

    // Invalid digit
    return 0;
 }

struct TWData TWDataCreateWithHexString(struct TWString hex) {
    const char *ptr = hex.bytes;
    if (hex.len >= 2 && ptr[0] == '0' && ptr[1] == 'x') {
        ptr += 2;
    }
    
    const size_t count = (strlen(ptr) + 1) / 2;
    uint8_t *data = (uint8_t *)malloc(count);

    size_t index = 0;
    while (ptr != hex.bytes + hex.len && *ptr != 0) {
        uint8_t high = value(*ptr);
        ptr += 1;
        if (ptr == hex.bytes + hex.len || *ptr == 0) {
            data[index] = high;
            break;
        }

        uint8_t low = value(*ptr);
        ptr += 1;

        data[index] = (high << 4) | low;
        index += 1;
    }

    struct TWData result = { .bytes = data, .len = count };
    return result;
}

void TWDataDelete(struct TWData data) {
    free((void *) data.bytes);
}
