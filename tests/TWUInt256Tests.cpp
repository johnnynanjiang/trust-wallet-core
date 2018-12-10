// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "gtest/gtest.h"
#include "TWTestUtilities.h"

#include <TrustWalletCore/TWUInt256.h>

TEST(UInt256Tests, ZeroIsZero) {
    auto zero = TWUInt256Zero();
    ASSERT_TRUE(TWUInt256IsZero(zero));
    TWUInt256Delete(zero);
}

TEST(UInt256Tests, OneIsNotZero) {
    auto one = TWUInt256One();
    ASSERT_FALSE(TWUInt256IsZero(one));
    TWUInt256Delete(one);
}

TEST(UInt256Tests, CreateWithData) {
    uint8_t bytes[] = {0x1b, 0xc1, 0x6d, 0x67, 0x4e, 0xc8, 0x00, 0x00};
    auto data = WRAPD(TWDataCreateWithBytes(bytes, 8));
    auto number = WRAP(TWUInt256, TWUInt256CreateWithData(data.get()));

    auto actual = WRAPD(TWUInt256Data(number.get()));

    ASSERT_EQ(TWDataSize(actual.get()), 32);
    for (auto i = 0; i < 24; i += 1)
        ASSERT_EQ(TWDataBytes(actual.get())[i], 0);
    ASSERT_EQ(TWDataBytes(actual.get())[24], 0x1b);
    ASSERT_EQ(TWDataBytes(actual.get())[25], 0xc1);
    ASSERT_EQ(TWDataBytes(actual.get())[26], 0x6d);
    ASSERT_EQ(TWDataBytes(actual.get())[27], 0x67);
    ASSERT_EQ(TWDataBytes(actual.get())[28], 0x4e);
    ASSERT_EQ(TWDataBytes(actual.get())[29], 0xc8);
    ASSERT_EQ(TWDataBytes(actual.get())[30], 0x00);
    ASSERT_EQ(TWDataBytes(actual.get())[31], 0x00);
}
