#include "gtest/gtest.h"
#include <TrustWalletCore/TWString.h>

TEST(StringTests, HexZero) {
    uint8_t bytes[] = { 0 };
    auto zero = TWStringCreateWithHexData({ .bytes = bytes, .len = 1 });
    ASSERT_STREQ(zero.bytes, "00");
}

TEST(StringTests, HexNumber) {
    uint8_t bytes[] = { 0xde, 0xad, 0xbe, 0xef };
    auto zero = TWStringCreateWithHexData({ .bytes = bytes, .len = 4 });
    ASSERT_STREQ(zero.bytes, "deadbeef");
}
