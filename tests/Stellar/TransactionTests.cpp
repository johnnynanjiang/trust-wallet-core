// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "gtest/gtest.h"

#include "../src/Stellar/xdr/Stellar-transaction.h"
#include "../src/HexCoding.h"
#include "../src/Stellar/crypto/SecretKey.h"

using namespace TW;
using namespace stellar;

TEST(Stellar, Strings) {
    TransactionEnvelope te;
    auto secretKey = SecretKey::fromSeed("SAV4O6KS2F6ZKVKRBDY2CC3AAP2NQUIN4OIET2BGSZYV6FX7OJMWPBV4");
    te.tx.sourceAccount = secretKey.getPublicKey();
    te.tx.fee = 10
    te.tx.seqNum = 1 //uint64
}