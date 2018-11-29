// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWData.h>
#include <TrustWalletCore/TWPrivateKey.h>
#include "PrivateKey.h"

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_nativeCreate(JNIEnv *env, jclass thisClass) {
    struct TWPrivateKey *instance = TWPrivateKeyCreate();

    return (jlong) instance;
}

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_nativeCreateWithData(JNIEnv *env, jclass thisClass, jbyteArray data) {
    jbyte* dataBuffer = (*env)->GetByteArrayElements(env, data, NULL);
    jsize dataSize = (*env)->GetArrayLength(env, data);
    struct TWData dataData = {
        .bytes = (uint8_t *) dataBuffer,
        .len = (size_t) dataSize
    };

    struct TWPrivateKey *instance = TWPrivateKeyCreateWithData(dataData);

    (*env)->ReleaseByteArrayElements(env, data, dataBuffer, JNI_ABORT);
    return (jlong) instance;
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWPrivateKeyDelete((struct TWPrivateKey *) handle);
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_isValid(JNIEnv *env, jclass thisClass, jbyteArray data) {
    jbyte* dataBuffer = (*env)->GetByteArrayElements(env, data, NULL);
    jsize dataSize = (*env)->GetArrayLength(env, data);
    struct TWData dataData = {
        .bytes = (uint8_t *) dataBuffer,
        .len = (size_t) dataSize
    };

    jboolean resultValue = (jboolean) TWPrivateKeyIsValid(dataData);

    (*env)->ReleaseByteArrayElements(env, data, dataBuffer, JNI_ABORT);

    return resultValue;
}


jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_data(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    uint8_t resultBuffer[TWPrivateKeySize];
    TWPrivateKeyData(instance, resultBuffer);

    jbyteArray resultArray = (*env)->NewByteArray(env, TWPrivateKeySize);
    (*env)->SetByteArrayRegion(env, resultArray, 0, TWPrivateKeySize, (jbyte *) resultBuffer);
    return resultArray;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_sign(JNIEnv *env, jobject thisObject, jbyteArray digest) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyte* digestBuffer = (*env)->GetByteArrayElements(env, digest, NULL);
    jsize digestSize = (*env)->GetArrayLength(env, digest);
    struct TWData digestData = {
        .bytes = (uint8_t *) digestBuffer,
        .len = (size_t) digestSize
    };

    uint8_t resultBuffer[65];
    TWPrivateKeySign(instance, digestData, resultBuffer);

    (*env)->ReleaseByteArrayElements(env, digest, digestBuffer, JNI_ABORT);

    jbyteArray resultArray = (*env)->NewByteArray(env, 65);
    (*env)->SetByteArrayRegion(env, resultArray, 0, 65, (jbyte *) resultBuffer);
    return resultArray;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_signAsDER(JNIEnv *env, jobject thisObject, jbyteArray digest) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyte* digestBuffer = (*env)->GetByteArrayElements(env, digest, NULL);
    jsize digestSize = (*env)->GetArrayLength(env, digest);
    struct TWData digestData = {
        .bytes = (uint8_t *) digestBuffer,
        .len = (size_t) digestSize
    };

    uint8_t resultBuffer[72];
    jsize resultSize = (jsize) TWPrivateKeySignAsDER(instance, digestData, resultBuffer);

    (*env)->ReleaseByteArrayElements(env, digest, digestBuffer, JNI_ABORT);

    jbyteArray resultArray = (*env)->NewByteArray(env, resultSize);
    (*env)->SetByteArrayRegion(env, resultArray, 0, resultSize, (jbyte *) resultBuffer);
    return resultArray;
}

