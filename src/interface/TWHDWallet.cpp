// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWHDWallet.h>

extern "C" {
#include <TrezorCrypto/bip32.h>
#include <TrezorCrypto/bip39.h>
#include <TrezorCrypto/curves.h>
}

#include <algorithm>
#include <string>

static const size_t TWHDSeedSize = 64;

struct TWHDWallet {
    /// Wallet seed.
    uint8_t seed[TWHDSeedSize];

    /// Mnemonic word list.
    std::string mnemonic;

    /// Mnemonic passphrase.
    std::string passphrase;
};

static HDNode getNode(struct TWHDWallet *_Nonnull wallet, uint32_t purpose, uint32_t coin);
static HDNode getNode(struct TWHDWallet *_Nonnull wallet, uint32_t purpose, uint32_t coin, uint32_t account, uint32_t change, uint32_t address);
static HDNode getMasterNode(struct TWHDWallet *_Nonnull wallet);

struct TWHDWallet *_Nonnull TWHDWalletCreate(int strength, TWString *_Nonnull passphrase) {
    auto wallet = new TWHDWallet{};
    auto mnemonic = mnemonic_generate(strength);
    mnemonic_to_seed(mnemonic, TWStringUTF8Bytes(passphrase), wallet->seed, NULL);
    wallet->mnemonic = mnemonic;
    wallet->passphrase = TWStringUTF8Bytes(passphrase);
    return wallet;
}

struct TWHDWallet *_Nonnull TWHDWalletCreateWithMnemonic(TWString *_Nonnull mnemonic, TWString *_Nonnull passphrase) {
    auto wallet = new TWHDWallet{};
    mnemonic_to_seed(TWStringUTF8Bytes(mnemonic), TWStringUTF8Bytes(passphrase), wallet->seed, NULL);
    wallet->mnemonic = TWStringUTF8Bytes(mnemonic);
    wallet->passphrase = TWStringUTF8Bytes(passphrase);
    return wallet;
}

struct TWHDWallet *_Nonnull TWHDWalletCreateWithData(TWData *_Nonnull data, TWString *_Nonnull passphrase) {
    auto wallet = new TWHDWallet{};
    auto mnemonic = mnemonic_from_data(TWDataBytes(data), TWDataSize(data));
    mnemonic_to_seed(mnemonic, TWStringUTF8Bytes(passphrase), wallet->seed, NULL);
    wallet->mnemonic = TWStringUTF8Bytes(mnemonic);
    wallet->passphrase = TWStringUTF8Bytes(passphrase);
    return wallet;
}

void TWHDWalletDelete(struct TWHDWallet *wallet) {
    std::fill(wallet->seed, wallet->seed + 64, 0);
    std::fill(std::begin(wallet->mnemonic), std::end(wallet->mnemonic), 0);
    std::fill(std::begin(wallet->passphrase), std::end(wallet->passphrase), 0);
    delete wallet;
}

TWData *_Nonnull TWHDWalletSeed(struct TWHDWallet *_Nonnull wallet) {
    return TWDataCreateWithBytes(wallet->seed, TWHDSeedSize);
}

TWString *_Nonnull TWHDWalletMnemonic(struct TWHDWallet *_Nonnull wallet){
    return TWStringCreateWithUTF8Bytes(wallet->mnemonic.c_str());
}

struct TWPrivateKey *_Nonnull TWHDWalletGetKey(struct TWHDWallet *wallet, uint32_t purpose, uint32_t coin, uint32_t account, uint32_t change, uint32_t address) {
    auto node = getNode(wallet, purpose, coin, account, change, address);
    auto data = TWDataCreateWithBytes(node.private_key, TWPrivateKeySize);
    auto pk = TWPrivateKeyCreateWithData(data);
    TWDataDelete(data);
    return pk;
}

TWString *_Nonnull TWHDWalletGetExtendedPrivateKey(struct TWHDWallet *wallet, uint32_t purpose, uint32_t coin, uint32_t version) {
    auto node = getNode(wallet, purpose, coin);
    char buffer[128] = {0};
    auto fingerprint = hdnode_fingerprint(&node);
    hdnode_private_ckd(&node, 0x80000000);
    hdnode_serialize_private(&node, fingerprint, version, buffer, 128);
    return TWStringCreateWithUTF8Bytes(buffer);
}

TWString *_Nonnull TWHDWalletGetExtendedPublicKey(struct TWHDWallet *wallet, uint32_t purpose, uint32_t coin, uint32_t version) {
    auto node = getNode(wallet, purpose, coin);
    char buffer[128] = {0};
    auto fingerprint = hdnode_fingerprint(&node);
    hdnode_private_ckd(&node, 0x80000000);
    hdnode_fill_public_key(&node);
    hdnode_serialize_public(&node, fingerprint, version, buffer, 128);
    return TWStringCreateWithUTF8Bytes(buffer);
}

TWPublicKey TWHDWalletGetPublicKeyFromExtended(TWString *_Nonnull extended, uint32_t versionPublic, uint32_t versionPrivate, uint32_t change, uint32_t address) {
    auto node = HDNode{};
    uint32_t fingerprint = 0;

    hdnode_deserialize(TWStringUTF8Bytes(extended), versionPublic, versionPrivate, SECP256K1_NAME, &node, &fingerprint);
    hdnode_public_ckd(&node, change);
    hdnode_public_ckd(&node, address);
    hdnode_fill_public_key(&node);

    auto pk = TWPublicKey{};
    auto data = TWDataCreateWithBytes(node.public_key, TWPublicKeyCompressedSize);
    TWPublicKeyInitWithData(&pk, data);
    TWDataDelete(data);

    return pk;
}

HDNode getNode(struct TWHDWallet *wallet, uint32_t purpose, uint32_t coin) {
    auto node = getMasterNode(wallet);
    hdnode_private_ckd(&node, purpose | 0x80000000);
    hdnode_private_ckd(&node, coin | 0x80000000);
    return node;
}

HDNode getNode(struct TWHDWallet *wallet, uint32_t purpose, uint32_t coin, uint32_t account, uint32_t change, uint32_t address) {
    auto node = getMasterNode(wallet);
    hdnode_private_ckd(&node, purpose | 0x80000000);
    hdnode_private_ckd(&node, coin | 0x80000000);
    hdnode_private_ckd(&node, account | 0x80000000);
    hdnode_private_ckd(&node, change);
    hdnode_private_ckd(&node, address);
    return node;
}

HDNode getMasterNode(struct TWHDWallet *wallet) {
    auto node = HDNode();
    hdnode_from_seed(wallet->seed, TWHDSeedSize, SECP256K1_NAME, &node);
    return node;
}
