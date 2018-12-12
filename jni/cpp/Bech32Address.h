// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef JNI_TW_BECH32ADDRESS_H
#define JNI_TW_BECH32ADDRESS_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_initWithString(JNIEnv *env, jclass thisClass, jstring string);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_initWithData(JNIEnv *env, jclass thisClass, jbyteArray data, jstring hrp);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_initWithPublicKey(JNIEnv *env, jclass thisClass, jobject publicKey, jstring hrp);

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs);

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_isValid(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jstring JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_description(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_data(JNIEnv *env, jobject thisObject);


TW_EXTERN_C_END

#endif // JNI_TW_BECH32ADDRESS_H
