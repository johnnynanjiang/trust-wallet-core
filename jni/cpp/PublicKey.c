// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWData.h>
#include <TrustWalletCore/TWPublicKey.h>
#include "PublicKey.h"

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_PublicKey_initWithData(JNIEnv *env, jclass thisObject, jbyteArray data) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID bytesFieldID = (*env)->GetFieldID(env, thisClass, "bytes", "[b");
    jbyteArray bytesArray = (*env)->GetObjectField(env, thisObject, bytesFieldID);
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, bytesArray, NULL);
    struct TWPublicKey *instance = (struct TWPublicKey *) bytesBuffer;

    jbyte* dataBuffer = (*env)->GetByteArrayElements(env, data, NULL);
    jsize dataSize = (*env)->GetArrayLength(env, data);
    struct TWData dataData = {
        .bytes = (uint8_t *) dataBuffer,
        .len = (size_t) dataSize
    };

    jboolean result = (jboolean) TWPublicKeyInitWithData(instance, dataData);

    (*env)->ReleaseByteArrayElements(env, data, dataBuffer, JNI_ABORT);
    (*env)->ReleaseByteArrayElements(env, bytesArray, (jbyte *) bytesBuffer, JNI_ABORT);

    return result;
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_PublicKey_isValid(JNIEnv *env, jclass thisClass, jbyteArray data) {
    jbyte* dataBuffer = (*env)->GetByteArrayElements(env, data, NULL);
    jsize dataSize = (*env)->GetArrayLength(env, data);
    struct TWData dataData = {
        .bytes = (uint8_t *) dataBuffer,
        .len = (size_t) dataSize
    };

    jboolean resultValue = (jboolean) TWPublicKeyIsValid(dataData);

    (*env)->ReleaseByteArrayElements(env, data, dataBuffer, JNI_ABORT);

    return resultValue;
}


jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_PublicKey_isCompressed(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID bytesFieldID = (*env)->GetFieldID(env, thisClass, "bytes", "[b");
    jbyteArray bytesArray = (*env)->GetObjectField(env, thisObject, bytesFieldID);
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, bytesArray, NULL);
    struct TWPublicKey *instance = (struct TWPublicKey *) bytesBuffer;

    jboolean resultValue = (jboolean) TWPublicKeyIsCompressed(*instance);

    (*env)->ReleaseByteArrayElements(env, bytesArray, bytesBuffer, JNI_ABORT);

    return resultValue;
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_PublicKey_compressed(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID bytesFieldID = (*env)->GetFieldID(env, thisClass, "bytes", "[b");
    jbyteArray bytesArray = (*env)->GetObjectField(env, thisObject, bytesFieldID);
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, bytesArray, NULL);
    struct TWPublicKey *instance = (struct TWPublicKey *) bytesBuffer;

    struct TWPublicKey result = TWPublicKeyCompressed(*instance);

    (*env)->ReleaseByteArrayElements(env, bytesArray, bytesBuffer, JNI_ABORT);

    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/PublicKey");
    jbyteArray resultArray = (*env)->NewByteArray(env, sizeof(struct TWPublicKey));
    (*env)->SetByteArrayRegion(env, resultArray, 0, sizeof(struct TWPublicKey), (jbyte *) &result);
    jmethodID init = (*env)->GetMethodID(env, class, "createFromNative", "([b)V");
    return (*env)->NewObject(env, class, init, resultArray);
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_PublicKey_data(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID bytesFieldID = (*env)->GetFieldID(env, thisClass, "bytes", "[b");
    jbyteArray bytesArray = (*env)->GetObjectField(env, thisObject, bytesFieldID);
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, bytesArray, NULL);
    struct TWPublicKey *instance = (struct TWPublicKey *) bytesBuffer;

    uint8_t resultBuffer[TWPublicKeyUncompressedSize];
    jsize resultSize = (jsize) TWPublicKeyData(*instance, resultBuffer);

    (*env)->ReleaseByteArrayElements(env, bytesArray, bytesBuffer, JNI_ABORT);

    jbyteArray resultArray = (*env)->NewByteArray(env, resultSize);
    (*env)->SetByteArrayRegion(env, resultArray, 0, resultSize, (jbyte *) resultBuffer);
    return resultArray;
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_PublicKey_verify(JNIEnv *env, jobject thisObject, jbyteArray signature, jbyteArray message) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID bytesFieldID = (*env)->GetFieldID(env, thisClass, "bytes", "[b");
    jbyteArray bytesArray = (*env)->GetObjectField(env, thisObject, bytesFieldID);
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, bytesArray, NULL);
    struct TWPublicKey *instance = (struct TWPublicKey *) bytesBuffer;

    jbyte* signatureBuffer = (*env)->GetByteArrayElements(env, signature, NULL);
    jsize signatureSize = (*env)->GetArrayLength(env, signature);
    struct TWData signatureData = {
        .bytes = (uint8_t *) signatureBuffer,
        .len = (size_t) signatureSize
    };

    jbyte* messageBuffer = (*env)->GetByteArrayElements(env, message, NULL);
    jsize messageSize = (*env)->GetArrayLength(env, message);
    struct TWData messageData = {
        .bytes = (uint8_t *) messageBuffer,
        .len = (size_t) messageSize
    };

    jboolean resultValue = (jboolean) TWPublicKeyVerify(*instance, signatureData, messageData);

    (*env)->ReleaseByteArrayElements(env, signature, signatureBuffer, JNI_ABORT);
    (*env)->ReleaseByteArrayElements(env, message, messageBuffer, JNI_ABORT);
    (*env)->ReleaseByteArrayElements(env, bytesArray, bytesBuffer, JNI_ABORT);

    return resultValue;
}

