#include "Stellar.h"
#include "../trezor-crypto/include/TrezorCrypto/base32.h"

using namespace TW::Stellar;
using namespace stellar;

std::string TW::Stellar::GetString(uint8_t * charArray, int size) {
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

TW::Data TW::Stellar::GetDataFromInt(int number) {
    TW::Data data;
    
    TW::byte * beginPtr = reinterpret_cast<TW::byte *>(&number);

    for (int i = sizeof(int)-1; i >= 0; i--) {
         data.push_back(*(beginPtr + i));     
    }
    
    return data;
}

TW::Data TW::Stellar::GetDataFromLong(long number) {
    TW::Data data;
    
    TW::byte * beginPtr = reinterpret_cast<TW::byte *>(&number);

    for (int i = sizeof(long)-1; i >= 0; i--) {
         data.push_back(*(beginPtr + i));     
    }
    
    return data;
}

void TW::Stellar::DecodePublicKey(const char * publicKeyHash, uint8_t * decodedInBase32, int size) {
    base32_decode(publicKeyHash, strlen(publicKeyHash), decodedInBase32, size, BASE32_ALPHABET_RFC4648);    
}

TW::Stellar::AccountID TW::Stellar::DecodeAndDissectPublicKey(const char * publicKeyHash) {
    uint8_t decodedInBase32[SIZE_ENCODED_PUBLIC_KEY] = {};

    DecodePublicKey(publicKeyHash, decodedInBase32, sizeof(decodedInBase32));

    AccountID accountId;

    std::copy(decodedInBase32, 
                decodedInBase32 + SIZE_ACCOUNT_ID_VERSION, 
                accountId.version);
    std::copy(decodedInBase32 + SIZE_ACCOUNT_ID_VERSION, 
                decodedInBase32 + SIZE_ACCOUNT_ID_VERSION + SIZE_ACCOUNT_ID_PAYLOAD, 
                accountId.payload);
    std::copy(decodedInBase32 + SIZE_ACCOUNT_ID_VERSION + SIZE_ACCOUNT_ID_PAYLOAD, 
                decodedInBase32 + SIZE_ACCOUNT_ID_VERSION + SIZE_ACCOUNT_ID_PAYLOAD + SIZE_ACCOUNT_ID_CHECKSUM, 
                accountId.checksum);

    return accountId;
}

PublicKey TW::Stellar::GetPublicKeyFromHash(const char * publicKeyHash) {
    PublicKey publicKey = PublicKey{};
    TW::Stellar::AccountID accountId = DecodeAndDissectPublicKey(publicKeyHash);
    
    std::memcpy(publicKey.ed25519().data(), accountId.payload, sizeof(accountId.payload));

    return publicKey;
}

Operation TW::Stellar::CreatePaymentOperation(PublicKey const& to, int64_t amount)
{
    Operation op;

    op.body.type(PAYMENT);
    op.body.paymentOp().amount = amount;
    op.body.paymentOp().destination = to;
    op.body.paymentOp().asset.type(ASSET_TYPE_NATIVE);
    
    return op;
}

Memo TW::Stellar::CreateMemoText(const char * text) {
    Memo memo = Memo(stellar::MemoType::MEMO_TEXT);
    std::memcpy(memo.text().data(), text, std::strlen(text));
    return memo;
}
