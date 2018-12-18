// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef JNI_TW_BITCOINSIGNINGPROVIDER_H
#define JNI_TW_BITCOINSIGNINGPROVIDER_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinSigningProvider_nativeCreate(JNIEnv *env, jclass thisClass);

JNIEXPORT
void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinSigningProvider_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinSigningProvider_addKey(JNIEnv *env, jobject thisObject, jobject key);

JNIEXPORT
void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinSigningProvider_addRedeemScript(JNIEnv *env, jobject thisObject, jbyteArray hash, jobject script);


TW_EXTERN_C_END

#endif // JNI_TW_BITCOINSIGNINGPROVIDER_H
