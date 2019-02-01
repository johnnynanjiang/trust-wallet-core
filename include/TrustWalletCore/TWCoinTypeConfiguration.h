// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include "TWBase.h"
#include "TWCoinType.h"
#include "TWString.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_STRUCT
struct TWCoinTypeConfiguration;

TW_EXPORT_STATIC_METHOD
TWString *_Nullable TWCoinTypeConfigurationGetSymbol(enum TWCoinType type);

TW_EXPORT_STATIC_METHOD
int TWCoinTypeConfigurationGetDecimals(enum TWCoinType type);

TW_EXPORT_STATIC_METHOD
TWString *_Nullable TWCoinTypeConfigurationGetTransactionURL(enum TWCoinType type, TWString *_Nonnull transactionID);

TW_EXTERN_C_END
