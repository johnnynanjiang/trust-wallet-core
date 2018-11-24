// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef JNI_TW_PUBLICKEY_H
#define JNI_TW_PUBLICKEY_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_PublicKey_initWithData(JNIEnv *env, jclass thisObject, jbyteArray data);

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_PublicKey_isValid(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_PublicKey_isCompressed(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_com_wallet_crypto_trustapp_jni_PublicKey_compressed(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_PublicKey_data(JNIEnv *env, jobject thisObject);


TW_EXTERN_C_END

#endif // JNI_TW_PUBLICKEY_H
