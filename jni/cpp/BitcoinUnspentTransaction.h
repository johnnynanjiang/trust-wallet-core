// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef JNI_TW_BITCOINUNSPENTTRANSACTION_H
#define JNI_TW_BITCOINUNSPENTTRANSACTION_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinUnspentTransaction_nativeCreateWithOutput(JNIEnv *env, jclass thisClass, jobject outpoint, jobject output);

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinUnspentTransaction_nativeCreate(JNIEnv *env, jclass thisClass, jbyteArray hash, jint index, jobject script, jlong amount);

JNIEXPORT
void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinUnspentTransaction_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinUnspentTransaction_outPoint(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinUnspentTransaction_output(JNIEnv *env, jobject thisObject);

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinUnspentTransaction_amount(JNIEnv *env, jobject thisObject);


TW_EXTERN_C_END

#endif // JNI_TW_BITCOINUNSPENTTRANSACTION_H
