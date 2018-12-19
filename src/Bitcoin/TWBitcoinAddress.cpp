// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinAddress.h>

#include <TrustWalletCore/TWPublicKey.h>
#include <TrezorCrypto/base58.h>
#include <TrezorCrypto/ecdsa.h>

#include <string.h>
#include <vector>

static const size_t dataSize = 21;

bool TWBitcoinAddressEqual(struct TWBitcoinAddress lhs, struct TWBitcoinAddress rhs) {
    return memcmp(lhs.bytes, rhs.bytes, dataSize) == 0;
}

bool TWBitcoinAddressIsValid(TWData *_Nonnull data) {
    return TWDataSize(data) == dataSize;
}

bool TWBitcoinAddressInitWithString(struct TWBitcoinAddress *_Nonnull address, TWString *_Nonnull string) {
    auto str = TWStringUTF8Bytes(string);

    size_t capacity = 128;
    uint8_t buffer[capacity];

    int size = base58_decode_check(str, HASHER_SHA2D, buffer, (int)capacity);
    if (size != dataSize) {
        return false;
    }

    memcpy(address->bytes, buffer, dataSize);
    return true;
}

bool TWBitcoinAddressInitWithData(struct TWBitcoinAddress *_Nonnull address, TWData *_Nonnull data) {
    if (TWDataSize(data) != dataSize) {
        return false;
    }
    TWDataCopyBytes(data, 0, dataSize, address->bytes);
    return true;
}

bool TWBitcoinAddressInitWithPublicKey(struct TWBitcoinAddress *_Nonnull address, struct TWPublicKey publicKey, uint8_t prefix) {
    address->bytes[0] = prefix;

    auto compressed = TWPublicKeyCompressed(publicKey);
    ecdsa_get_pubkeyhash(compressed.bytes, HASHER_SHA2_RIPEMD,  address->bytes + 1);

    return true;
}

TWString *_Nonnull TWBitcoinAddressDescription(struct TWBitcoinAddress address) {
    size_t size = 0;
    b58enc(nullptr, &size, address.bytes, dataSize);
    size += 16;

    std::vector<char> str(size);
    base58_encode_check(address.bytes, dataSize, HASHER_SHA2D, str.data(), size);

    return TWStringCreateWithUTF8Bytes(str.data());
}

TWData *_Nonnull TWBitcoinAddressData(struct TWBitcoinAddress address) {
    return TWDataCreateWithBytes(address.bytes, dataSize);
}
