// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include "TWBase.h"

TW_EXTERN_C_BEGIN

/// HD wallet purpose
///
/// See https://github.com/bitcoin/bips/blob/master/bip-0044.mediawiki
/// See https://github.com/bitcoin/bips/blob/master/bip-0049.mediawiki
/// See https://github.com/bitcoin/bips/blob/master/bip-0084.mediawiki
enum Purpose {
    BIP44 = 44,
    BIP49 = 49, // Derivation scheme for P2WPKH-nested-in-P2SH
    BIP84 = 84, // Derivation scheme for P2WPKH
};

/// Coin type for Level 2 of BIP44.
///
/// - SeeAlso: https://github.com/satoshilabs/slips/blob/master/slip-0044.md
enum CoinType {
    COIN_BITCOIN = 0,
    COIN_LITECOIN = 2,
    COIN_BITCOINCASH = 145,
    COIN_DASH = 5,
    COIN_ETHEREUM = 60,
    COIN_ETHEREUMCLASSIC = 61,
    COIN_THUNDERTOKEN = 1001,
    COIN_GO = 6060,
    COIN_POA = 178,
    COIN_TRON = 195,
    COIN_VECHAIN = 818,
    COIN_CALLISTO = 820,
    COIN_TOMOCHAIN = 889,
    COIN_WANCHAIN = 5718350,
    COIN_ICON = 74,
    COIN_EOS = 194,
};

///  Registered HD version bytes
///
/// - SeeAlso: https://github.com/satoshilabs/slips/blob/master/slip-0132.md
enum HDVersion {
    // Bitcoin
    HD_XPUB = 0x0488b21e,
    HD_XPRV = 0x0488ade4,
    HD_YPUB = 0x049d7cb2,
    HD_YPRV = 0x049d7878,
    HD_ZPUB = 0x04b24746,
    HD_ZPRV = 0x04b2430c,

    // Litecoin
    HD_LTUB = 0x019da462,
    HD_LTPV = 0x019d9cfe,
    HD_MTUB = 0x01b26ef6,
    HD_MTPV = 0x01b26792,
};

///  Registered human-readable parts for BIP-0173
///
/// - SeeAlso: https://github.com/satoshilabs/slips/blob/master/slip-0173.md
static const char *HRP_BITCOIN = "bc";
static const char *HRP_LITECOIN = "ltc";
static const char *HRP_BITCOINCASH = "bitcoincash";

static const char *HRP[] = {
    "bc",
    "ltc",
    "bitcoincash",
};

TW_EXTERN_C_END
