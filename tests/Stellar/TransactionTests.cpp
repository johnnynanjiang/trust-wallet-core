// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "gtest/gtest.h"

#include "../src/Stellar/xdr/Stellar-transaction.h"
#include "../src/Stellar/Stellar.h"
#include "../src/Stellar/Constants.h"

using namespace stellar;

TEST(Stellar, CreatingTransaction) {
    // https://www.stellar.org/laboratory/#xdr-viewer?input=AAAAAIPH3PyvLJqtxhUC5fUzEvZkXimsEtWVLG6EYPZon7HnAAAAZAAfG3oAAAAIAAAAAAAAAAAAAAABAAAAAAAAAAEAAAAAinQ%2BkabSvDIkRwpp5V3FmM4zhj87QlUcjS3qrYf7sdwAAAAAAAAAAACYloAAAAAAAAAAAWifsecAAABABz36Bu4CJ30qYcCMG6cqxbSnZyfVUhD4Gnia5o6tfCjYOM%2BPO4JHEinovzgj48g67joCaqTi4IWFIy8xUGlWBQ%3D%3D&type=TransactionEnvelope&network=test
}

TEST(Stellar, TransactionSigning) {
    TransactionEnvelope te;

    stellar::PublicKey publicKey = PublicKey{};
    //publicKey.ed25519_ = payload; // TODO by jnj: covert uint8_t[] to uint32_t

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
    const char * PUBLIC_KEY_HASH = "GCB4PXH4V4WJVLOGCUBOL5JTCL3GIXRJVQJNLFJMN2CGB5TIT6Y6PQMB";

    uint8_t decodedInBase32[SIZE_ENCODED_PUBLIC_KEY] = {};
    int sizeOfDecodedInBase32 = sizeof(decodedInBase32);

    decodePublicKey(PUBLIC_KEY_HASH, decodedInBase32, sizeOfDecodedInBase32);

    EXPECT_EQ("[48, -125, -57, -36, -4, -81, 44, -102, -83, -58, 21, 2, -27, -11, 51, 18, -10, 100, 94, 41, -84, 18, -43, -107, 44, 110, -124, 96, -10, 104, -97, -79, -25, -63, -127]", getString(decodedInBase32, sizeOfDecodedInBase32));

    uint8_t version[SIZE_VERSION] = {};
    uint8_t payload[SIZE_PAYLOAD] = {};
    uint8_t checksum[SIZE_CHECKSUM] = {};

    decodeAndDissectPublicKey(PUBLIC_KEY_HASH, version, payload, checksum);

    EXPECT_EQ("[48]", getString(version, sizeof(version)));
    EXPECT_EQ("[-125, -57, -36, -4, -81, 44, -102, -83, -58, 21, 2, -27, -11, 51, 18, -10, 100, 94, 41, -84, 18, -43, -107, 44, 110, -124, 96, -10, 104, -97, -79, -25]", getString(payload, sizeof(payload)));
    EXPECT_EQ("[-63, -127]", getString(checksum, sizeof(checksum)));

    // TODO by jnj: implement versoin and checksum validation
}