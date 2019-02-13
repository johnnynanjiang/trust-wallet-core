#include "gtest/gtest.h"

#include "../src/Stellar/xdr/Stellar-transaction.h"
#include "../src/Stellar/Stellar.h"
#include "../src/Stellar/Constants.h"

using namespace TW::Stellar;
using namespace stellar;

const char * PUBLIC_KEY_HASH = "GCB4PXH4V4WJVLOGCUBOL5JTCL3GIXRJVQJNLFJMN2CGB5TIT6Y6PQMB";
const char * PUBLIC_KEY_DECODED = "[-125, -57, -36, -4, -81, 44, -102, -83, -58, 21, 2, -27, -11, 51, 18, -10, 100, 94, 41, -84, 18, -43, -107, 44, 110, -124, 96, -10, 104, -97, -79, -25]";

TEST(Stellar, CreatingTransaction) {
    // https://www.stellar.org/laboratory/#xdr-viewer?input=AAAAAIPH3PyvLJqtxhUC5fUzEvZkXimsEtWVLG6EYPZon7HnAAAAZAAfG3oAAAAIAAAAAAAAAAAAAAABAAAAAAAAAAEAAAAAinQ%2BkabSvDIkRwpp5V3FmM4zhj87QlUcjS3qrYf7sdwAAAAAAAAAAACYloAAAAAAAAAAAWifsecAAABABz36Bu4CJ30qYcCMG6cqxbSnZyfVUhD4Gnia5o6tfCjYOM%2BPO4JHEinovzgj48g67joCaqTi4IWFIy8xUGlWBQ%3D%3D&type=TransactionEnvelope&network=test
}

TEST(Stellar, TransactionSigning) {
    stellar::TransactionEnvelope te;
    
    stellar::PublicKey publicKey = PublicKey{};
    TW::Stellar::AccountID accountId = decodeAndDissectPublicKey(PUBLIC_KEY_HASH);
    std::memcpy(publicKey.ed25519().data(), accountId.payload, sizeof(accountId.payload));

    te.tx.sourceAccount = publicKey;
    te.tx.fee = 10;
    te.tx.seqNum = 1;

    EXPECT_EQ(PUBLIC_KEY_DECODED, 
                getString(te.tx.sourceAccount.ed25519().data(), sizeof(te.tx.sourceAccount.ed25519())));    
    EXPECT_EQ(10, te.tx.fee);
    EXPECT_EQ(1, te.tx.seqNum);
}

TEST(Stellar, PublicKeyDecoding) {
    uint8_t decodedInBase32[SIZE_ENCODED_PUBLIC_KEY] = {};
    int sizeOfDecodedInBase32 = sizeof(decodedInBase32);

    decodePublicKey(PUBLIC_KEY_HASH, decodedInBase32, sizeOfDecodedInBase32);

    EXPECT_EQ("[48, -125, -57, -36, -4, -81, 44, -102, -83, -58, 21, 2, -27, -11, 51, 18, -10, 100, 94, 41, -84, 18, -43, -107, 44, 110, -124, 96, -10, 104, -97, -79, -25, -63, -127]", 
                getString(decodedInBase32, sizeOfDecodedInBase32));

    TW::Stellar::AccountID accountId = decodeAndDissectPublicKey(PUBLIC_KEY_HASH);

    EXPECT_EQ("[48]", getString(accountId.version, sizeof(accountId.version)));
    EXPECT_EQ(PUBLIC_KEY_DECODED, getString(accountId.payload, sizeof(accountId.payload)));
    EXPECT_EQ("[-63, -127]", getString(accountId.checksum, sizeof(accountId.checksum)));

    // TODO by jnj: implement versoin and checksum validation, and throw std::runtime_error("invalid public key") if it fails
}