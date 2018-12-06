// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWHash.h>
#include "TWJNI.h"
#include "Hash.h"

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_sha1(JNIEnv *env, jclass thisClass, jbyteArray data) {
    currentEnv = env;
    jbyteArray result = (jbyteArray) TWHashSHA1(data);
    return result;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_sha256(JNIEnv *env, jclass thisClass, jbyteArray data) {
    currentEnv = env;
    jbyteArray result = (jbyteArray) TWHashSHA256(data);
    return result;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_sha512(JNIEnv *env, jclass thisClass, jbyteArray data) {
    currentEnv = env;
    jbyteArray result = (jbyteArray) TWHashSHA512(data);
    return result;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_keccak256(JNIEnv *env, jclass thisClass, jbyteArray data) {
    currentEnv = env;
    jbyteArray result = (jbyteArray) TWHashKeccak256(data);
    return result;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_keccak512(JNIEnv *env, jclass thisClass, jbyteArray data) {
    currentEnv = env;
    jbyteArray result = (jbyteArray) TWHashKeccak512(data);
    return result;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_sha3_256(JNIEnv *env, jclass thisClass, jbyteArray data) {
    currentEnv = env;
    jbyteArray result = (jbyteArray) TWHashSHA3_256(data);
    return result;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_sha3_512(JNIEnv *env, jclass thisClass, jbyteArray data) {
    currentEnv = env;
    jbyteArray result = (jbyteArray) TWHashSHA3_512(data);
    return result;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_ripemd(JNIEnv *env, jclass thisClass, jbyteArray data) {
    currentEnv = env;
    jbyteArray result = (jbyteArray) TWHashRIPEMD(data);
    return result;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_blake2b(JNIEnv *env, jclass thisClass, jbyteArray data, jsize size) {
    currentEnv = env;
    jbyteArray result = (jbyteArray) TWHashBlake2b(data, size);
    return result;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_sha256RIPEMD(JNIEnv *env, jclass thisClass, jbyteArray data) {
    currentEnv = env;
    jbyteArray result = (jbyteArray) TWHashSHA256RIPEMD(data);
    return result;
}


