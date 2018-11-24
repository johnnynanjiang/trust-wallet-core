// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWData.h>
#include <TrustWalletCore/TWHash.h>
#include "Hash.h"

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_sha1(JNIEnv *env, jclass thisClass, jbyteArray data) {
    jbyte* dataBuffer = (*env)->GetByteArrayElements(env, data, NULL);
    jsize dataSize = (*env)->GetArrayLength(env, data);
    struct TWData dataData = {
        .bytes = (uint8_t *) dataBuffer,
        .len = (size_t) dataSize
    };

    uint8_t resultBuffer[TWHashSHA1Length];
    TWHashSHA1(dataData, resultBuffer);
    jbyteArray resultArray = (*env)->NewByteArray(env, TWHashSHA1Length);
    (*env)->SetByteArrayRegion(env, resultArray, 0, TWHashSHA1Length, (jbyte *) resultBuffer);

    (*env)->ReleaseByteArrayElements(env, data, dataBuffer, JNI_ABORT);

    return resultArray;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_sha256(JNIEnv *env, jclass thisClass, jbyteArray data) {
    jbyte* dataBuffer = (*env)->GetByteArrayElements(env, data, NULL);
    jsize dataSize = (*env)->GetArrayLength(env, data);
    struct TWData dataData = {
        .bytes = (uint8_t *) dataBuffer,
        .len = (size_t) dataSize
    };

    uint8_t resultBuffer[TWHashSHA256Length];
    TWHashSHA256(dataData, resultBuffer);
    jbyteArray resultArray = (*env)->NewByteArray(env, TWHashSHA256Length);
    (*env)->SetByteArrayRegion(env, resultArray, 0, TWHashSHA256Length, (jbyte *) resultBuffer);

    (*env)->ReleaseByteArrayElements(env, data, dataBuffer, JNI_ABORT);

    return resultArray;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_sha512(JNIEnv *env, jclass thisClass, jbyteArray data) {
    jbyte* dataBuffer = (*env)->GetByteArrayElements(env, data, NULL);
    jsize dataSize = (*env)->GetArrayLength(env, data);
    struct TWData dataData = {
        .bytes = (uint8_t *) dataBuffer,
        .len = (size_t) dataSize
    };

    uint8_t resultBuffer[TWHashSHA512Length];
    TWHashSHA512(dataData, resultBuffer);
    jbyteArray resultArray = (*env)->NewByteArray(env, TWHashSHA512Length);
    (*env)->SetByteArrayRegion(env, resultArray, 0, TWHashSHA512Length, (jbyte *) resultBuffer);

    (*env)->ReleaseByteArrayElements(env, data, dataBuffer, JNI_ABORT);

    return resultArray;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_keccak256(JNIEnv *env, jclass thisClass, jbyteArray data) {
    jbyte* dataBuffer = (*env)->GetByteArrayElements(env, data, NULL);
    jsize dataSize = (*env)->GetArrayLength(env, data);
    struct TWData dataData = {
        .bytes = (uint8_t *) dataBuffer,
        .len = (size_t) dataSize
    };

    uint8_t resultBuffer[TWHashSHA256Length];
    TWHashKeccak256(dataData, resultBuffer);
    jbyteArray resultArray = (*env)->NewByteArray(env, TWHashSHA256Length);
    (*env)->SetByteArrayRegion(env, resultArray, 0, TWHashSHA256Length, (jbyte *) resultBuffer);

    (*env)->ReleaseByteArrayElements(env, data, dataBuffer, JNI_ABORT);

    return resultArray;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_keccak512(JNIEnv *env, jclass thisClass, jbyteArray data) {
    jbyte* dataBuffer = (*env)->GetByteArrayElements(env, data, NULL);
    jsize dataSize = (*env)->GetArrayLength(env, data);
    struct TWData dataData = {
        .bytes = (uint8_t *) dataBuffer,
        .len = (size_t) dataSize
    };

    uint8_t resultBuffer[TWHashSHA512Length];
    TWHashKeccak512(dataData, resultBuffer);
    jbyteArray resultArray = (*env)->NewByteArray(env, TWHashSHA512Length);
    (*env)->SetByteArrayRegion(env, resultArray, 0, TWHashSHA512Length, (jbyte *) resultBuffer);

    (*env)->ReleaseByteArrayElements(env, data, dataBuffer, JNI_ABORT);

    return resultArray;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_sha3_256(JNIEnv *env, jclass thisClass, jbyteArray data) {
    jbyte* dataBuffer = (*env)->GetByteArrayElements(env, data, NULL);
    jsize dataSize = (*env)->GetArrayLength(env, data);
    struct TWData dataData = {
        .bytes = (uint8_t *) dataBuffer,
        .len = (size_t) dataSize
    };

    uint8_t resultBuffer[TWHashSHA256Length];
    TWHashSHA3_256(dataData, resultBuffer);
    jbyteArray resultArray = (*env)->NewByteArray(env, TWHashSHA256Length);
    (*env)->SetByteArrayRegion(env, resultArray, 0, TWHashSHA256Length, (jbyte *) resultBuffer);

    (*env)->ReleaseByteArrayElements(env, data, dataBuffer, JNI_ABORT);

    return resultArray;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_sha3_512(JNIEnv *env, jclass thisClass, jbyteArray data) {
    jbyte* dataBuffer = (*env)->GetByteArrayElements(env, data, NULL);
    jsize dataSize = (*env)->GetArrayLength(env, data);
    struct TWData dataData = {
        .bytes = (uint8_t *) dataBuffer,
        .len = (size_t) dataSize
    };

    uint8_t resultBuffer[TWHashSHA512Length];
    TWHashSHA3_512(dataData, resultBuffer);
    jbyteArray resultArray = (*env)->NewByteArray(env, TWHashSHA512Length);
    (*env)->SetByteArrayRegion(env, resultArray, 0, TWHashSHA512Length, (jbyte *) resultBuffer);

    (*env)->ReleaseByteArrayElements(env, data, dataBuffer, JNI_ABORT);

    return resultArray;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_ripemd(JNIEnv *env, jclass thisClass, jbyteArray data) {
    jbyte* dataBuffer = (*env)->GetByteArrayElements(env, data, NULL);
    jsize dataSize = (*env)->GetArrayLength(env, data);
    struct TWData dataData = {
        .bytes = (uint8_t *) dataBuffer,
        .len = (size_t) dataSize
    };

    uint8_t resultBuffer[TWHashRipemdLength];
    TWHashRIPEMD(dataData, resultBuffer);
    jbyteArray resultArray = (*env)->NewByteArray(env, TWHashRipemdLength);
    (*env)->SetByteArrayRegion(env, resultArray, 0, TWHashRipemdLength, (jbyte *) resultBuffer);

    (*env)->ReleaseByteArrayElements(env, data, dataBuffer, JNI_ABORT);

    return resultArray;
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_Hash_blake2b(JNIEnv *env, jclass thisClass, jbyteArray data, jbyteArray result, jsize size) {
    jbyte* dataBuffer = (*env)->GetByteArrayElements(env, data, NULL);
    jsize dataSize = (*env)->GetArrayLength(env, data);
    struct TWData dataData = {
        .bytes = (uint8_t *) dataBuffer,
        .len = (size_t) dataSize
    };

    jbyte* resultBuffer = (*env)->GetByteArrayElements(env, result, NULL);
    jsize resultSize = (*env)->GetArrayLength(env, result);
    struct TWData resultData = {
        .bytes = (uint8_t *) resultBuffer,
        .len = (size_t) resultSize
    };

    TWHashBlake2b(dataData, resultBuffer, size);

    (*env)->ReleaseByteArrayElements(env, data, dataBuffer, JNI_ABORT);

    (*env)->ReleaseByteArrayElements(env, result, resultBuffer, JNI_ABORT);

}


