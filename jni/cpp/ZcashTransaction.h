// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_ZCASHTRANSACTION_H
#define JNI_TW_ZCASHTRANSACTION_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_ZcashTransaction_nativeCreate(JNIEnv *env, jclass thisClass);

JNIEXPORT
void JNICALL Java_com_wallet_crypto_trustapp_jni_ZcashTransaction_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jint JNICALL Java_com_wallet_crypto_trustapp_jni_ZcashTransaction_lockTime(JNIEnv *env, jobject thisObject);

JNIEXPORT
jsize JNICALL Java_com_wallet_crypto_trustapp_jni_ZcashTransaction_inputCount(JNIEnv *env, jobject thisObject);

JNIEXPORT
jsize JNICALL Java_com_wallet_crypto_trustapp_jni_ZcashTransaction_outputCount(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_ZcashTransaction_hash(JNIEnv *env, jobject thisObject);

JNIEXPORT
jstring JNICALL Java_com_wallet_crypto_trustapp_jni_ZcashTransaction_identifier(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_ZcashTransaction_encode(JNIEnv *env, jobject thisObject);


TW_EXTERN_C_END

#endif // JNI_TW_ZCASHTRANSACTION_H
