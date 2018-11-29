// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef JNI_TW_BITCOINSCRIPT_H
#define JNI_TW_BITCOINSCRIPT_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_bitcoin_BitcoinScript_nativeCreate(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
void JNICALL Java_com_wallet_crypto_trustapp_jni_bitcoin_BitcoinScript_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);


TW_EXTERN_C_END

#endif // JNI_TW_BITCOINSCRIPT_H
