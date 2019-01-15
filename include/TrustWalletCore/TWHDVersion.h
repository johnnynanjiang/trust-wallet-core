// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include "TWBase.h"

TW_EXTERN_C_BEGIN

///  Registered HD version bytes
///
/// - SeeAlso: https://github.com/satoshilabs/slips/blob/master/slip-0132.md
TW_EXPORT_ENUM
enum TWHDVersion {
    TWHDVersionNone = 0,

    // Bitcoin
    TWHDVersionXPUB = 0x0488b21e,
    TWHDVersionXPRV = 0x0488ade4,
    TWHDVersionYPUB = 0x049d7cb2,
    TWHDVersionYPRV = 0x049d7878,
    TWHDVersionZPUB = 0x04b24746,
    TWHDVersionZPRV = 0x04b2430c,

    // Litecoin
    TWHDVersionLTUB = 0x019da462,
    TWHDVersionLTPV = 0x019d9cfe,
    TWHDVersionMTUB = 0x01b26ef6,
    TWHDVersionMTPV = 0x01b26792,
};

TW_EXTERN_C_END
