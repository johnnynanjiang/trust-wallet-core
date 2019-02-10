// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "gtest/gtest.h"

#include "../src/Stellar/xdr/Stellar-transaction.h"
#include "../src/HexCoding.h"

using namespace TW;
using namespace stellar;

TEST(Stellar, Strings) {
    TransactionEnvelope te;

    stellar::PublicKey publicKey = stellar::PublicKey{};
    te.tx.sourceAccount = publicKey;
    te.tx.fee = 10;
    te.tx.seqNum = 1;

    //EXPECT_EQ("", te.tx.sourceAccount.ed25519());
    EXPECT_EQ(10, te.tx.fee);
    EXPECT_EQ(1, te.tx.seqNum);
}