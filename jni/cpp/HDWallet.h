// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef JNI_TW_HDWALLET_H
#define JNI_TW_HDWALLET_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_nativeCreateWithMnemonic(JNIEnv *env, jclass thisClass, jstring mnemonic, jstring passphrase);

JNIEXPORT
void JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle);

JNIEXPORT
jobject JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_getPublicKeyFromExtended(JNIEnv *env, jclass thisClass, jstring extended, jint versionPublic, jint versionPrivate, jint change, jint address);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_seed(JNIEnv *env, jobject thisObject);

JNIEXPORT
jobject JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_getKey(JNIEnv *env, jobject thisObject, jint purpose, jint coin, jint account, jint change, jint address);

JNIEXPORT
jstring JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_getExtendedPrivateKey(JNIEnv *env, jobject thisObject, jint purpose, jint coin, jint version);

JNIEXPORT
jstring JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_getExtendedPublicKey(JNIEnv *env, jobject thisObject, jint purpose, jint coin, jint version);


TW_EXTERN_C_END

#endif // JNI_TW_HDWALLET_H