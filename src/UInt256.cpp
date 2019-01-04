// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "UInt256.h"
#include "HexCoding.h"

#include <tuple>

using namespace TW;

std::string UInt256::hex() const {
    auto bytes = reinterpret_cast<const uint8_t*>(words);
    return TW::hex(
        std::reverse_iterator<const uint8_t*>(bytes + UInt256::byteCount),
        std::reverse_iterator<const uint8_t*>(bytes)
    );
}

/// Adds two numbers and returns a tuple with the result and carry.
static std::tuple<uint64_t, bool> addReportingOverflow(uint64_t lhs, uint64_t rhs) {
    uint64_t result;
    if (__builtin_add_overflow(lhs, rhs, &result)) {
        return std::make_tuple(result, 1);
    }
    return std::make_tuple(result, 0);
}

/// Multiplies two numbers and returns a tuple with the result and carry.
static std::tuple<uint64_t, uint64_t> multiplyFullWidth(uint64_t lhs, uint64_t rhs) {
    const auto wordBitCount = UInt256::wordSize * 8;
    const auto halfsizeMax = (1ul << (wordBitCount/2)) - 1ul;
    auto lhs_high = lhs >> wordBitCount/2;
    auto lhs_low  = lhs & halfsizeMax;
    auto rhs_high = rhs >> wordBitCount/2;
    auto rhs_low  = rhs & halfsizeMax;

    auto bot_bits = lhs_low * rhs_low;
    if ((lhs_high | rhs_high) == 0) {
        return std::make_tuple(bot_bits, 0);
    }

    auto mid_bits1 = lhs_low * rhs_high;
    auto mid_bits2 = lhs_high * rhs_low;
    auto high_bits = lhs_high * rhs_high;

    auto low = addReportingOverflow(bot_bits, (mid_bits1 + mid_bits2) << wordBitCount/2);
    return std::make_tuple(
        std::get<0>(low),
        (std::get<1>(low) ? 1 : 0) + ((mid_bits1 + mid_bits2) >> wordBitCount/2) + high_bits
    );
}

bool UInt256::addWordReportingOverflow(Word word, size_t shift) {
    assert(shift >= 0);
    auto carry = word;
    auto i = shift;
    while (carry > 0 && i < UInt256::wordCount) {
        auto d = Word();
        auto c = __builtin_add_overflow(words[i], carry, &d);
        words[i] = d;
        carry = (c ? 1 : 0);
        i += 1;
    }
    return carry > 0;
}

bool UInt256::addReportingOverflow(const UInt256& other, size_t shift) {
    assert(shift >= 0);
    auto carry = false;
    auto bi = 0;
    while (bi < UInt256::wordCount) {
        const auto ai = shift + bi;
        auto d = Word();
        auto c = __builtin_add_overflow(words[ai], other.words[bi], &d);
        if (carry) {
            auto d2 = Word();
            auto c2 = __builtin_add_overflow(d, 1, &d2);
            words[ai] = d2;
            carry = c || c2;
        } else {
            words[ai] = d;
            carry = c;
        }
        bi += 1;
    }
    return carry > 0;
}

bool UInt256::subtractWordReportingOverflow(Word word, size_t shift) {
    assert(shift >= 0);
    auto carry = word;
    auto i = shift;
    while (carry > 0 && i < UInt256::wordCount) {
        auto d = Word();
        auto c = __builtin_sub_overflow(words[i], carry, &d);
        words[i] = d;
        carry = (c ? 1 : 0);
        i += 1;
    }
    return carry > 0;
}

bool UInt256::subtractReportingOverflow(const UInt256& other, size_t shift) {
    assert(shift >= 0);
    auto carry = false;
    auto bi = 0;
    while (bi < UInt256::wordCount || (shift + bi < UInt256::wordCount && carry)) {
        const auto ai = shift + bi;
        auto d = Word();
        auto c = __builtin_sub_overflow(words[ai], other.words[bi], &d);
        if (carry) {
            auto d2 = Word();
            auto c2 = __builtin_sub_overflow(d, 1, &d);
            words[ai] = d2;
            carry = c || c2;
        } else {
            words[ai] = d;
            carry = c;
        }
        bi += 1;
    }
    return carry;
}

void UInt256::multiplyAndAdd(const UInt256& x, const Word& y, size_t shift) {
    assert(shift >= 0);
    if (y == 0) {
        return;
    }
    if (y == 1) {
        addReportingOverflow(x, shift);
        return;
    }
    auto mulCarry = Word();
    auto addCarry = false;
    auto xi = 0;
    while (xi < UInt256::wordCount) {
        const auto mult = multiplyFullWidth(x.words[xi], y);
        const auto l = std::get<0>(mult);
        const auto h = std::get<1>(mult);

        const auto low = ::addReportingOverflow(l, mulCarry);
        mulCarry = (std::get<1>(low) ? h + 1 : h);

        const auto ai = shift + xi;
        const auto sum1 = ::addReportingOverflow(words[ai], std::get<0>(low));
        if (addCarry) {
            const auto sum2 = ::addReportingOverflow(std::get<0>(sum1), 1);
            words[ai] = std::get<0>(sum2);
            addCarry = std::get<1>(sum1) || std::get<1>(sum2);
        } else {
            words[ai] = std::get<0>(sum1);
            addCarry = std::get<1>(sum1);
        }
        xi += 1;
    }

    assert(!addCarry && mulCarry == 0);
}

UInt256& UInt256::operator+=(const UInt256& rhs) {
    const auto overflow = addReportingOverflow(rhs);
    assert(!overflow);
    return *this;
}

UInt256& UInt256::operator-=(const UInt256& rhs) {
    const auto overflow = subtractReportingOverflow(rhs);
    assert(!overflow);
    return *this;
}

UInt256& UInt256::operator*=(const UInt256& rhs) {
    auto result = UInt256();
    for (auto i = 0; i < UInt256::wordCount; i += 1) {
        const auto index = UInt256::wordCount - i - 1;
        result.multiplyAndAdd(*this, rhs.words[index], index);
    }
    *this = std::move(result);
    return *this;
}
