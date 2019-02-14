#ifndef TW_STELLAR_H
#define TW_STELLAR_H

#include <string>
#include "xdr/Stellar-transaction.h"

using namespace stellar;

namespace TW {
namespace Stellar {

const uint32_t VERSION_ACCOUNT_ID = 6 << 3;
const uint32_t VERSION_SEED = 18 << 3;
const uint32_t VERSION_SHA256_HASH = 23 << 3;

const uint32_t SIZE_ACCOUNT_ID_VERSION = 1;
const uint32_t SIZE_ACCOUNT_ID_PAYLOAD = 32;
const uint32_t SIZE_ACCOUNT_ID_CHECKSUM = 2;
const uint32_t SIZE_ENCODED_PUBLIC_KEY = 35;

const uint32_t ENVELOPE_TYPE_SCP = 1;
const uint32_t ENVELOPE_TYPE_TX = 2;
const uint32_t ENVELOPE_TYPE_AUTH = 3;

std::string getString(uint8_t * charArray, int size);

struct AccountID {
    uint8_t version[SIZE_ACCOUNT_ID_VERSION];
    uint8_t payload[SIZE_ACCOUNT_ID_PAYLOAD];
    uint8_t checksum[SIZE_ACCOUNT_ID_CHECKSUM];
};

void decodePublicKey(const char * publicKeyHash, uint8_t * decodedInBase32, int size);

AccountID decodeAndDissectPublicKey(const char * publicKeyHash);

PublicKey getPublicKeyFromHash(const char * publicKeyHash);

Operation createPaymentOperation(PublicKey const& to, int64_t amount);

}
}

#endif