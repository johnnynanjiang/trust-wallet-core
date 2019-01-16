// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include "TWBase.h"

TW_EXTERN_C_BEGIN

/// Coin type for Level 2 of BIP44.
///
/// - SeeAlso: https://github.com/satoshilabs/slips/blob/master/slip-0044.md
TW_EXPORT_ENUM(uint32_t)
enum TWCoinType {
    TWCoinTypeBitcoin = 0,
    TWCoinTypeLitecoin = 2,
    TWCoinTypeBitcoinCash = 145,
    TWCoinTypeDash = 5,
    TWCoinTypeEthereum = 60,
    TWCoinTypeEthereumClassic = 61,
    TWCoinTypeThunderToken = 1001,
    TWCoinTypeGo = 6060,
    TWCoinTypePoa = 178,
    TWCoinTypeTron = 195,
    TWCoinTypeVeChain = 818,
    TWCoinTypeCallisto = 820,
    TWCoinTypeTomoChain = 889,
    TWCoinTypeWanChain = 5718350,
    TWCoinTypeICON = 74,
    TWCoinTypeEOS = 194,
};

TW_EXTERN_C_END
