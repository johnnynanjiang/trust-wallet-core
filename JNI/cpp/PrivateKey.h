// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef JNI_TW_DATA_H
#define JNI_TW_DATA_H

#include <jni.h>
#include <TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_create(JNIEnv *env, jclass thisClas);

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_createWithData(JNIEnv *env, jclass thisClas, jbyteArray array);

JNIEXPORT
void Java_com_wallet_crypto_trustapp_jni_PrivateKey_delete(JNIEnv *env, jclass thisClas, jlong handle);

TW_EXTERN_C_END

#endif /* JNI_TW_DATA_H */
