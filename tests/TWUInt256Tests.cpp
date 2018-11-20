#include "gtest/gtest.h"
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
    auto data = TWData{bytes, 8};
    auto number = TWUInt256CreateWithData(data);

    uint8_t actual[32];
    TWUInt256CopyData(number, actual);

    for (auto i = 0; i < 24; i += 1)
        ASSERT_EQ(actual[i], 0);
    ASSERT_EQ(actual[24], 0x1b);
    ASSERT_EQ(actual[25], 0xc1);
    ASSERT_EQ(actual[26], 0x6d);
    ASSERT_EQ(actual[27], 0x67);
    ASSERT_EQ(actual[28], 0x4e);
    ASSERT_EQ(actual[29], 0xc8);
    ASSERT_EQ(actual[30], 0x00);
    ASSERT_EQ(actual[31], 0x00);

    TWUInt256Delete(number);
}
