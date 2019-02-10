// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "gtest/gtest.h"

#include "../src/Stellar/xdr/Stellar-transaction.h"
#include "../src/HexCoding.h"
#include "../trezor-crypto/include/TrezorCrypto/base32.h"

using namespace TW;
using namespace stellar;

TEST(Stellar, TransactionSigning) {
    TransactionEnvelope te;

    stellar::PublicKey publicKey = PublicKey{};
    te.tx.sourceAccount = publicKey;
    te.tx.fee = 10;
    te.tx.seqNum = 1;
    
    EXPECT_EQ(10, te.tx.fee);
    EXPECT_EQ(1, te.tx.seqNum);
}

TEST(Stellar, PublicKey) {
    const char *publicKeyCharArray = "GCB4PXH4V4WJVLOGCUBOL5JTCL3GIXRJVQJNLFJMN2CGB5TIT6Y6PQMB";
    char decodedPublicKey[64];

    std::cout << "\n" << ">>> Stellar test - public key >>> " << publicKeyCharArray << "\n";
    base32_decode(publicKeyCharArray, strlen(publicKeyCharArray), (uint8_t *) decodedPublicKey, sizeof(decodedPublicKey), BASE32_ALPHABET_RFC4648);
    std::cout << "\n" << ">>> Stellar test - decoded public key >>> " << decodedPublicKey << "\n";
    EXPECT_EQ("???", std::string(decodedPublicKey));
}