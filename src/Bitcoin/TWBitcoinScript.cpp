// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWBitcoinOpCodes.h>
#include <TrustWalletCore/TWHash.h>
#include "TWBinaryCoding.h"

#include <vector>

struct TWBitcoinScript {
    std::vector<uint8_t> bytes;
};

struct TWBitcoinScript *TWBitcoinScriptCreate(struct TWData data) {
    auto script = new TWBitcoinScript{};
    script->bytes.resize(data.len);
    std::copy(data.bytes, data.bytes + data.len, std::begin(script->bytes));
    return script;
}

void TWBitcoinScriptDelete(struct TWBitcoinScript *script) {
    delete script;
}

size_t TWBitcoinScriptSize(struct TWBitcoinScript *script) {
    return script->bytes.size();
}

size_t TWBitcoinScriptData(struct TWBitcoinScript *script, uint8_t *_Nullable result) {
    if (result == nullptr)
        return script->bytes.size();
    std::copy(std::begin(script->bytes), std::end(script->bytes), result);
    return script->bytes.size();
}

size_t TWBitcoinScriptScriptHash(struct TWBitcoinScript *_Nonnull script, uint8_t result[20]) {
    uint8_t sha[32];
    struct TWData input = { .bytes = &(script->bytes[0]), .len = script->bytes.size() };
    TWHashSHA256(input, sha);

    struct TWData intermediate = { .bytes = sha, .len = 32 };
    TWHashRIPEMD(intermediate, result);

    return 20;
}

bool TWBitcoinScriptIsPayToScriptHash(struct TWBitcoinScript *script) {
    // Extra-fast test for pay-to-script-hash
    return script->bytes.size() == 23 &&
        script->bytes[0] == OP_HASH160 &&
        script->bytes[1] == 0x14 &&
        script->bytes[22] == OP_EQUAL;
}

bool TWBitcoinScriptIsPayToWitnessScriptHash(struct TWBitcoinScript *script) {
    // Extra-fast test for pay-to-witness-script-hash
    return script->bytes.size() == 22 &&
        script->bytes[0] == OP_0 &&
        script->bytes[1] == 0x14;
}

bool TWBitcoinScriptIsWitnessProgram(struct TWBitcoinScript *script) {
    if (script->bytes.size() < 4 || script->bytes.size() > 42) {
        return false;
    }
    if (script->bytes[0] != OP_0 && (script->bytes[0] < OP_1 || script->bytes[0] > OP_16)) {
        return false;
    }
    return script->bytes[1] + 2 == script->bytes.size();
}

uint8_t TWBitcoinScriptEncodeNumber(int value) {
    assert(value >= 0 && value <= 16);
    if (value == 0) {
        return OP_0;
    }
    return OP_1 + uint8_t(value - 1);
}

int TWBitcoinScriptDecodeNumber(uint8_t opcode) {
    if (opcode == OP_0) {
        return 0;
    }
    assert(opcode >= OP_1 && opcode <= OP_16);
    return (int)(opcode) - (int)(OP_1 - 1);
}

size_t TWBitcoinScriptMatchPayToPubkey(struct TWBitcoinScript *script, uint8_t result[TWPublicKeyUncompressedSize]) {
    if (script->bytes.size() == TWPublicKeyUncompressedSize + 2 && script->bytes[0] == TWPublicKeyUncompressedSize && script->bytes.back() == OP_CHECKSIG) {
        std::copy(std::begin(script->bytes) + 1, std::begin(script->bytes) + TWPublicKeyUncompressedSize + 1, result);
        return TWPublicKeyUncompressedSize;
    }
    if (script->bytes.size() == TWPublicKeyCompressedSize + 2 && script->bytes[0] == TWPublicKeyCompressedSize && script->bytes.back() == OP_CHECKSIG) {
        std::copy(std::begin(script->bytes) + 1, std::begin(script->bytes) + TWPublicKeyCompressedSize + 1, result);
        return TWPublicKeyCompressedSize;
    }
    return 0;
}

size_t TWBitcoinScriptMatchPayToPubkeyHash(struct TWBitcoinScript *script, uint8_t *_Nullable result) {
    if (script->bytes.size() == 25 && script->bytes[0] == OP_DUP && script->bytes[1] == OP_HASH160 && script->bytes[2] == 20 && script->bytes[23] == OP_EQUALVERIFY && script->bytes[24] == OP_CHECKSIG) {
        std::copy(std::begin(script->bytes) + 3, std::begin(script->bytes) + 23, result);
        return 20;
    }
    return 0;
}

size_t TWBitcoinScriptMatchPayToScriptHash(struct TWBitcoinScript *script, uint8_t *_Nullable result) {
    if (!TWBitcoinScriptIsPayToScriptHash(script)) {
        return 0;
    }
    std::copy(std::begin(script->bytes) + 2, std::begin(script->bytes) + 22, result);
    return 20;
}

size_t TWBitcoinScriptMatchPayToWitnessPublicKeyHash(struct TWBitcoinScript *script, uint8_t *_Nullable result) {
    if (script->bytes.size() == 22 && script->bytes[0] == OP_0 && script->bytes[1] == 0x14) {
        std::copy(std::begin(script->bytes) + 2, std::end(script->bytes), result);
        return script->bytes.size() - 2;
    }
    return 0;
}

size_t TWBitcoinScriptMatchPayToWitnessScriptHash(struct TWBitcoinScript *script, uint8_t *_Nullable result) {
    if (script->bytes.size() == 34 && script->bytes[0] == OP_0 && script->bytes[1] == 0x20) {
        std::copy(std::begin(script->bytes) + 2, std::end(script->bytes), result);
        return script->bytes.size() - 2;
    }
    return 0;
}

size_t TWBitcoinScriptEncode(struct TWBitcoinScript *script, uint8_t *_Nullable result) {
    size_t offset = TWWriteCompactSize(script->bytes.size(), result);
    if (result != nullptr) {
        std::copy(std::begin(script->bytes), std::end(script->bytes), result + offset);
    }
    return offset + script->bytes.size();
}

struct TWBitcoinScript *TWBitcoinScriptBuildPayToPublicKeyHash(struct TWData hash) {
    assert(hash.len == 20);
    uint8_t data[25];
    data[0] = OP_DUP;
    data[1] = OP_HASH160;
    data[2] = 20;
    std::copy(hash.bytes, hash.bytes + hash.len, data + 3);
    data[23] = OP_EQUALVERIFY;
    data[24] = OP_CHECKSIG;
    return TWBitcoinScriptCreate({ .bytes = data, .len = 25 });
}

struct TWBitcoinScript *TWBitcoinScriptBuildPayToScriptHash(struct TWData scriptHash) {
    assert(scriptHash.len == 20);
    uint8_t data[23];
    data[0] = OP_HASH160;
    data[1] = 20;
    std::copy(scriptHash.bytes, scriptHash.bytes + scriptHash.len, data + 2);
    data[22] = OP_EQUAL;
    return TWBitcoinScriptCreate({ .bytes = data, .len = 23 });
}

struct TWBitcoinScript *TWBitcoinScriptBuildPayToWitnessPubkeyHash(struct TWData hash) {
    assert(hash.len == 20);
    uint8_t data[22];
    data[0] = OP_0;
    data[1] = 20;
    std::copy(hash.bytes, hash.bytes + 20, data + 2);
    return TWBitcoinScriptCreate({ .bytes = data, .len = 22 });
}

struct TWBitcoinScript *TWBitcoinScriptBuildPayToWitnessScriptHash(struct TWData scriptHash) {
    assert(scriptHash.len == 32);
    uint8_t data[34];
    data[0] = OP_0;
    data[1] = 32;
    std::copy(scriptHash.bytes, scriptHash.bytes + scriptHash.len, data + 2);
    return TWBitcoinScriptCreate({ .bytes = data, .len = 34 });
}
