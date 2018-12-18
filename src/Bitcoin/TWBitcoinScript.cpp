// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWBitcoinOpCodes.h>
#include <TrustWalletCore/TWHash.h>
#include <TrustWalletCore/TWString.h>

#include <TrezorCrypto/ripemd160.h>
#include <TrezorCrypto/sha2.h>
#include <TrezorCrypto/sha3.h>

#include "TWBinaryCoding.h"

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

struct TWBitcoinScript *_Nonnull TWBitcoinScriptCreateWithBytes(uint8_t *_Nonnull bytes, size_t size) {
    auto script = new TWBitcoinScript{};
    std::copy(bytes, bytes + size, std::back_inserter(script->bytes));
    return script;
}

struct TWBitcoinScript *TWBitcoinScriptCreateCopy(const struct TWBitcoinScript *script) {
    auto newScript = new TWBitcoinScript{};
    newScript->bytes = script->bytes;
    return newScript;
}

void TWBitcoinScriptDelete(struct TWBitcoinScript *script) {
    delete script;
}

size_t TWBitcoinScriptSize(const struct TWBitcoinScript *script) {
    return script->bytes.size();
}

TWData *TWBitcoinScriptData(const struct TWBitcoinScript *script) {
    return TWDataCreateWithBytes(&script->bytes[0], script->bytes.size());
}

TWData *TWBitcoinScriptScriptHash(const struct TWBitcoinScript *_Nonnull script) {
    TWData *input = TWBitcoinScriptData(script);
    TWData *sha = TWHashSHA256(input);
    return TWHashRIPEMD(sha);
}

bool TWBitcoinScriptIsPayToScriptHash(const struct TWBitcoinScript *script) {
    // Extra-fast test for pay-to-script-hash
    return script->bytes.size() == 23 &&
        script->bytes[0] == OP_HASH160 &&
        script->bytes[1] == 0x14 &&
        script->bytes[22] == OP_EQUAL;
}

bool TWBitcoinScriptIsPayToWitnessScriptHash(const struct TWBitcoinScript *script) {
    // Extra-fast test for pay-to-witness-script-hash
    return script->bytes.size() == 22 &&
        script->bytes[0] == OP_0 &&
        script->bytes[1] == 0x14;
}

bool TWBitcoinScriptIsWitnessProgram(const struct TWBitcoinScript *script) {
    if (script->bytes.size() < 4 || script->bytes.size() > 42) {
        return false;
    }
    if (script->bytes[0] != OP_0 && (script->bytes[0] < OP_1 || script->bytes[0] > OP_16)) {
        return false;
    }
    return script->bytes[1] + 2 == script->bytes.size();
}

bool TWBitcoinScriptEqual(const struct TWBitcoinScript *_Nonnull lhs, const struct TWBitcoinScript *_Nonnull rhs) {
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

TWData *TWBitcoinScriptMatchPayToPubkey(const struct TWBitcoinScript *script) {
    if (script->bytes.size() == TWPublicKeyUncompressedSize + 2 && script->bytes[0] == TWPublicKeyUncompressedSize && script->bytes.back() == OP_CHECKSIG) {
        return TWDataCreateWithBytes(&script->bytes[1], TWPublicKeyUncompressedSize);
    }
    if (script->bytes.size() == TWPublicKeyCompressedSize + 2 && script->bytes[0] == TWPublicKeyCompressedSize && script->bytes.back() == OP_CHECKSIG) {
        return TWDataCreateWithBytes(&script->bytes[1], TWPublicKeyCompressedSize);
    }
    return 0;
}

TWData *TWBitcoinScriptMatchPayToPubkeyHash(const struct TWBitcoinScript *script) {
    if (script->bytes.size() == 25 && script->bytes[0] == OP_DUP && script->bytes[1] == OP_HASH160 && script->bytes[2] == 20 && script->bytes[23] == OP_EQUALVERIFY && script->bytes[24] == OP_CHECKSIG) {
        return TWDataCreateWithBytes(&script->bytes[3], 20);
    }
    return 0;
}

TWData *_Nullable TWBitcoinScriptMatchPayToScriptHash(const struct TWBitcoinScript *script) {
    if (!TWBitcoinScriptIsPayToScriptHash(script)) {
        return nullptr;
    }
    TWData *result = TWDataCreateWithSize(20);
    TWDataReplaceBytes(result, 0, 20, &script->bytes[0]);
    return result;
}

TWData *_Nullable TWBitcoinScriptMatchPayToWitnessPublicKeyHash(const struct TWBitcoinScript *script) {
    if (script->bytes.size() == 22 && script->bytes[0] == OP_0 && script->bytes[1] == 0x14) {
        TWData *result = TWDataCreateWithSize(script->bytes.size() - 2);
        TWDataReplaceBytes(result, 0, TWDataSize(result), &script->bytes[2]);
        return result;
    }
    return nullptr;
}

TWData *_Nullable TWBitcoinScriptMatchPayToWitnessScriptHash(const struct TWBitcoinScript *script) {
    if (script->bytes.size() == 34 && script->bytes[0] == OP_0 && script->bytes[1] == 0x20) {
        TWData *result = TWDataCreateWithSize(script->bytes.size() - 2);
        TWDataReplaceBytes(result, 0, TWDataSize(result), &script->bytes[2]);
        return result;
    }
    return 0;
}

TWData *TWBitcoinScriptEncode(const struct TWBitcoinScript *script) {
    auto result = std::vector<uint8_t>{};
    script->encode(result);
    return TWDataCreateWithBytes(result.data(), result.size());
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

bool TWBitcoinScript::isPayToScriptHash() const {
    // Extra-fast test for pay-to-script-hash
    return bytes.size() == 23 &&
        bytes[0] == OP_HASH160 &&
        bytes[1] == 0x14 &&
        bytes[22] == OP_EQUAL;
}

bool TWBitcoinScript::isPayToWitnessScriptHash() const {
    // Extra-fast test for pay-to-witness-script-hash
    return bytes.size() == 22 &&
        bytes[0] == OP_0 &&
        bytes[1] == 0x14;
}

bool TWBitcoinScript::isWitnessProgram() const {
    if (bytes.size() < 4 || bytes.size() > 42) {
        return false;
    }
    if (bytes[0] != OP_0 && (bytes[0] < OP_1 || bytes[0] > OP_16)) {
        return false;
    }
    return bytes[1] + 2 == bytes.size();
}

bool TWBitcoinScript::matchPayToPubkey(std::vector<uint8_t>& result) const {
    if (bytes.size() == TWPublicKeyUncompressedSize + 2 && bytes[0] == TWPublicKeyUncompressedSize && bytes.back() == OP_CHECKSIG) {
        result.clear();
        std::copy(std::begin(bytes) + 1, std::begin(bytes) + 1 + TWPublicKeyUncompressedSize, std::back_inserter(result));
        return true;
    }
    if (bytes.size() == TWPublicKeyCompressedSize + 2 && bytes[0] == TWPublicKeyCompressedSize && bytes.back() == OP_CHECKSIG) {
        result.clear();
        std::copy(std::begin(bytes) + 1, std::begin(bytes) + 1 + TWPublicKeyCompressedSize, std::back_inserter(result));
        return true;
    }
    return false;
}

bool TWBitcoinScript::matchPayToPubkeyHash(std::vector<uint8_t>& result) const {
    if (bytes.size() == 25 && bytes[0] == OP_DUP && bytes[1] == OP_HASH160 && bytes[2] == 20 && bytes[23] == OP_EQUALVERIFY && bytes[24] == OP_CHECKSIG) {
        result.clear();
        std::copy(std::begin(bytes) + 3, std::begin(bytes) + 3 + 20, std::back_inserter(result));
        return true;
    }
    return false;
}

bool TWBitcoinScript::matchPayToScriptHash(std::vector<uint8_t>& result) const {
    if (!isPayToScriptHash()) {
        return false;
    }
    result.clear();
    std::copy(std::begin(bytes) + 2, std::begin(bytes) + 22, std::back_inserter(result));
    return true;
}

bool TWBitcoinScript::matchPayToWitnessPublicKeyHash(std::vector<uint8_t>& result) const {
    if (bytes.size() == 22 && bytes[0] == OP_0 && bytes[1] == 0x14) {
        result.clear();
        std::copy(std::begin(bytes) + 2, std::end(bytes), std::back_inserter(result));
        return true;
    }
    return false;
}

bool TWBitcoinScript::matchPayToWitnessScriptHash(std::vector<uint8_t>& result) const {
    if (bytes.size() == 34 && bytes[0] == OP_0 && bytes[1] == 0x20) {
        result.clear();
        std::copy(std::begin(bytes) + 2, std::end(bytes), std::back_inserter(result));
        return true;
    }
    return false;
}

/// Decodes a small integer
static inline int decodeNumber(uint8_t opcode) {
    if (opcode == OP_0) {
        return 0;
    }
    assert(opcode >= OP_1 && opcode <= OP_16);
    return static_cast<int>(opcode) - static_cast<int>(OP_1 - 1);
}

bool TWBitcoinScript::matchMultisig(std::vector<std::vector<uint8_t>>& keys, int& required) const {
    keys.clear();
    required = 0;
    
    if (bytes.size() < 1 || bytes.back() != OP_CHECKMULTISIG) {
        return false;
    }

    size_t it = 0;
    uint8_t opcode;
    std::vector<uint8_t> operand;

    auto op = getScriptOp(it, opcode, operand);
    if (!op || !TWOpCodeIsSmallInteger(opcode)) {
        return false;
    }
    required = decodeNumber(opcode);
    while (true) {
        auto res = getScriptOp(it, opcode, operand);
        if (!res) {
            break;
        }
        if (!TW::PublicKey::isValid(operand)) {
            break;
        }
        keys.push_back(operand);
    }

    if (!TWOpCodeIsSmallInteger(opcode)) {
        return false;
    }

    auto expectedCount = decodeNumber(opcode);
    if (keys.size() != expectedCount || expectedCount < required) {
        return false;
    }
    if (it + 1 != bytes.size()) {
        return false;
    }

    return true;
}

bool TWBitcoinScript::getScriptOp(size_t& index, uint8_t& opcode, std::vector<uint8_t>& operand) const {
    operand.clear();

    // Read instruction
    if (index >= bytes.size()) {
        return false;
    }

    opcode = bytes[index];
    index += 1;

    if (opcode > OP_PUSHDATA4) {
        return true;
    }

    // Immediate operand
    auto size = 0;
    if (opcode < OP_PUSHDATA1) {
        size = static_cast<size_t>(opcode);
    } else if (opcode == OP_PUSHDATA1) {
        if (bytes.size() - index < 1) {
            return false;
        }
        size = index;
        index += 1;
    } else if (opcode == OP_PUSHDATA2) {
        if (bytes.size() - index < 2) {
            return false;
        }
        size = static_cast<size_t>(decode16(bytes.data() + index));
        index += 2;
    } else if (opcode == OP_PUSHDATA4) {
        if (bytes.size() - index < 4) {
            return false;
        }
        size = static_cast<size_t>(decode32(bytes.data() + index));
        index += 4;
    }
    if (bytes.size() - index < size) {
        return false;
    }
    operand = std::vector<uint8_t>(bytes.begin() + index, bytes.begin() + index + size);
    index += size;

    return true;
}

TWBitcoinScript TWBitcoinScript::buildPayToPublicKeyHash(const std::vector<uint8_t>& hash) {
    assert(hash.size() == 20);
    TWBitcoinScript script;
    script.bytes.push_back(OP_DUP);
    script.bytes.push_back(OP_HASH160);
    script.bytes.push_back(20);
    script.bytes.insert(script.bytes.end(), hash.begin(), hash.end());
    script.bytes.push_back(OP_EQUALVERIFY);
    script.bytes.push_back(OP_CHECKSIG);
    return script;
}

TWBitcoinScript TWBitcoinScript::buildPayToScriptHash(const std::vector<uint8_t>& scriptHash) {
    assert(scriptHash.size() == 20);
    TWBitcoinScript script;
    script.bytes.push_back(OP_HASH160);
    script.bytes.push_back(20);
    script.bytes.insert(script.bytes.end(), scriptHash.begin(), scriptHash.end());
    script.bytes.push_back(OP_EQUAL);
    return script;
}

TWBitcoinScript TWBitcoinScript::buildPayToWitnessPubkeyHashRaw(const std::vector<uint8_t>& hash) {
    assert(hash.size() == 20);
    TWBitcoinScript script;
    script.bytes.push_back(OP_0);
    script.bytes.push_back(20);
    script.bytes.insert(script.bytes.end(), hash.begin(), hash.end());
    return script;
}

TWBitcoinScript TWBitcoinScript::buildPayToWitnessScriptHash(const std::vector<uint8_t>& scriptHash) {
    assert(scriptHash.size() == 32);
    TWBitcoinScript script;
    script.bytes.push_back(OP_0);
    script.bytes.push_back(32);
    script.bytes.insert(script.bytes.end(), scriptHash.begin(), scriptHash.end());
    return script;
}


void TWBitcoinScript::encode(std::vector<uint8_t>& data) const {
    TWWriteCompactSize(bytes.size(), data);
    std::copy(std::begin(bytes), std::end(bytes), std::back_inserter(data));
}
