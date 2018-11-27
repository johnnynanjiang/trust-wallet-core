#include "gtest/gtest.h"
#include <TrustWalletCore/TWData.h>

TEST(DataTests, ParseHex) {
    auto zero = TWDataCreateWithHexString({ .bytes = "0x0", .len = 3 });
    ASSERT_EQ(zero.len, 1);
    ASSERT_EQ(zero.bytes[0], 0);
    TWDataDelete(zero);

    auto num = TWDataCreateWithHexString({ .bytes = "0xdeadbeef", .len = 11 });
    ASSERT_EQ(num.len, 4);
    ASSERT_EQ(num.bytes[0], 0xde);
    ASSERT_EQ(num.bytes[1], 0xad);
    ASSERT_EQ(num.bytes[2], 0xbe);
    ASSERT_EQ(num.bytes[3], 0xef);
    TWDataDelete(num);
}
