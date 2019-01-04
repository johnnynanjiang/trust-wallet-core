// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "gtest/gtest.h"
#include "../src/UInt256.h"

using namespace TW;

TEST(UInt256Tests, ZeroIsZero) {
    auto zero = UInt256();
    for (auto i = 0; i < UInt256::wordCount; i+= 1) {
        ASSERT_EQ(zero.words[i], 0);
    }
}

TEST(UInt256Tests, Add) {
    auto zero = UInt256();
    auto num = UInt256(12345u);
    ASSERT_EQ(zero + num, num);
}

TEST(UInt256Tests, AddOverflow) {
    auto number = UInt256();
    auto expected = UInt256();
    for (auto i = 0; i < UInt256::wordCount; i+= 1) {
        number.words[i] = 0xffff'ffff'ffff'ffff;
    }
    number.words[UInt256::wordCount - 1] = 0x7fff'ffff'ffff'ffff;
    expected.words[UInt256::wordCount - 1] = 0x8000'0000'0000'0000;
    auto result = number + UInt256(1u);
    
    ASSERT_EQ(result, expected);
}

TEST(UInt256Tests, Multiply) {
    auto number = UInt256();
    auto expected = UInt256();
    for (auto i = 0; i < UInt256::wordCount; i+= 1) {
        number.words[i] = 0xffff'ffff'ffff'ffff;
        expected.words[i] = 0xffff'ffff'ffff'ffff;
    }
    number.words[UInt256::wordCount - 1] = 0x0fff'ffff'ffff'ffff;
    expected.words[0] = 0xffff'ffff'ffff'fffe;
    expected.words[UInt256::wordCount - 1] = 0x1fff'ffff'ffff'ffff;
    auto result = number * UInt256(2u);

    ASSERT_EQ(result, expected);
}
