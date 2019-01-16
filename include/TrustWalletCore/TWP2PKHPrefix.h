// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include "TWBase.h"

TW_EXTERN_C_BEGIN

/// Public key hash address prefix.
///
/// - SeeAlso: https://dash-docs.github.io/en/developer-reference#address-conversion
TW_EXPORT_ENUM(uint8_t)
enum TWP2PKHPrefix {
    TWP2PKHPrefixBitcoin = 0x00,
    TWP2PKHPrefixLitecoin = 0x30,
    TWP2PKHPrefixDash = 0x4C,
};

TW_EXTERN_C_END
