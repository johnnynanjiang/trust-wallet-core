// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <TrustWalletCore/TWString.h>

const TWString *_Nonnull TWStringCreateWithReference(NSString *_Nonnull other);
NSString *_Nonnull TWStringNSString(TWString *_Nonnull string);
