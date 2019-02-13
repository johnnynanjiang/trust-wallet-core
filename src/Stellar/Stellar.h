#ifndef TRUST_STELLAR_H
#define TRUST_STELLAR_H

#include <string>
#include "Constants.h"

using namespace TW::Stellar;

namespace TW {
namespace Stellar {
std::string getString(uint8_t * charArray, int size);

struct AccountID {
    uint8_t version[SIZE_VERSION];
    uint8_t payload[SIZE_PAYLOAD];
    uint8_t checksum[SIZE_CHECKSUM];
};

void decodePublicKey(const char * publicKeyHash, uint8_t * decodedInBase32, int size);

AccountID decodeAndDissectPublicKey(const char * publicKeyHash);
}
}

#endif