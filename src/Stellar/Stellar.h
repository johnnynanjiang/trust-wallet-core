#ifndef TW_STELLAR_H
#define TW_STELLAR_H

#include <string>
#include <TrustWalletCore/TWHDWallet.h>
#include "../../src/Data.h"
#include "xdr/Stellar-transaction.h"

using namespace stellar;

namespace TW {
namespace Stellar {

const char NULL_TERMINATOR = '\0';

/* Utils */
std::string GetString(uint8_t * charArray, int size);
TW::Data GetDataFromInt(int number);
TW::Data GetDataFromLong(long number);

#define FROMHEX_MAXLEN 512
const uint8_t *fromhex(const char *str);

/* Stellar specific */
const uint32_t VERSION_ACCOUNT_ID = 6 << 3;
const uint32_t VERSION_SEED = 18 << 3;
const uint32_t VERSION_SHA256_HASH = 23 << 3;

const uint32_t SIZE_STELLAR_KEY_VERSION = 1;
const uint32_t SIZE_STELLAR_KEY_PAYLOAD = 32;
const uint32_t SIZE_STELLAR_KEY_CHECKSUM = 2;
const uint32_t SIZE_ENCODED_STELLAR_KEY = 35;

const uint32_t ENVELOPE_TYPE_SCP = 1;
const uint32_t ENVELOPE_TYPE_TX = 2;
const uint32_t ENVELOPE_TYPE_AUTH = 3;

struct StellarKey {
    uint8_t version[SIZE_STELLAR_KEY_VERSION];
    uint8_t payload[SIZE_STELLAR_KEY_PAYLOAD];
    uint8_t checksum[SIZE_STELLAR_KEY_CHECKSUM];
};

void DecodeStellarKey(const char * stellarKeyHash, uint8_t * decodedInBase32, int size);
StellarKey DecodeAndDissectStellarKey(const char * stellarKeyHash);
PublicKey GetPublicKeyFromHash(const char * publicKeyHash);
Operation CreatePaymentOperation(PublicKey const& to, int64_t amount);
Memo CreateMemoText(const char * text);

}
}

#endif