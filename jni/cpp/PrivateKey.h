// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_PRIVATEKEY_H
#define JNI_TW_PRIVATEKEY_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_nativeCreate(JNIEnv *env, jclass thisClass);

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_nativeCreateWithData(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_nativeCreateCopy(JNIEnv *env, jclass thisClass, jobject key);

JNIEXPORT
void JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_isValid(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_data(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_getPublicKey(JNIEnv *env, jobject thisObject, jboolean compressed);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_sign(JNIEnv *env, jobject thisObject, jbyteArray digest);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_signAsDER(JNIEnv *env, jobject thisObject, jbyteArray digest);


TW_EXTERN_C_END

#endif // JNI_TW_PRIVATEKEY_H
