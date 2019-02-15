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
const int64 SEQ_NUMBER = 1;
const long TX_AMOUNT = 10L;
std::string NETWORK_PASSPHRASE_PUBLIC = "Public Global Stellar Network ; September 2015";
std::string NETWORK_PASSPHRASE_TESTNET = "Test SDF Network ; September 2015";

TEST(Stellar, DecodePublicKey) {
    uint8_t decodedInBase32[SIZE_ENCODED_PUBLIC_KEY] = {};
    int sizeOfDecodedInBase32 = sizeof(decodedInBase32);

    DecodePublicKey(ACCOUT_ID_HASH_OF_FROM, decodedInBase32, sizeOfDecodedInBase32);

    EXPECT_EQ("[48, -125, -57, -36, -4, -81, 44, -102, -83, -58, 21, 2, -27, -11, 51, 18, -10, 100, 94, 41, -84, 18, -43, -107, 44, 110, -124, 96, -10, 104, -97, -79, -25, -63, -127]", 
                GetString(decodedInBase32, sizeOfDecodedInBase32));

    TW::Stellar::AccountID accountId = DecodeAndDissectPublicKey(ACCOUT_ID_HASH_OF_FROM);

    EXPECT_EQ("[48]", GetString(accountId.version, sizeof(accountId.version)));
    EXPECT_EQ(DECODED_PUBLIC_KEY_OF_FROM, GetString(accountId.payload, sizeof(accountId.payload)));
    EXPECT_EQ("[-63, -127]", GetString(accountId.checksum, sizeof(accountId.checksum)));

    // TODO by jnj: implement versoin and checksum validation, and throw std::runtime_error("invalid public key") if it fails
}

TEST(Stellar, CreateTransaction) {
    // https://www.stellar.org/laboratory/#xdr-viewer?input=AAAAAIPH3PyvLJqtxhUC5fUzEvZkXimsEtWVLG6EYPZon7HnAAAAZAAfG3oAAAAIAAAAAAAAAAAAAAABAAAAAAAAAAEAAAAAinQ%2BkabSvDIkRwpp5V3FmM4zhj87QlUcjS3qrYf7sdwAAAAAAAAAAACYloAAAAAAAAAAAWifsecAAABABz36Bu4CJ30qYcCMG6cqxbSnZyfVUhD4Gnia5o6tfCjYOM%2BPO4JHEinovzgj48g67joCaqTi4IWFIy8xUGlWBQ%3D%3D&type=TransactionEnvelope&network=test

    PublicKey publicKey = GetPublicKeyFromHash(ACCOUT_ID_HASH_OF_FROM);
    Operation op = TW::Stellar::CreatePaymentOperation(
                        GetPublicKeyFromHash(ACCOUT_ID_HASH_OF_TO), TX_AMOUNT);
    
    TransactionEnvelope te;

    te.tx.sourceAccount = publicKey;
    te.tx.fee = TX_FEE;
    te.tx.seqNum = SEQ_NUMBER;
    te.tx.operations = { op };

    EXPECT_EQ(DECODED_PUBLIC_KEY_OF_FROM, 
                GetString(te.tx.sourceAccount.ed25519().data(), 
                            sizeof(te.tx.sourceAccount.ed25519())));
    
    EXPECT_EQ(DECODED_PUBLIC_KEY_OF_TO, 
                GetString(te.tx.operations[0].body.paymentOp().destination.ed25519().data(), 
                            sizeof(te.tx.operations[0].body.paymentOp().destination.ed25519())));
    EXPECT_EQ(TX_AMOUNT, te.tx.operations[0].body.paymentOp().amount);

    EXPECT_EQ(TX_FEE, te.tx.fee);
    EXPECT_EQ(1, te.tx.seqNum);
}

TEST(Stellar, SignTransaction) {
    PublicKey publicKey = GetPublicKeyFromHash(ACCOUT_ID_HASH_OF_FROM);
    Operation op = TW::Stellar::CreatePaymentOperation(
                        GetPublicKeyFromHash(ACCOUT_ID_HASH_OF_TO), TX_AMOUNT);
    
    TransactionEnvelope te;

    te.tx.sourceAccount = publicKey;
    te.tx.fee = TX_FEE;
    te.tx.seqNum = SEQ_NUMBER;
    te.tx.operations = { op };

    TW::Data dataToHash;

    // network id
    TW::Data networkIdHash = TW::Hash::sha256(NETWORK_PASSPHRASE_TESTNET);

    EXPECT_EQ("cee0302d59844d32bdca915c8203dd44b33fbb7edc19051ea37abedf28ecd472", 
                TW::hex(networkIdHash.begin(), networkIdHash.end()));

    // envelope type
    TW::Data envelopeTypeData = GetDataFromInt(TW::Stellar::ENVELOPE_TYPE_TX);

    EXPECT_EQ("00000002", 
                TW::hex(envelopeTypeData.begin(), envelopeTypeData.end()));

    // TX
    TW::Data txDataToHash; // contained in dataToHash

    // account id
    TW::Data publicKeyTypeData = GetDataFromInt(TW::Stellar::PUBLIC_KEY_TYPE_ED25519);
    TW::Data accountIdData(te.tx.sourceAccount.ed25519().begin(), te.tx.sourceAccount.ed25519().end());

    std::copy(publicKeyTypeData.begin(), publicKeyTypeData.end(), std::back_inserter(txDataToHash));
    std::copy(accountIdData.begin(), accountIdData.end(), std::back_inserter(txDataToHash));

    EXPECT_EQ("0000000083c7dcfcaf2c9aadc61502e5f53312f6645e29ac12d5952c6e8460f6689fb1e7",
                TW::hex(txDataToHash.begin(), txDataToHash.end()));

    // fee
    TW::Data feeData = GetDataFromInt(te.tx.fee);

    std::copy(feeData.begin(), feeData.end(), std::back_inserter(txDataToHash));

    EXPECT_EQ("0000000083c7dcfcaf2c9aadc61502e5f53312f6645e29ac12d5952c6e8460f6689fb1e700000064",
                TW::hex(txDataToHash.begin(), txDataToHash.end()));

    // seq number
    TW::Data seqNumberData = GetDataFromLong(te.tx.seqNum);

    std::copy(seqNumberData.begin(), seqNumberData.end(), std::back_inserter(txDataToHash));

    EXPECT_EQ("0000000083c7dcfcaf2c9aadc61502e5f53312f6645e29ac12d5952c6e8460f6689fb1e7000000640000000000000001",
                TW::hex(txDataToHash.begin(), txDataToHash.end()));

    // final hash
    std::copy(networkIdHash.begin(), networkIdHash.end(), std::back_inserter(dataToHash));
    std::copy(envelopeTypeData.begin(), envelopeTypeData.end(), std::back_inserter(dataToHash));
    std::copy(txDataToHash.begin(), txDataToHash.end(), std::back_inserter(dataToHash));

    auto dataHashed = TW::Hash::sha256(dataToHash);

    EXPECT_EQ("a60d309e0a51eb152df9785580504bbd120fc32793759b23c31d08afde99bc0b", 
                TW::hex(dataHashed.begin(), dataHashed.end()));    
}