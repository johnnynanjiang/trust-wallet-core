#include "gtest/gtest.h"

#include "../../src/Data.h"
#include "../../src/Hash.h"
#include "../../src/HexCoding.h"
#include "../src/Stellar/xdr/Stellar-transaction.h"
#include "../src/Stellar/Stellar.h"

using namespace TW;
using namespace TW::Stellar;
using namespace TW::Hash;
using namespace stellar;

const char * ACCOUT_ID_HASH_OF_FROM = "GCB4PXH4V4WJVLOGCUBOL5JTCL3GIXRJVQJNLFJMN2CGB5TIT6Y6PQMB";
const char * ACCOUT_ID_HASH_OF_TO = "GCFHIPURU3JLYMREI4FGTZK5YWMM4M4GH45UEVI4RUW6VLMH7OY5YECK";
const char * DECODED_PUBLIC_KEY_OF_FROM = "[-125, -57, -36, -4, -81, 44, -102, -83, -58, 21, 2, -27, -11, 51, 18, -10, 100, 94, 41, -84, 18, -43, -107, 44, 110, -124, 96, -10, 104, -97, -79, -25]";
const char * DECODED_PUBLIC_KEY_OF_TO = "[-118, 116, 62, -111, -90, -46, -68, 50, 36, 71, 10, 105, -27, 93, -59, -104, -50, 51, -122, 63, 59, 66, 85, 28, -115, 45, -22, -83, -121, -5, -79, -36]";
const uint32 TX_FEE = 100;
const long TX_AMOUNT = 10L;
std::string NETWORK_PASSPHRASE_PUBLIC = "Public Global Stellar Network ; September 2015";
std::string NETWORK_PASSPHRASE_TESTNET = "Test SDF Network ; September 2015";

TEST(Stellar, DecodePublicKey) {
    uint8_t decodedInBase32[SIZE_ENCODED_PUBLIC_KEY] = {};
    int sizeOfDecodedInBase32 = sizeof(decodedInBase32);

    decodePublicKey(ACCOUT_ID_HASH_OF_FROM, decodedInBase32, sizeOfDecodedInBase32);

    EXPECT_EQ("[48, -125, -57, -36, -4, -81, 44, -102, -83, -58, 21, 2, -27, -11, 51, 18, -10, 100, 94, 41, -84, 18, -43, -107, 44, 110, -124, 96, -10, 104, -97, -79, -25, -63, -127]", 
                getString(decodedInBase32, sizeOfDecodedInBase32));

    TW::Stellar::AccountID accountId = decodeAndDissectPublicKey(ACCOUT_ID_HASH_OF_FROM);

    EXPECT_EQ("[48]", getString(accountId.version, sizeof(accountId.version)));
    EXPECT_EQ(DECODED_PUBLIC_KEY_OF_FROM, getString(accountId.payload, sizeof(accountId.payload)));
    EXPECT_EQ("[-63, -127]", getString(accountId.checksum, sizeof(accountId.checksum)));

    // TODO by jnj: implement versoin and checksum validation, and throw std::runtime_error("invalid public key") if it fails
}

TEST(Stellar, CreateTransaction) {
    // https://www.stellar.org/laboratory/#xdr-viewer?input=AAAAAIPH3PyvLJqtxhUC5fUzEvZkXimsEtWVLG6EYPZon7HnAAAAZAAfG3oAAAAIAAAAAAAAAAAAAAABAAAAAAAAAAEAAAAAinQ%2BkabSvDIkRwpp5V3FmM4zhj87QlUcjS3qrYf7sdwAAAAAAAAAAACYloAAAAAAAAAAAWifsecAAABABz36Bu4CJ30qYcCMG6cqxbSnZyfVUhD4Gnia5o6tfCjYOM%2BPO4JHEinovzgj48g67joCaqTi4IWFIy8xUGlWBQ%3D%3D&type=TransactionEnvelope&network=test

    PublicKey publicKey = getPublicKeyFromHash(ACCOUT_ID_HASH_OF_FROM);
    Operation op = TW::Stellar::createPaymentOperation(
                        getPublicKeyFromHash(ACCOUT_ID_HASH_OF_TO), TX_AMOUNT);
    
    TransactionEnvelope te;

    te.tx.sourceAccount = publicKey;
    te.tx.fee = TX_FEE;
    te.tx.seqNum = 1;
    te.tx.operations = { op };

    EXPECT_EQ(DECODED_PUBLIC_KEY_OF_FROM, 
                getString(te.tx.sourceAccount.ed25519().data(), 
                            sizeof(te.tx.sourceAccount.ed25519())));
    
    EXPECT_EQ(DECODED_PUBLIC_KEY_OF_TO, 
                getString(te.tx.operations[0].body.paymentOp().destination.ed25519().data(), 
                            sizeof(te.tx.operations[0].body.paymentOp().destination.ed25519())));
    EXPECT_EQ(TX_AMOUNT, te.tx.operations[0].body.paymentOp().amount);

    EXPECT_EQ(TX_FEE, te.tx.fee);
    EXPECT_EQ(1, te.tx.seqNum);
}

TEST(Stellar, SignTransaction) {
    PublicKey publicKey = getPublicKeyFromHash(ACCOUT_ID_HASH_OF_FROM);
    Operation op = TW::Stellar::createPaymentOperation(
                        getPublicKeyFromHash(ACCOUT_ID_HASH_OF_TO), TX_AMOUNT);
    
    TransactionEnvelope te;

    te.tx.sourceAccount = publicKey;
    te.tx.fee = TX_FEE;
    te.tx.seqNum = 1;
    te.tx.operations = { op };

    TW::Data dataToHash;

    // network id
    TW::Data hash = TW::Hash::sha256(NETWORK_PASSPHRASE_TESTNET);

    EXPECT_EQ("cee0302d59844d32bdca915c8203dd44b33fbb7edc19051ea37abedf28ecd472", 
                TW::hex(hash.begin(), hash.end()));

    // envelope type

    // EXPECT_EQ("0416ad60a023bf7d8073e40fb7172c018df3acd8ceff4195527881d33695a5fc", "");

    // final hash
    std::copy(hash.begin(), hash.end(), std::back_inserter(dataToHash));

    auto hashResult = TW::Hash::sha256(dataToHash);

    EXPECT_EQ("f016a53457a4476cf07e542bd23736b4f19aae21a91dfa14841b648522bdc2da", 
                TW::hex(hashResult.begin(), hashResult.end()));    
}