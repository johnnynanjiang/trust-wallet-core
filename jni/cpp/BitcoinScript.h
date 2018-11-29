// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef JNI_TW_BITCOINSCRIPT_H
#define JNI_TW_BITCOINSCRIPT_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_nativeCreate(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jint JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_decodeNumber(JNIEnv *env, jclass thisClass, jchar opcode);

JNIEXPORT
jsize JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_size(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_data(JNIEnv *env, jobject thisObject);

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_isPayToScriptHash(JNIEnv *env, jobject thisObject);

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_isPayToWitnessScriptHash(JNIEnv *env, jobject thisObject);

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_isWitnessProgram(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_matchPayToPubkey(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_matchPayToPubkeyHash(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_matchPayToScriptHash(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_matchPayToWitnessPublicKeyHash(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_matchPayToWitnessScriptHash(JNIEnv *env, jobject thisObject);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_encode(JNIEnv *env, jobject thisObject);


TW_EXTERN_C_END

#endif // JNI_TW_BITCOINSCRIPT_H
