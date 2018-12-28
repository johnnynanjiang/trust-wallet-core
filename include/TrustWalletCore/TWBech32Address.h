// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"
#include "TWString.h"

TW_EXTERN_C_BEGIN

struct TWPublicKey;

/// Represents a BIP 0173 address.
TW_EXPORT_STRUCT
struct TWBech32Address {
    /// Address data.
    uint8_t data[33];

    /// Human-readable part.
    ///
    /// \see https://github.com/satoshilabs/slips/blob/master/slip-0173.md
    const char *_Nullable hrp;
};

/// Compares two addresses for equality.
TW_EXPORT_STATIC_METHOD
bool TWBech32AddressEqual(struct TWBech32Address lhs, struct TWBech32Address rhs);

/// Determines if the data is a valid Bech32 address.
TW_EXPORT_STATIC_METHOD
bool TWBech32AddressIsValid(TWData *_Nonnull data);

/// Determines if the string is a valid Bech32 address.
TW_EXPORT_STATIC_METHOD
bool TWBech32AddressIsValidString(TWString *_Nonnull string);

/// Initializes an address from a string representaion.
TW_EXPORT_STATIC_METHOD
bool TWBech32AddressInitWithString(struct TWBech32Address *_Nonnull address, TWString *_Nonnull string);

/// Initializes an address from data and a HRP type.
TW_EXPORT_STATIC_METHOD
bool TWBech32AddressInitWithData(struct TWBech32Address *_Nonnull address, TWData *_Nonnull data, TWString *_Nonnull hrp);

/// Initializes an address from a public key.
TW_EXPORT_STATIC_METHOD
bool TWBech32AddressInitWithPublicKey(struct TWBech32Address *_Nonnull address, struct TWPublicKey publicKey, TWString *_Nonnull hrp);

/// Returns the address string representation.
TW_EXPORT_PROPERTY
TWString *_Nonnull TWBech32AddressDescription(struct TWBech32Address address);

/// Returns the address data.
TW_EXPORT_PROPERTY
TWData *_Nonnull TWBech32AddressData(struct TWBech32Address address);

TW_EXTERN_C_END
