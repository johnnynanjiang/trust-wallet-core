#include "gtest/gtest.h"

#include "../../src/Data.h"
#include "../../src/Hash.h"
#include "../../src/HexCoding.h"
#include "../src/Stellar/xdr/Stellar-transaction.h"
#include "../src/Stellar/Stellar.h"
// TODO by jnj: add TrezorCrypto in target_link_libraries in CMakeLists.txt for tests as a temporary workaround, need to undo it eventually
#include <TrezorCrypto/bip32.h>
#include <TrezorCrypto/curves.h>

using namespace TW;
using namespace TW::Stellar;
using namespace TW::Hash;
using namespace stellar;

const char * ACCOUT_ID_HASH_OF_FROM = "GCB4PXH4V4WJVLOGCUBOL5JTCL3GIXRJVQJNLFJMN2CGB5TIT6Y6PQMB";
const char * ACCOUT_ID_HASH_OF_TO = "GCFHIPURU3JLYMREI4FGTZK5YWMM4M4GH45UEVI4RUW6VLMH7OY5YECK";
const char * DECODED_PUBLIC_KEY_OF_FROM = "[-125, -57, -36, -4, -81, 44, -102, -83, -58, 21, 2, -27, -11, 51, 18, -10, 100, 94, 41, -84, 18, -43, -107, 44, 110, -124, 96, -10, 104, -97, -79, -25]";
const char * DECODED_PUBLIC_KEY_OF_TO = "[-118, 116, 62, -111, -90, -46, -68, 50, 36, 71, 10, 105, -27, 93, -59, -104, -50, 51, -122, 63, 59, 66, 85, 28, -115, 45, -22, -83, -121, -5, -79, -36]";
const uint32 TX_FEE = 100;
const int64 TX_SEQ_NUMBER = 1;
const long TX_AMOUNT = 10L;
const char * TX_MEMO = "test by JNJ";
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
    te.tx.seqNum = TX_SEQ_NUMBER;
    te.tx.memo = CreateMemoText(TX_MEMO);
    te.tx.operations = { op };

    EXPECT_EQ(DECODED_PUBLIC_KEY_OF_FROM, 
                GetString(te.tx.sourceAccount.ed25519().data(), 
                            sizeof(te.tx.sourceAccount.ed25519())));
    EXPECT_EQ(DECODED_PUBLIC_KEY_OF_TO, 
                GetString(te.tx.operations[0].body.paymentOp().destination.ed25519().data(), 
                            sizeof(te.tx.operations[0].body.paymentOp().destination.ed25519())));
    // TODO by jnj: need to set source account id to operations
    EXPECT_EQ(NULL, te.tx.operations[0].sourceAccount.get());                        
    EXPECT_EQ(TX_AMOUNT, te.tx.operations[0].body.paymentOp().amount);
    EXPECT_EQ(TX_FEE, te.tx.fee);
    EXPECT_EQ(TX_SEQ_NUMBER, te.tx.seqNum);
    EXPECT_EQ(std::string(TX_MEMO), std::string(te.tx.memo.text().data()));
}

TEST(Stellar, HashTransaction) {
    PublicKey publicKey = GetPublicKeyFromHash(ACCOUT_ID_HASH_OF_FROM);
    Operation op = TW::Stellar::CreatePaymentOperation(
                        GetPublicKeyFromHash(ACCOUT_ID_HASH_OF_TO), TX_AMOUNT);
    
    TransactionEnvelope te;

    te.tx.sourceAccount = publicKey;
    te.tx.fee = TX_FEE;
    te.tx.seqNum = TX_SEQ_NUMBER;
    te.tx.memo = CreateMemoText(TX_MEMO);
    te.tx.operations = { op };

    TW::Data dataToHash;

    // #1 network id
    TW::Data networkIdHashData = TW::Hash::sha256(NETWORK_PASSPHRASE_TESTNET);

    EXPECT_EQ("cee0302d59844d32bdca915c8203dd44b33fbb7edc19051ea37abedf28ecd472", 
                TW::hex(networkIdHashData.begin(), networkIdHashData.end()));

    // #2 envelope type
    TW::Data envelopeTypeData = GetDataFromInt(TW::Stellar::ENVELOPE_TYPE_TX);

    EXPECT_EQ("00000002", 
                TW::hex(envelopeTypeData.begin(), envelopeTypeData.end()));

    // TX
    TW::Data txDataToHash; // contained in dataToHash

    // #3 account id
    TW::Data publicKeyTypeData = GetDataFromInt(stellar::PublicKeyType::PUBLIC_KEY_TYPE_ED25519);
    TW::Data accountIdData(te.tx.sourceAccount.ed25519().begin(), te.tx.sourceAccount.ed25519().end());

    std::copy(publicKeyTypeData.begin(), publicKeyTypeData.end(), std::back_inserter(txDataToHash));
    std::copy(accountIdData.begin(), accountIdData.end(), std::back_inserter(txDataToHash));

    EXPECT_EQ("0000000083c7dcfcaf2c9aadc61502e5f53312f6645e29ac12d5952c6e8460f6689fb1e7",
                TW::hex(txDataToHash.begin(), txDataToHash.end()));

    // #4 fee
    TW::Data feeData = GetDataFromInt(te.tx.fee);

    std::copy(feeData.begin(), feeData.end(), std::back_inserter(txDataToHash));

    EXPECT_EQ("0000000083c7dcfcaf2c9aadc61502e5f53312f6645e29ac12d5952c6e8460f6689fb1e700000064",
                TW::hex(txDataToHash.begin(), txDataToHash.end()));

    // #5 seq number
    // TODO by jnj: consider refactoring GetDataFromInt() and GetDataFromLong() using template
    TW::Data seqNumberData = GetDataFromLong(te.tx.seqNum);

    std::copy(seqNumberData.begin(), seqNumberData.end(), std::back_inserter(txDataToHash));

    EXPECT_EQ("0000000083c7dcfcaf2c9aadc61502e5f53312f6645e29ac12d5952c6e8460f6689fb1e7000000640000000000000001",
                TW::hex(txDataToHash.begin(), txDataToHash.end()));
    
    // #6 timeout
    // TODO by jnj: implement TimeBounds
    TW::Data timeoutData = GetDataFromInt(0);

    std::copy(timeoutData.begin(), timeoutData.end(), std::back_inserter(txDataToHash));

    EXPECT_EQ("0000000083c7dcfcaf2c9aadc61502e5f53312f6645e29ac12d5952c6e8460f6689fb1e700000064000000000000000100000000",
                TW::hex(txDataToHash.begin(), txDataToHash.end()));
    
    // #7 memo
    // TODO by jnj: implement all types of memo, and add length limit check or error handling
    TW::Data memoTypeData = GetDataFromInt(stellar::MemoType::MEMO_TEXT);
    TW::Data memoSizeData = GetDataFromInt(strlen(TX_MEMO));
    TW::Data memoTextData = TW::Data(TX_MEMO, TX_MEMO + strlen(TX_MEMO));

    std::copy(memoTypeData.begin(), memoTypeData.end(), std::back_inserter(txDataToHash));
    std::copy(memoSizeData.begin(), memoSizeData.end(), std::back_inserter(txDataToHash));
    std::copy(memoTextData.begin(), memoTextData.end(), std::back_inserter(txDataToHash));
    txDataToHash.push_back(NULL_TERMINATOR);

    EXPECT_EQ("0000000083c7dcfcaf2c9aadc61502e5f53312f6645e29ac12d5952c6e8460f6689fb1e700000064000000000000000100000000000000010000000b74657374206279204a4e4a00",
                TW::hex(txDataToHash.begin(), txDataToHash.end()));

    // #8 operations
    EXPECT_EQ(1, te.tx.operations.size());

    TW::Data operationSizeData = GetDataFromInt(te.tx.operations.size());

    std::copy(operationSizeData.begin(), operationSizeData.end(), std::back_inserter(txDataToHash));

    EXPECT_EQ("0000000083c7dcfcaf2c9aadc61502e5f53312f6645e29ac12d5952c6e8460f6689fb1e700000064000000000000000100000000000000010000000b74657374206279204a4e4a0000000001",
                TW::hex(txDataToHash.begin(), txDataToHash.end()));

    Operation operation = te.tx.operations[0];
    xdr::pointer<stellar::AccountID> sourceAccountPtr = operation.sourceAccount;
    TW::Data sourceAccountFlagData;

    // #8.1 source account
    if (sourceAccountPtr.get() != NULL) {
        // TODO by jnj: implement and test the case where sourceAccount is not null
        sourceAccountFlagData = GetDataFromInt(1);
        TW::Data sourceAccountTypeData = GetDataFromInt(sourceAccountPtr->type());
        TW::Data sourceAccountData;

        std::copy(std::begin(sourceAccountPtr->ed25519()), std::end(sourceAccountPtr->ed25519()), std::back_inserter(sourceAccountData));
    
        std::copy(sourceAccountFlagData.begin(), sourceAccountFlagData.end(), std::back_inserter(txDataToHash));
        std::copy(sourceAccountTypeData.begin(), sourceAccountTypeData.end(), std::back_inserter(txDataToHash));
        std::copy(sourceAccountData.begin(), sourceAccountData.end(), std::back_inserter(txDataToHash));

        EXPECT_EQ("to find out the expected result from Stellar Java SDK test",
                    TW::hex(txDataToHash.begin(), txDataToHash.end()));
    } else {
        sourceAccountFlagData = GetDataFromInt(0);

        std::copy(sourceAccountFlagData.begin(), sourceAccountFlagData.end(), std::back_inserter(txDataToHash));

        EXPECT_EQ("0000000083c7dcfcaf2c9aadc61502e5f53312f6645e29ac12d5952c6e8460f6689fb1e700000064000000000000000100000000000000010000000b74657374206279204a4e4a000000000100000000",
                    TW::hex(txDataToHash.begin(), txDataToHash.end()));
    }

    // #8.2 operation body
    TW::Data operationTypeData = GetDataFromInt(operation.body.type());

    std::copy(operationTypeData.begin(), operationTypeData.end(), std::back_inserter(txDataToHash));

    EXPECT_EQ("0000000083c7dcfcaf2c9aadc61502e5f53312f6645e29ac12d5952c6e8460f6689fb1e700000064000000000000000100000000000000010000000b74657374206279204a4e4a00000000010000000000000001",
                TW::hex(txDataToHash.begin(), txDataToHash.end()));

    // TODO by jnj: implement encoding for 12 types of operations, they are different
    /*
    TW::Data operationDestinationData;

    // TODO by jnj: continue from here
    std::copy(operation.body.destination().ed25519().data(), operation.body.destination().ed25519().data(), std::back_inserter(operationDestinationData));

    EXPECT_EQ("???",
            TW::hex(operationDestinationData.begin(), operationDestinationData.end()));
    */

    // final hash
    std::copy(networkIdHashData.begin(), networkIdHashData.end(), std::back_inserter(dataToHash));
    std::copy(envelopeTypeData.begin(), envelopeTypeData.end(), std::back_inserter(dataToHash));
    std::copy(txDataToHash.begin(), txDataToHash.end(), std::back_inserter(dataToHash));

    auto dataHashed = TW::Hash::sha256(dataToHash);

    EXPECT_EQ("4a4a13e6e0892d9428ea459db574f16812ff91ab45bff82f8b571139a417942a", 
                TW::hex(dataHashed.begin(), dataHashed.end()));    
}

TEST(Stellar, SignTransaction) {
    const char * SECRET_SEED = "SCH27VUZZ6UAKB67BDNF6FA42YMBMQCBKXWGMFD5TZ6S5ZZCZFLRXKHS";
    int8_t txHashBytes[] = {-42, -12, 65, 33, 16, -73, -61, -74, 71, -26, -76, 26, -41, -72, 72, 4, -91, 48, 101, 59, -63, 63, -119, 13, -103, 35, -5, -115, 92, -80, -43, -12};
    int8_t privateKeyBytes[] = {-80, 28, 113, -64, 125, -52, -97, 79, 7, 79, 1, 90, -89, -23, 68, 59, -37, 64, -45, -31, -123, 114, 124, -126, -61, -122, -4, 110, -99, 82, 2, 93};
    int8_t publicKeyBytes[] = {94, -59, 34, 32, -45, -95, 109, 95, 57, -123, 5, 4, 45, 29, -101, 43, -97, 37, -79, 83, 57, -83, -122, 64, 68, -122, -49, -28, -74, -121, -107, 98};
    int8_t signature[] = {-53, -110, 47, 78, -117, -67, 52, 55, -83, 11, -93, -56, 20, -104, 65, 71, 108, -85, -40, 27, -124, 18, -87, 120, -117, 34, -33, 83, -46, -69, -74, 59, -112, 105, -123, 89, 127, -115, 31, 109, 98, -47, -64, 15, -27, 30, 13, -120, 96, 92, -40, 48, 83, 26, -109, 18, -19, 86, -70, 75, -60, -55, -121, 3};

/* TODO by jnj: continue from here
    TW::Stellar::AccountID decodedSeed = DecodeAndDissectPublicKey(SECRET_SEED);

    HDNode node;
    hdnode_from_seed(decodedSeed.payload, 16, ED25519_NAME, &node);

    EXPECT_EQ(GetString((uint8_t *)privateKeyBytes, sizeof(privateKeyBytes)), 
                GetString(node.private_key, sizeof(node.private_key)));
*/
}