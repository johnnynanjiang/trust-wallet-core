#include "Stellar.h"
#include "Constants.h"
#include "../trezor-crypto/include/TrezorCrypto/base32.h"

using namespace stellar;

std::string getString(uint8_t * charArray, int size) {
// TODO by jnj: is there a way to not pass size?
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

void decodePublicKey(const char * publicKeyHash, uint8_t * decodedInBase32, int size) {
    base32_decode(publicKeyHash, strlen(publicKeyHash), decodedInBase32, size, BASE32_ALPHABET_RFC4648);    
}

void decodeAndDissectPublicKey(const char * publicKeyHash, uint8_t version[], uint8_t payload[], uint8_t checksum[]) {
    uint8_t decodedInBase32[SIZE_ENCODED_PUBLIC_KEY] = {};
    int sizeOfDecodedInBase32 = sizeof(decodedInBase32);

    decodePublicKey(publicKeyHash, decodedInBase32, sizeOfDecodedInBase32);

    std::copy(decodedInBase32, decodedInBase32 + SIZE_VERSION, version);
    std::copy(decodedInBase32 + SIZE_VERSION, decodedInBase32 + SIZE_VERSION + SIZE_PAYLOAD, payload);
    std::copy(decodedInBase32 + SIZE_VERSION + SIZE_PAYLOAD, decodedInBase32 + SIZE_VERSION + SIZE_PAYLOAD + SIZE_CHECKSUM, checksum);
}