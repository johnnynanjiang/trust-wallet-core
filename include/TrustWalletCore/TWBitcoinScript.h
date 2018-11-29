// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef TW_BITCOINSCRIPT_H
#define TW_BITCOINSCRIPT_H

#include "TWBase.h"
#include "TWData.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_CLASS
struct TWBitcoinScript;

TW_EXPORT_STATIC_METHOD
struct TWBitcoinScript *_Nonnull TWBitcoinScriptCreate(struct TWData data);

TW_EXPORT_METHOD
void TWBitcoinScriptDelete(struct TWBitcoinScript *_Nonnull script);

TW_EXPORT_PROPERTY
size_t TWBitcoinScriptSize(struct TWBitcoinScript *_Nonnull script);

TW_EXPORT_PROPERTY
size_t TWBitcoinScriptData(struct TWBitcoinScript *_Nonnull script, uint8_t *_Nullable result);

TW_EXTERN_C_END

#endif // TW_BITCOINSCRIPT_H
