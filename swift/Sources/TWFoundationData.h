// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <TrustWalletCore/TWData.h>

TWData *_Nonnull TWDataCreateWithReference(NSMutableData *_Nonnull data);
NSMutableData *_Nonnull TWDataNSData(TWData *_Nonnull data);