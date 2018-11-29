// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWData.h>
#include <TrustWalletCore/TWBitcoinScript.h>
#include "BitcoinScript.h"

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_nativeCreate(JNIEnv *env, jclass thisClass, jbyteArray data) {
    jbyte* dataBuffer = (*env)->GetByteArrayElements(env, data, NULL);
    jsize dataSize = (*env)->GetArrayLength(env, data);
    struct TWData dataData = {
        .bytes = (uint8_t *) dataBuffer,
        .len = (size_t) dataSize
    };

    struct TWBitcoinScript *instance = TWBitcoinScriptCreate(dataData);

    (*env)->ReleaseByteArrayElements(env, data, dataBuffer, JNI_ABORT);
    return (jlong) instance;
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWBitcoinScriptDelete((struct TWBitcoinScript *) handle);
}


jsize JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_size(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jsize resultValue = (jsize) TWBitcoinScriptSize(instance);


    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_data(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    uint8_t *resultBuffer = (uint8_t *) malloc(TWBitcoinScriptData(instance, resultBuffer));
    jsize resultSize = (jsize) TWBitcoinScriptData(instance, resultBuffer);

    jbyteArray resultArray = (*env)->NewByteArray(env, resultSize);
    (*env)->SetByteArrayRegion(env, resultArray, 0, resultSize, (jbyte *) resultBuffer);
    free(resultBuffer);
    return resultArray;
}

