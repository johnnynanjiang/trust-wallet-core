// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef JNI_TW_INT256_H
#define JNI_TW_INT256_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_nativeCreateZero(JNIEnv *, jclass);

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_nativeCreateOne(JNIEnv *, jclass);

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_nativeCreateWithData(JNIEnv *, jclass, jbyteArray);

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_nativeCreateWithInt(JNIEnv *, jclass, jint);

JNIEXPORT
void JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_delete(JNIEnv *, jclass, jlong);

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_isZero(JNIEnv *, jobject);

JNIEXPORT
jint JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_intValue(JNIEnv *, jobject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_getBytes(JNIEnv *, jobject);

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_equals(JNIEnv *, jobject, jobject);

JNIEXPORT
jint JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_compareTo(JNIEnv *, jobject, jobject);

JNIEXPORT
jstring JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_format(JNIEnv *, jobject, jint, jint);

TW_EXTERN_C_END

#endif /* JNI_TW_INT256_H */
