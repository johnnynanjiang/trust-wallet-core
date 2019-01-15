// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include "TWBase.h"

TW_EXTERN_C_BEGIN

///  Registered human-readable parts for BIP-0173
///
/// - SeeAlso: https://github.com/satoshilabs/slips/blob/master/slip-0173.md
static const char *HRP_BITCOIN = "bc";
static const char *HRP_LITECOIN = "ltc";
static const char *HRP_BITCOINCASH = "bitcoincash";

static const char *HRP[] = {
    "bc",
    "tb",
    "ltc",
    "tltc",
    "bitcoincash",
    "bchtest",
};

TW_EXTERN_C_END
