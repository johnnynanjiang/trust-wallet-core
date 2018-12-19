// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef JNI_TW_BITCOINTRANSACTION_H
#define JNI_TW_BITCOINTRANSACTION_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_nativeCreate(JNIEnv *env, jclass thisClass, jint version, jint lockTime);

JNIEXPORT
void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jint JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_lockTime(JNIEnv *env, jobject thisObject);

JNIEXPORT
jsize JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_inputCount(JNIEnv *env, jobject thisObject);

JNIEXPORT
jsize JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_outputCount(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_hash(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_witnessHash(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_identifier(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_witnessIdentifier(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_getInput(JNIEnv *env, jobject thisObject, jsize index);

JNIEXPORT
void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_addInput(JNIEnv *env, jobject thisObject, jobject previousOutput, jobject script, jint sequence);

JNIEXPORT
jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_getOutput(JNIEnv *env, jobject thisObject, jsize index);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_encode(JNIEnv *env, jobject thisObject, jboolean witness);


TW_EXTERN_C_END

#endif // JNI_TW_BITCOINTRANSACTION_H
