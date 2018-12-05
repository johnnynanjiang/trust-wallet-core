#include "gtest/gtest.h"
#include "TWTestUtilities.h"

TEST(StringTests, HexZero) {
    uint8_t bytes[] = { 0 };
    auto data = WRAPD(TWDataCreateWithBytes(bytes, 1));
    auto zero = WRAPS(TWStringCreateWithHexData(data.get()));
    ASSERT_STREQ(TWStringUTF8Bytes(zero.get()), "00");
}

TEST(StringTests, HexNumber) {
    uint8_t bytes[] = { 0xde, 0xad, 0xbe, 0xef };
    auto data = WRAPD(TWDataCreateWithBytes(bytes, 4));
    auto string = WRAPS(TWStringCreateWithHexData(data.get()));
    ASSERT_STREQ(TWStringUTF8Bytes(string.get()), "deadbeef");
}
