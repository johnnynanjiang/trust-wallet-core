// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#import <Foundation/Foundation.h>

//! Project version number for TrustWalletCore.
FOUNDATION_EXPORT double TrustWalletCoreVersionNumber;

//! Project version string for TrustWalletCore.
FOUNDATION_EXPORT const unsigned char TrustWalletCoreVersionString[];

#include <TrustWalletCore/TWBase.h>
#include <TrustWalletCore/TWData.h>
#include <TrustWalletCore/TWString.h>
#include <TrustWalletCore/TWFoundationData.h>
#include <TrustWalletCore/TWFoundationString.h>

#include <TrustWalletCore/TWHash.h>
#include <TrustWalletCore/TWHDWallet.h>
#include <TrustWalletCore/TWPrivateKey.h>
#include <TrustWalletCore/TWPublicKey.h>
#include <TrustWalletCore/TWUInt256.h>

#include <TrustWalletCore/TWBitcoinOpCodes.h>
#include <TrustWalletCore/TWBitcoinOutPoint.h>
#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWBitcoinTransaction.h>
#include <TrustWalletCore/TWBitcoinTransactionInput.h>
#include <TrustWalletCore/TWBitcoinTransactionOutput.h>
#include <TrustWalletCore/TWBech32Address.h>
#include <TrustWalletCore/TWSLIP.h>
