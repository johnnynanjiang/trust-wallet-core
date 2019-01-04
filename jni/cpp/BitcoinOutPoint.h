// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef JNI_TW_BITCOINOUTPOINT_H
#define JNI_TW_BITCOINOUTPOINT_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinOutPoint_initWithHash(JNIEnv *env, jclass thisClass, jbyteArray hash, jint index);

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinOutPoint_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinOutPoint_hash(JNIEnv *env, jobject thisObject);

JNIEXPORT
jint JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinOutPoint_index(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinOutPoint_encode(JNIEnv *env, jobject thisObject);


TW_EXTERN_C_END

#endif // JNI_TW_BITCOINOUTPOINT_H
