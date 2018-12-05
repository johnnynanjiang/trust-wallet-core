#include "gtest/gtest.h"
#include "TWTestUtilities.h"

TEST(DataTests, ParseHex) {
    auto zero = DATA("0x0");
    ASSERT_EQ(TWDataSize(zero.get()), 1);
    ASSERT_EQ(TWDataBytes(zero.get())[0], 0);

    auto num = DATA("0xdeadbeef");
    ASSERT_EQ(TWDataSize(num.get()), 4);
    ASSERT_EQ(TWDataBytes(num.get())[0], 0xde);
    ASSERT_EQ(TWDataBytes(num.get())[1], 0xad);
    ASSERT_EQ(TWDataBytes(num.get())[2], 0xbe);
    ASSERT_EQ(TWDataBytes(num.get())[3], 0xef);
}
