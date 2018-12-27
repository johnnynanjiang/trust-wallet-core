// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <algorithm>

namespace TW {

/// 256-bit unsigned integer.
class UInt256 {
public:
    using Word = uint64_t;
    static constexpr size_t wordSize = sizeof(Word);
    static constexpr size_t wordCount = 256 / wordSize / 8;
    static constexpr size_t byteCount = 256 / 8;

    /// 64-bit words
    Word words[wordCount];

    /// Initializes a UInt256 with zero.
    UInt256() = default;

    /// Initializes a UInt256 with a 64-bit unisnged integer.
    UInt256(Word val) : words{0} {
        words[0] = val;
    }

    /// Whether this is zero.
    bool isZero() const {
        return std::all_of(words, words + wordCount, [](const Word& w) { return w == 0; });
    }

    /// Converts the UInt256 to a 64-bit unsigned integer.
    operator Word() const {
        return words[0];
    }

    /// Returns a hexadecimal string representation.
    std::string hex() const;

    /// Adds `word` to this integer in place.
    ///
    /// `word` is shifted `shift` words to the left before being added.
    ///
    /// \returns a flag indicating if the operation caused an arithmetic overflow. 
    bool addWordReportingOverflow(Word word, size_t shift = 0);

    /// Add `other` to this integer in place.
    ///
    /// `other` is shifted `shift` words to the left before being added.
    ///
    /// \returns a flag indicating if the operation caused an arithmetic overflow. 
    bool addReportingOverflow(const UInt256& other, size_t shift = 0);

    /// Subtract `word` from this integer in place.
    ///
    /// `word` is shifted `shift` words to the left before being subtracted. If the result indicates an overflow, then
    /// `self` becomes the two's complement of the absolute difference.
    ///
    /// \returns a flag indicating if the operation caused an arithmetic overflow.
    bool subtractWordReportingOverflow(Word word, size_t shift = 0);

    /// Subtract `other` from this integer in place.
    ///
    /// `word` is shifted `shift` words to the left before being subtracted. If the result indicates an overflow, then
    /// `self` becomes the two's complement of the absolute difference.
    ///
    /// \returns a flag indicating if the operation caused an arithmetic overflow.
    bool subtractReportingOverflow(const UInt256& other, size_t shift = 0);

    /// Multiplies `x` by `y`, and adds the result to this integer, optionally shifted `shift` words to the left.
    ///
    /// This is the fused multiply/shift/add operation; it is more efficient than doing the components individually.
    /// (The fused operation doesn't need to allocate space for temporary big integers.)
    void multiplyAndAdd(const UInt256& x, const Word& y, size_t shift = 0);

    UInt256& operator+=(const UInt256& rhs);
    UInt256& operator-=(const UInt256& rhs);
    UInt256& operator*=(const UInt256& rhs);

    inline UInt256 operator<<(int bits) const {
        UInt256 result;
        for (auto i = 0; i < UInt256::wordCount; i++) {
            result.words[i] = words[i] << bits;
        }
        return result;
    }

    inline UInt256 operator>>(int bits) const {
        UInt256 result;
        for (auto i = 0; i < UInt256::wordCount; i++) {
            result.words[i] = words[i] >> bits;
        }
        return result;
    }
};

inline bool operator==(const UInt256& lhs, const UInt256& rhs) {
    return std::equal(
        lhs.words, lhs.words + UInt256::wordCount,
        rhs.words, rhs.words + UInt256::wordCount
    );
}

inline bool operator<(const UInt256& lhs, const UInt256& rhs) {
    return std::lexicographical_compare(
        lhs.words, lhs.words + UInt256::wordCount,
        rhs.words, rhs.words + UInt256::wordCount
    );
}

inline bool operator<=(const UInt256& lhs, const UInt256& rhs) {
    return lhs < rhs || lhs == rhs;
}

inline bool operator>(const UInt256& lhs, const UInt256& rhs) {
    return !(lhs <= rhs);
}

inline bool operator>=(const UInt256& lhs, const UInt256& rhs) {
    return !(lhs < rhs);
}

inline UInt256 operator+(const UInt256& lhs, const UInt256& rhs) {
    UInt256 result(lhs);
    result += rhs;
    return result;
}

inline UInt256 operator-(const UInt256& lhs, const UInt256& rhs) {
    UInt256 result(lhs);
    result -= rhs;
    return result;
}

inline UInt256 operator*(const UInt256& lhs, const UInt256& rhs) {
    UInt256 result(lhs);
    result *= rhs;
    return result;
}

} // namespace
