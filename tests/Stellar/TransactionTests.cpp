// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "gtest/gtest.h"

#include "../src/Stellar/xdr/Stellar-transaction.h"
#include "../src/Stellar/constants.h"
#include "../src/HexCoding.h"
#include "../trezor-crypto/include/TrezorCrypto/base32.h"

using namespace TW;
using namespace stellar;

std::string getString(uint8_t *charArray, int size) {
    std::string signedCharArrayInString = "";

    signedCharArrayInString.append("[");
    for (int i=0; i<size; i++) {
        signedCharArrayInString.append(std::to_string(+(int8_t)charArray[i]));
        
        if (i != size-1) {
            signedCharArrayInString.append(", ");
        } 
    }
    signedCharArrayInString.append("]");

    return signedCharArrayInString;
}

TEST(Stellar, TransactionSigning) {
    TransactionEnvelope te;

    stellar::PublicKey publicKey = PublicKey{};
    te.tx.sourceAccount = publicKey;
    te.tx.fee = 10;
    te.tx.seqNum = 1;
    
    EXPECT_EQ(10, te.tx.fee);
    EXPECT_EQ(1, te.tx.seqNum);
}

TEST(Stellar, Versions) {
    EXPECT_EQ(48, VERSION_ACCOUNT_ID);
}

TEST(Stellar, PublicKeyDecoding) {
    const char *publicKeyCharArray = "GCB4PXH4V4WJVLOGCUBOL5JTCL3GIXRJVQJNLFJMN2CGB5TIT6Y6PQMB";

    uint8_t decodedInBase32[35] = "";
    int size = sizeof(decodedInBase32);

    base32_decode(publicKeyCharArray, strlen(publicKeyCharArray), decodedInBase32, size, BASE32_ALPHABET_RFC4648);
    std::string decodedPublicKeyAsCharArrayInString = getString(decodedInBase32, sizeof(decodedInBase32));

    EXPECT_EQ("[48, -125, -57, -36, -4, -81, 44, -102, -83, -58, 21, 2, -27, -11, 51, 18, -10, 100, 94, 41, -84, 18, -43, -107, 44, 110, -124, 96, -10, 104, -97, -79, -25, -63, -127]", decodedPublicKeyAsCharArrayInString);

    uint8_t version[SIZE_VERSION] = "";
    uint8_t payload[SIZE_PAYLOAD] = "";
    uint8_t checksum[SIZE_CHECKSUM] = "";

    std::copy(decodedInBase32, decodedInBase32 + SIZE_VERSION, version);
    std::copy(decodedInBase32 + SIZE_VERSION, decodedInBase32 + SIZE_VERSION + SIZE_PAYLOAD, payload);
    std::copy(decodedInBase32 + SIZE_VERSION + SIZE_PAYLOAD, decodedInBase32 + SIZE_VERSION + SIZE_PAYLOAD + SIZE_CHECKSUM, checksum);

    EXPECT_EQ("[48]", getString(version, sizeof(version)));
    EXPECT_EQ("[-125, -57, -36, -4, -81, 44, -102, -83, -58, 21, 2, -27, -11, 51, 18, -10, 100, 94, 41, -84, 18, -43, -107, 44, 110, -124, 96, -10, 104, -97, -79, -25]", getString(payload, sizeof(payload)));
    EXPECT_EQ("[-63, -127]", getString(checksum, sizeof(checksum)));
    
    // TODO by jnj: implement versoin and checksum validation
}