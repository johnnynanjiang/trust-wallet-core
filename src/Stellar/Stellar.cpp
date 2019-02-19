#include "../trezor-crypto/include/TrezorCrypto/base32.h"
#include "Stellar.h"

using namespace TW::Stellar;
using namespace stellar;

/* Utils */
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

const uint8_t * TW::Stellar::fromhex(const char *str)
{
	static uint8_t buf[FROMHEX_MAXLEN];
	size_t len = strlen(str) / 2;
	if (len > FROMHEX_MAXLEN) len = FROMHEX_MAXLEN;
	for (size_t i = 0; i < len; i++) {
		uint8_t c = 0;
		if (str[i * 2] >= '0' && str[i*2] <= '9') c += (str[i * 2] - '0') << 4;
		if ((str[i * 2] & ~0x20) >= 'A' && (str[i*2] & ~0x20) <= 'F') c += (10 + (str[i * 2] & ~0x20) - 'A') << 4;
		if (str[i * 2 + 1] >= '0' && str[i * 2 + 1] <= '9') c += (str[i * 2 + 1] - '0');
		if ((str[i * 2 + 1] & ~0x20) >= 'A' && (str[i * 2 + 1] & ~0x20) <= 'F') c += (10 + (str[i * 2 + 1] & ~0x20) - 'A');
		buf[i] = c;
	}
	return buf;
}

/* Stellar specific */
void TW::Stellar::DecodeStellarKey(const char * stellarcKeyHash, uint8_t * decodedInBase32, int size) {
    base32_decode(stellarcKeyHash, strlen(stellarcKeyHash), decodedInBase32, size, BASE32_ALPHABET_RFC4648);    
}

TW::Stellar::StellarKey TW::Stellar::DecodeAndDissectStellarKey(const char * stellarcKeyHash) {
    uint8_t decodedInBase32[SIZE_ENCODED_STELLAR_KEY] = {};

    TW::Stellar::DecodeStellarKey(stellarcKeyHash, decodedInBase32, sizeof(decodedInBase32));

    StellarKey stellarKey;

    std::copy(decodedInBase32, 
                decodedInBase32 + SIZE_STELLAR_KEY_VERSION, 
                stellarKey.version);
    std::copy(decodedInBase32 + SIZE_STELLAR_KEY_VERSION, 
                decodedInBase32 + SIZE_STELLAR_KEY_VERSION + SIZE_STELLAR_KEY_PAYLOAD, 
                stellarKey.payload);
    std::copy(decodedInBase32 + SIZE_STELLAR_KEY_VERSION + SIZE_STELLAR_KEY_PAYLOAD, 
                decodedInBase32 + SIZE_STELLAR_KEY_VERSION + SIZE_STELLAR_KEY_PAYLOAD + SIZE_STELLAR_KEY_CHECKSUM, 
                stellarKey.checksum);

    return stellarKey;
}

PublicKey TW::Stellar::GetPublicKeyFromHash(const char * publicKeyHash) {
    PublicKey publicKey = PublicKey{};
    TW::Stellar::StellarKey accountId = DecodeAndDissectStellarKey(publicKeyHash);
    
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
