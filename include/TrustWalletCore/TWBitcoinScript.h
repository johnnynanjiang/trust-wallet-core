// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"
#include "TWPublicKey.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_CLASS
struct TWBitcoinScript;

/// Creates an empty script.
TW_EXPORT_STATIC_METHOD
struct TWBitcoinScript *_Nonnull TWBitcoinScriptCreate();

/// Creates a script from a raw data representation.
TW_EXPORT_STATIC_METHOD
struct TWBitcoinScript *_Nonnull TWBitcoinScriptCreateWithData(TWData *_Nonnull data);
struct TWBitcoinScript *_Nonnull TWBitcoinScriptCreateWithBytes(uint8_t *_Nonnull bytes, size_t size);

/// Creates a script by copying an existring script.
TW_EXPORT_STATIC_METHOD
struct TWBitcoinScript *_Nonnull TWBitcoinScriptCreateCopy(const struct TWBitcoinScript *_Nonnull script);

TW_EXPORT_METHOD
void TWBitcoinScriptDelete(struct TWBitcoinScript *_Nonnull script);

TW_EXPORT_PROPERTY
size_t TWBitcoinScriptSize(const struct TWBitcoinScript *_Nonnull script);

TW_EXPORT_PROPERTY
TWData *_Nonnull TWBitcoinScriptData(const struct TWBitcoinScript *_Nonnull script);

TW_EXPORT_PROPERTY
TWData *_Nonnull TWBitcoinScriptScriptHash(const struct TWBitcoinScript *_Nonnull script);

/// Determines whether this is a pay-to-script-hash (P2SH) script.
TW_EXPORT_PROPERTY
bool TWBitcoinScriptIsPayToScriptHash(const struct TWBitcoinScript *_Nonnull script);

/// Determines whether this is a pay-to-witness-script-hash (P2WSH) script.
TW_EXPORT_PROPERTY
bool TWBitcoinScriptIsPayToWitnessScriptHash(const struct TWBitcoinScript *_Nonnull script);

/// Determines whether this is a witness programm script.
TW_EXPORT_PROPERTY
bool TWBitcoinScriptIsWitnessProgram(const struct TWBitcoinScript *_Nonnull script);

TW_EXPORT_STATIC_METHOD
bool TWBitcoinScriptEqual(const struct TWBitcoinScript *_Nonnull lhs, const struct TWBitcoinScript *_Nonnull rhs);

/// Encodes a small integer.
TW_EXPORT_STATIC_METHOD
uint8_t TWBitcoinScriptEncodeNumber(int value);

/// Decodes a small integer
TW_EXPORT_STATIC_METHOD
int TWBitcoinScriptDecodeNumber(uint8_t opcode);

/// Matches the script to a pay-to-public-key (P2PK) script.
///
/// - Returns: the public key.
TW_EXPORT_METHOD
TWData *_Nullable TWBitcoinScriptMatchPayToPubkey(const struct TWBitcoinScript *_Nonnull script);

/// Matches the script to a pay-to-public-key-hash (P2PKH).
///
/// - Returns: the key hash.
TW_EXPORT_METHOD
TWData *_Nullable TWBitcoinScriptMatchPayToPubkeyHash(const struct TWBitcoinScript *_Nonnull script);

/// Matches the script to a pay-to-script-hash (P2SH).
///
/// - Returns: the script hash.
TW_EXPORT_METHOD
TWData *_Nullable TWBitcoinScriptMatchPayToScriptHash(const struct TWBitcoinScript *_Nonnull script);

/// Matches the script to a pay-to-witness-public-key-hash (P2WPKH).
///
/// - Returns: the key hash.
TW_EXPORT_METHOD
TWData *_Nullable TWBitcoinScriptMatchPayToWitnessPublicKeyHash(const struct TWBitcoinScript *_Nonnull script);

/// Matches the script to a pay-to-witness-script-hash (P2WSH).
///
/// - Returns: the script hash, a SHA256 of the witness script.
TW_EXPORT_METHOD
TWData *_Nullable TWBitcoinScriptMatchPayToWitnessScriptHash(const struct TWBitcoinScript *_Nonnull script);

/// Encodes the script.
TW_EXPORT_METHOD
TWData *_Nonnull TWBitcoinScriptEncode(const struct TWBitcoinScript *_Nonnull script);

/// Builds a standard 'pay to public key hash' script.
TW_EXPORT_STATIC_METHOD
struct TWBitcoinScript *_Nonnull TWBitcoinScriptBuildPayToPublicKeyHash(TWData *_Nonnull hash);

/// Builds a standard 'pay to script hash' script.
TW_EXPORT_STATIC_METHOD
struct TWBitcoinScript *_Nonnull TWBitcoinScriptBuildPayToScriptHash(TWData *_Nonnull scriptHash);

/// Builds a pay-to-witness-public-key-hash (P2WPKH) script.
TW_EXPORT_STATIC_METHOD
struct TWBitcoinScript *_Nonnull TWBitcoinScriptBuildPayToWitnessPubkeyHash(TWData *_Nonnull hash);
struct TWBitcoinScript *_Nonnull TWBitcoinScriptBuildPayToWitnessPubkeyHashRaw(const uint8_t *_Nonnull hash);

/// Builds a pay-to-witness-script-hash (P2WSH) script.
TW_EXPORT_STATIC_METHOD
struct TWBitcoinScript *_Nonnull TWBitcoinScriptBuildPayToWitnessScriptHash(TWData *_Nonnull scriptHash);

TW_EXTERN_C_END

#if defined(__cplusplus)
#include <memory>
#include <vector>

struct TWBitcoinScript {
    std::vector<uint8_t> bytes;

    TWBitcoinScript() = default;
    TWBitcoinScript(const std::vector<uint8_t>& bytes) : bytes(bytes) {}
    TWBitcoinScript(std::vector<uint8_t>&& bytes) : bytes(bytes) {}

    /// Determines whether this is a pay-to-script-hash (P2SH) script.
    bool isPayToScriptHash() const;

    /// Determines whether this is a pay-to-witness-script-hash (P2WSH) script.
    bool isPayToWitnessScriptHash() const;

    /// Determines whether this is a witness programm script.
    bool isWitnessProgram() const;

    /// Matches the script to a pay-to-public-key (P2PK) script.
    bool matchPayToPubkey(std::vector<uint8_t>& publicKey) const;

    /// Matches the script to a pay-to-public-key-hash (P2PKH).
    bool matchPayToPubkeyHash(std::vector<uint8_t>& keyHash) const;

    /// Matches the script to a pay-to-script-hash (P2SH).
    bool matchPayToScriptHash(std::vector<uint8_t>& scriptHash) const;

    /// Matches the script to a pay-to-witness-public-key-hash (P2WPKH).
    bool matchPayToWitnessPublicKeyHash(std::vector<uint8_t>& keyHash) const;

    /// Matches the script to a pay-to-witness-script-hash (P2WSH).
    bool matchPayToWitnessScriptHash(std::vector<uint8_t>& scriptHash) const;

    /// Matches the script to a multisig script.
    bool matchMultisig(std::vector<std::vector<uint8_t>>& publicKeys, int& required) const;

    static TWBitcoinScript buildPayToPublicKeyHash(const std::vector<uint8_t>& hash);
    static TWBitcoinScript buildPayToScriptHash(const std::vector<uint8_t>& scriptHash);
    static TWBitcoinScript buildPayToWitnessPubkeyHashRaw(const std::vector<uint8_t>& hash);
    static TWBitcoinScript buildPayToWitnessScriptHash(const std::vector<uint8_t>& scriptHash);

    /// Encodes the script.
    void encode(std::vector<uint8_t>& data) const;

private:

    /// Returns a single operation at the given index including its operand.
    /// \param index index where the operation starts, on return the index of the next operation.
    /// \param opcode on return the opcode.
    /// \param operand the opcode's operand
    /// \return whether an opcode was available.
    bool getScriptOp(size_t& index, uint8_t& opcode, std::vector<uint8_t>& operand) const;
};

inline bool operator==(const TWBitcoinScript& lhs, const TWBitcoinScript& rhs) { return lhs.bytes == rhs.bytes; }
inline bool operator!=(const TWBitcoinScript& lhs, const TWBitcoinScript& rhs) { return !(lhs == rhs); }

using TWBitcoinScriptUniquePtr = std::unique_ptr<TWBitcoinScript, void (*)(TWBitcoinScript *_Nonnull)>;
using TWBitcoinScriptSharedPtr = std::shared_ptr<TWBitcoinScript>;

static inline TWBitcoinScriptUniquePtr TWBitcoinScriptMakeUnique(TWBitcoinScript *_Nonnull raw) {
    return TWBitcoinScriptUniquePtr(raw, TWBitcoinScriptDelete);
}

static inline TWBitcoinScriptSharedPtr TWBitcoinScriptMakeShared(TWBitcoinScript *_Nonnull raw) {
    return TWBitcoinScriptSharedPtr(raw, TWBitcoinScriptDelete);
}

#endif
