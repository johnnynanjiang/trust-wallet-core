// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef JNI_TW_BITCOINTRANSACTIONOUTPUT_H
#define JNI_TW_BITCOINTRANSACTIONOUTPUT_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionOutput_nativeCreate(JNIEnv *env, jclass thisClass, jlong value, jobject script);

JNIEXPORT
void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionOutput_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionOutput_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs);

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionOutput_amount(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionOutput_script(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionOutput_encode(JNIEnv *env, jobject thisObject);


TW_EXTERN_C_END

#endif // JNI_TW_BITCOINTRANSACTIONOUTPUT_H
