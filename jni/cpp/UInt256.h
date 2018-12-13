// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef JNI_TW_UINT256_H
#define JNI_TW_UINT256_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_nativeCreateWithData(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_nativeCreateWithUInt32(JNIEnv *env, jclass thisClass, jint value);

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_nativeCreateWithUInt64(JNIEnv *env, jclass thisClass, jlong value);

JNIEXPORT
void JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jobject JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_zero(JNIEnv *env, jclass thisClass);

JNIEXPORT
jobject JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_one(JNIEnv *env, jclass thisClass);

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs);

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_less(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs);

JNIEXPORT
jint JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_compareTo(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs);

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_isZero(JNIEnv *env, jobject thisObject);

JNIEXPORT
jint JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_uint32Value(JNIEnv *env, jobject thisObject);

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_uint64Value(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_data(JNIEnv *env, jobject thisObject);

JNIEXPORT
jstring JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_format(JNIEnv *env, jobject thisObject, jint decimals, jint exponent);


TW_EXTERN_C_END

#endif // JNI_TW_UINT256_H
