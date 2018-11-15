// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef JNI_TW_PRIVATE_KEY_H
#define JNI_TW_PRIVATE_KEY_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_nativeCreateWithData(JNIEnv *env, jclass thisClass, jbyteArray array);

JNIEXPORT
void Java_com_wallet_crypto_trustapp_jni_PrivateKey_delete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jbyteArray Java_com_wallet_crypto_trustapp_jni_PrivateKey_getBytes(JNIEnv *env, jobject thisObject);

TW_EXTERN_C_END

#endif /* JNI_TW_PRIVATE_KEY_H */
