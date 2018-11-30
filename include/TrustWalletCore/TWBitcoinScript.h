// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef TW_BITCOINSCRIPT_H
#define TW_BITCOINSCRIPT_H

#include "TWBase.h"
#include "TWData.h"
#include "TWPublicKey.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_CLASS
struct TWBitcoinScript;

TW_EXPORT_STATIC_METHOD
struct TWBitcoinScript *_Nonnull TWBitcoinScriptCreate(struct TWData data);

TW_EXPORT_METHOD
void TWBitcoinScriptDelete(struct TWBitcoinScript *_Nonnull script);

TW_EXPORT_PROPERTY
size_t TWBitcoinScriptSize(struct TWBitcoinScript *_Nonnull script);

TW_EXPORT_PROPERTY
size_t TWBitcoinScriptData(struct TWBitcoinScript *_Nonnull script, uint8_t *_Nullable result);

TW_EXPORT_PROPERTY
size_t TWBitcoinScriptScriptHash(struct TWBitcoinScript *_Nonnull script, uint8_t result[_Nullable 20]);

/// Determines whether this is a pay-to-script-hash (P2SH) script.
TW_EXPORT_PROPERTY
bool TWBitcoinScriptIsPayToScriptHash(struct TWBitcoinScript *_Nonnull script);

/// Determines whether this is a pay-to-witness-script-hash (P2WSH) script.
TW_EXPORT_PROPERTY
bool TWBitcoinScriptIsPayToWitnessScriptHash(struct TWBitcoinScript *_Nonnull script);

/// Determines whether this is a witness programm script.
TW_EXPORT_PROPERTY
bool TWBitcoinScriptIsWitnessProgram(struct TWBitcoinScript *_Nonnull script);

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
size_t TWBitcoinScriptMatchPayToPubkey(struct TWBitcoinScript *_Nonnull script, uint8_t result[_Nonnull TWPublicKeyUncompressedSize]);

/// Matches the script to a pay-to-public-key-hash (P2PKH).
///
/// - Returns: the key hash.
TW_EXPORT_METHOD
size_t TWBitcoinScriptMatchPayToPubkeyHash(struct TWBitcoinScript *_Nonnull script, uint8_t *_Nullable result);

/// Matches the script to a pay-to-script-hash (P2SH).
///
/// - Returns: the script hash.
TW_EXPORT_METHOD
size_t TWBitcoinScriptMatchPayToScriptHash(struct TWBitcoinScript *_Nonnull script, uint8_t *_Nullable result);

/// Matches the script to a pay-to-witness-public-key-hash (P2WPKH).
///
/// - Returns: the key hash.
TW_EXPORT_METHOD
size_t TWBitcoinScriptMatchPayToWitnessPublicKeyHash(struct TWBitcoinScript *_Nonnull script, uint8_t *_Nullable result);

/// Matches the script to a pay-to-witness-script-hash (P2WSH).
///
/// - Returns: the script hash, a SHA256 of the witness script.
TW_EXPORT_METHOD
size_t TWBitcoinScriptMatchPayToWitnessScriptHash(struct TWBitcoinScript *_Nonnull script, uint8_t *_Nullable result);

/// Encodes the script into the provided buffer.
TW_EXPORT_METHOD
size_t TWBitcoinScriptEncode(struct TWBitcoinScript *_Nonnull script, uint8_t *_Nullable result);

/// Builds a standard 'pay to public key hash' script.
TW_EXPORT_STATIC_METHOD
struct TWBitcoinScript *_Nonnull TWBitcoinScriptBuildPayToPublicKeyHash(struct TWData hash);

/// Builds a standard 'pay to script hash' script.
TW_EXPORT_STATIC_METHOD
struct TWBitcoinScript *_Nonnull TWBitcoinScriptBuildPayToScriptHash(struct TWData scriptHash);

/// Builds a pay-to-witness-public-key-hash (P2WPKH) script.
TW_EXPORT_STATIC_METHOD
struct TWBitcoinScript *_Nonnull TWBitcoinScriptBuildPayToWitnessPubkeyHash(struct TWData hash);

/// Builds a pay-to-witness-script-hash (P2WSH) script.
TW_EXPORT_STATIC_METHOD
struct TWBitcoinScript *_Nonnull TWBitcoinScriptBuildPayToWitnessScriptHash(struct TWData scriptHash);

TW_EXTERN_C_END

#endif // TW_BITCOINSCRIPT_H
