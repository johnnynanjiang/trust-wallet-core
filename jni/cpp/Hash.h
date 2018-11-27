// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#ifndef JNI_TW_HASH_H
#define JNI_TW_HASH_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_sha1(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_sha256(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_sha512(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_keccak256(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_keccak512(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_sha3_256(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_sha3_512(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_ripemd(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
void JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_blake2b(JNIEnv *env, jclass thisClass, jbyteArray data, jbyteArray result, jsize size);


TW_EXTERN_C_END

#endif // JNI_TW_HASH_H