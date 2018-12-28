// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"

using namespace TW;

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

std::vector<uint8_t> TW::parse_hex(const std::string& string) {
    auto it = string.begin();

    // Skip `0x`
    if (string.size() >= 2 && string[0] == '0' && string[1] == 'x') {
        it += 2;
    }

    std::vector<uint8_t> result;
    result.reserve((string.size() + 1) / 2);

    while (it != string.end()) {
        auto high = value(*it);
        it += 1;

        if (it == string.end()) {
            result.push_back(high);
            break;
        }

        auto low = value(*it);
        it += 1;

        result.push_back((high << 4) | low);
    }

    return result;
}
