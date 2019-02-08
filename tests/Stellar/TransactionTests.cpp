// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "gtest/gtest.h"

#include "../src/Stellar/include/Stellar-transaction.h"
#include "../src/HexCoding.h"

using namespace TW;
using namespace stellar;

TEST(Stellar, Strings) {
    EXPECT_EQ("80", "80");
}