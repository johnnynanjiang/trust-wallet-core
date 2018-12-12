// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWBitcoinOpCodes.h>
#include <TrustWalletCore/TWHash.h>
#include <TrustWalletCore/TWString.h>
#include "TWBinaryCoding.h"

#include <vector>

struct TWBitcoinScript {
    std::vector<uint8_t> bytes;
};

struct TWBitcoinScript *_Nonnull TWBitcoinScriptCreate() {
    auto script = new TWBitcoinScript{};
    return script;
}

struct TWBitcoinScript *TWBitcoinScriptCreateWithData(TWData *data) {
    auto script = new TWBitcoinScript{};
    script->bytes.resize(TWDataSize(data));
    TWDataCopyBytes(data, 0, TWDataSize(data), script->bytes.data());
    return script;
}

struct TWBitcoinScript *TWBitcoinScriptCreateCopy(struct TWBitcoinScript *script) {
    auto newScript = new TWBitcoinScript{};
    newScript->bytes = script->bytes;
    return newScript;
}

void TWBitcoinScriptDelete(struct TWBitcoinScript *script) {
    delete script;
}

size_t TWBitcoinScriptSize(struct TWBitcoinScript *script) {
    return script->bytes.size();
}

TWData *TWBitcoinScriptData(struct TWBitcoinScript *script) {
    return TWDataCreateWithBytes(&script->bytes[0], script->bytes.size());
}

TWData *TWBitcoinScriptScriptHash(struct TWBitcoinScript *_Nonnull script) {
    TWData *input = TWBitcoinScriptData(script);
    TWData *sha = TWHashSHA256(input);
    return TWHashRIPEMD(sha);
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

bool TWBitcoinScriptEqual(struct TWBitcoinScript *_Nonnull lhs, struct TWBitcoinScript *_Nonnull rhs) {
    return lhs->bytes == rhs->bytes;
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

TWData *TWBitcoinScriptMatchPayToPubkey(struct TWBitcoinScript *script) {
    if (script->bytes.size() == TWPublicKeyUncompressedSize + 2 && script->bytes[0] == TWPublicKeyUncompressedSize && script->bytes.back() == OP_CHECKSIG) {
        return TWDataCreateWithBytes(&script->bytes[1], TWPublicKeyUncompressedSize);
    }
    if (script->bytes.size() == TWPublicKeyCompressedSize + 2 && script->bytes[0] == TWPublicKeyCompressedSize && script->bytes.back() == OP_CHECKSIG) {
        return TWDataCreateWithBytes(&script->bytes[1], TWPublicKeyCompressedSize);
    }
    return 0;
}

TWData *TWBitcoinScriptMatchPayToPubkeyHash(struct TWBitcoinScript *script) {
    if (script->bytes.size() == 25 && script->bytes[0] == OP_DUP && script->bytes[1] == OP_HASH160 && script->bytes[2] == 20 && script->bytes[23] == OP_EQUALVERIFY && script->bytes[24] == OP_CHECKSIG) {
        return TWDataCreateWithBytes(&script->bytes[3], 20);
    }
    return 0;
}

TWData *_Nullable TWBitcoinScriptMatchPayToScriptHash(struct TWBitcoinScript *script) {
    if (!TWBitcoinScriptIsPayToScriptHash(script)) {
        return nullptr;
    }
    TWData *result = TWDataCreateWithSize(20);
    TWDataReplaceBytes(result, 0, 20, &script->bytes[0]);
    return result;
}

TWData *_Nullable TWBitcoinScriptMatchPayToWitnessPublicKeyHash(struct TWBitcoinScript *script) {
    if (script->bytes.size() == 22 && script->bytes[0] == OP_0 && script->bytes[1] == 0x14) {
        TWData *result = TWDataCreateWithSize(script->bytes.size() - 2);
        TWDataReplaceBytes(result, 0, TWDataSize(result), &script->bytes[2]);
        return result;
    }
    return nullptr;
}

TWData *_Nullable TWBitcoinScriptMatchPayToWitnessScriptHash(struct TWBitcoinScript *script) {
    if (script->bytes.size() == 34 && script->bytes[0] == OP_0 && script->bytes[1] == 0x20) {
        TWData *result = TWDataCreateWithSize(script->bytes.size() - 2);
        TWDataReplaceBytes(result, 0, TWDataSize(result), &script->bytes[2]);
        return result;
    }
    return 0;
}

TWData *TWBitcoinScriptEncode(struct TWBitcoinScript *script) {
    TWData *result = TWDataCreateWithSize(0);
    TWBitcoinScriptEncodeRaw(script, result);
    return result;
}

void TWBitcoinScriptEncodeRaw(struct TWBitcoinScript *_Nonnull script, TWData *_Nonnull data) {
    TWWriteCompactSize(script->bytes.size(), data);
    TWDataAppendBytes(data, &script->bytes[0], script->bytes.size());
}

struct TWBitcoinScript *TWBitcoinScriptBuildPayToPublicKeyHash(TWData *hash) {
    assert(TWDataSize(hash) == 20);
    auto data = TWDataCreateWithSize(25);
    TWDataSet(data, 0, OP_DUP);
    TWDataSet(data, 1, OP_HASH160);
    TWDataSet(data, 2, 20);
    uint8_t *hashBytes = TWDataBytes(hash);
    TWDataReplaceBytes(data, 3, TWDataSize(hash), hashBytes);
    TWDataSet(data, 23, OP_EQUALVERIFY);
    TWDataSet(data, 24, OP_CHECKSIG);
    return TWBitcoinScriptCreateWithData(data);
}

struct TWBitcoinScript *TWBitcoinScriptBuildPayToScriptHash(TWData *scriptHash) {
    assert(TWDataSize(scriptHash) == 20);
    auto data = TWDataCreateWithSize(23);
    TWDataSet(data, 0, OP_HASH160);
    TWDataSet(data, 1, 20);
    uint8_t *hashBytes = TWDataBytes(scriptHash);
    TWDataReplaceBytes(data, 2, TWDataSize(scriptHash), hashBytes);
    TWDataSet(data, 22, OP_EQUAL);
    return TWBitcoinScriptCreateWithData(data);
}

struct TWBitcoinScript *TWBitcoinScriptBuildPayToWitnessPubkeyHash(TWData *hash) {
    assert(TWDataSize(hash) == 20);
    auto data = TWDataCreateWithSize(22);
    TWDataSet(data, 0, OP_0);
    TWDataSet(data, 1, 20);
    uint8_t *hashBytes = TWDataBytes(hash);
    TWDataReplaceBytes(data, 2, TWDataSize(hash), hashBytes);
    return TWBitcoinScriptCreateWithData(data);
}

struct TWBitcoinScript *_Nonnull TWBitcoinScriptBuildPayToWitnessPubkeyHashRaw(const uint8_t *_Nonnull hash) {
    auto data = TWDataCreateWithSize(22);
    TWDataSet(data, 0, OP_0);
    TWDataSet(data, 1, 20);
    TWDataReplaceBytes(data, 2, 20, hash);
    auto script = TWBitcoinScriptCreateWithData(data);
    TWDataDelete(data);
    return script;
}

struct TWBitcoinScript *TWBitcoinScriptBuildPayToWitnessScriptHash(TWData *scriptHash) {
    assert(TWDataSize(scriptHash) == 32);
    auto data = TWDataCreateWithSize(34);
    TWDataSet(data, 0, OP_0);
    TWDataSet(data, 1, 32);
    uint8_t *hashBytes = TWDataBytes(scriptHash);
    TWDataReplaceBytes(data, 2, TWDataSize(scriptHash), hashBytes);
    return TWBitcoinScriptCreateWithData(data);
}
