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

TEST(Stellar, PublicKeyDecoding) {
    const char *publicKeyCharArray = "GCB4PXH4V4WJVLOGCUBOL5JTCL3GIXRJVQJNLFJMN2CGB5TIT6Y6PQMB";

    uint8_t decodedInBase32[35] = "";
    int size = sizeof(decodedInBase32);

    base32_decode(publicKeyCharArray, strlen(publicKeyCharArray), (uint8_t *) decodedInBase32, size, BASE32_ALPHABET_RFC4648);
    
    std::string signedCharArrayInString = "";
    signedCharArrayInString.append("[");
    for (int i=0; i<size; i++) {
        signedCharArrayInString.append(std::to_string(+(int8_t)decodedInBase32[i]));
        
        if (i != size-1) {
            signedCharArrayInString.append(", ");
        } 
    }
    signedCharArrayInString.append("]");

    std::string decodedPublicKeyAsCharArrayInString = signedCharArrayInString;

    EXPECT_EQ("[48, -125, -57, -36, -4, -81, 44, -102, -83, -58, 21, 2, -27, -11, 51, 18, -10, 100, 94, 41, -84, 18, -43, -107, 44, 110, -124, 96, -10, 104, -97, -79, -25, -63, -127]", decodedPublicKeyAsCharArrayInString);
}