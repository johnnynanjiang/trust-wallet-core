// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWString.h>

#include <stdlib.h>
#include <string.h>

static inline char low_char(uint8_t v) {
    uint8_t lv = v & 0x0f;
    if (lv >= 0 && lv <= 9)
        return '0' + lv;
    if (lv >= 10)
        return 'a' + lv - 10;
    return 0;
}
static inline char high_char(uint8_t v) {
    uint8_t hv = (v & 0xf0) >> 4;
    if (hv >= 0 && hv <= 9)
        return '0' + hv;
    if (hv >= 10)
        return 'a' + hv - 10;
    return 0;
}

struct TWString TWStringCreateWithHexData(struct TWData data) {
    const size_t count = data.len * 2;
    char *string = (char *)malloc(count + 1);
    string[count] = 0;

    for (size_t i = 0; i < data.len; i += 1) {
        string[2 * i] = high_char(data.bytes[i]);
        string[2 * i + 1] = low_char(data.bytes[i]);
    }

    struct TWString result = { .bytes = string, .len = count };
    return result;
}

void TWStringDelete(struct TWString string) {
    free((void *) string.bytes);
}
