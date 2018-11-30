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

jchar JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_encodeNumber(JNIEnv *env, jclass thisClass, jint value) {
    jchar resultValue = (jchar) TWBitcoinScriptEncodeNumber(value);

    return resultValue;
}

jint JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_decodeNumber(JNIEnv *env, jclass thisClass, jchar opcode) {
    jint resultValue = (jint) TWBitcoinScriptDecodeNumber(opcode);

    return resultValue;
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_buildPayToPublicKeyHash(JNIEnv *env, jclass thisClass, jbyteArray hash) {
    jbyte* hashBuffer = (*env)->GetByteArrayElements(env, hash, NULL);
    jsize hashSize = (*env)->GetArrayLength(env, hash);
    struct TWData hashData = {
        .bytes = (uint8_t *) hashBuffer,
        .len = (size_t) hashSize
    };

    struct TWBitcoinScript *result = TWBitcoinScriptBuildPayToPublicKeyHash();

    (*env)->ReleaseByteArrayElements(env, hash, hashBuffer, JNI_ABORT);

    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/BitcoinScript");
    jmethodID init = (*env)->GetMethodID(env, class, "createFromNative", "(J)V");
    return (*env)->NewObject(env, class, init, (jlong) result);
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_buildPayToScriptHash(JNIEnv *env, jclass thisClass, jbyteArray scriptHash) {
    jbyte* scriptHashBuffer = (*env)->GetByteArrayElements(env, scriptHash, NULL);
    jsize scriptHashSize = (*env)->GetArrayLength(env, scriptHash);
    struct TWData scriptHashData = {
        .bytes = (uint8_t *) scriptHashBuffer,
        .len = (size_t) scriptHashSize
    };

    struct TWBitcoinScript *result = TWBitcoinScriptBuildPayToScriptHash();

    (*env)->ReleaseByteArrayElements(env, scriptHash, scriptHashBuffer, JNI_ABORT);

    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/BitcoinScript");
    jmethodID init = (*env)->GetMethodID(env, class, "createFromNative", "(J)V");
    return (*env)->NewObject(env, class, init, (jlong) result);
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_buildPayToWitnessPubkeyHash(JNIEnv *env, jclass thisClass, jbyteArray hash) {
    jbyte* hashBuffer = (*env)->GetByteArrayElements(env, hash, NULL);
    jsize hashSize = (*env)->GetArrayLength(env, hash);
    struct TWData hashData = {
        .bytes = (uint8_t *) hashBuffer,
        .len = (size_t) hashSize
    };

    struct TWBitcoinScript *result = TWBitcoinScriptBuildPayToWitnessPubkeyHash();

    (*env)->ReleaseByteArrayElements(env, hash, hashBuffer, JNI_ABORT);

    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/BitcoinScript");
    jmethodID init = (*env)->GetMethodID(env, class, "createFromNative", "(J)V");
    return (*env)->NewObject(env, class, init, (jlong) result);
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_buildPayToWitnessScriptHash(JNIEnv *env, jclass thisClass, jbyteArray scriptHash) {
    jbyte* scriptHashBuffer = (*env)->GetByteArrayElements(env, scriptHash, NULL);
    jsize scriptHashSize = (*env)->GetArrayLength(env, scriptHash);
    struct TWData scriptHashData = {
        .bytes = (uint8_t *) scriptHashBuffer,
        .len = (size_t) scriptHashSize
    };

    struct TWBitcoinScript *result = TWBitcoinScriptBuildPayToWitnessScriptHash();

    (*env)->ReleaseByteArrayElements(env, scriptHash, scriptHashBuffer, JNI_ABORT);

    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/BitcoinScript");
    jmethodID init = (*env)->GetMethodID(env, class, "createFromNative", "(J)V");
    return (*env)->NewObject(env, class, init, (jlong) result);
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

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_scriptHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    uint8_t resultBuffer[20];
    jsize resultSize = (jsize) TWBitcoinScriptScriptHash(instance, resultBuffer);

    jbyteArray resultArray = (*env)->NewByteArray(env, resultSize);
    (*env)->SetByteArrayRegion(env, resultArray, 0, resultSize, (jbyte *) resultBuffer);
    return resultArray;
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_isPayToScriptHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jboolean resultValue = (jboolean) TWBitcoinScriptIsPayToScriptHash(instance);


    return resultValue;
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_isPayToWitnessScriptHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jboolean resultValue = (jboolean) TWBitcoinScriptIsPayToWitnessScriptHash(instance);


    return resultValue;
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_isWitnessProgram(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jboolean resultValue = (jboolean) TWBitcoinScriptIsWitnessProgram(instance);


    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_matchPayToPubkey(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    uint8_t resultBuffer[TWPublicKeyUncompressedSize];
    jsize resultSize = (jsize) TWBitcoinScriptMatchPayToPubkey(instance, resultBuffer);

    jbyteArray resultArray = (*env)->NewByteArray(env, resultSize);
    (*env)->SetByteArrayRegion(env, resultArray, 0, resultSize, (jbyte *) resultBuffer);
    return resultArray;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_matchPayToPubkeyHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    uint8_t *resultBuffer = (uint8_t *) malloc(TWBitcoinScriptMatchPayToPubkeyHash(instance, resultBuffer));
    jsize resultSize = (jsize) TWBitcoinScriptMatchPayToPubkeyHash(instance, resultBuffer);

    jbyteArray resultArray = (*env)->NewByteArray(env, resultSize);
    (*env)->SetByteArrayRegion(env, resultArray, 0, resultSize, (jbyte *) resultBuffer);
    free(resultBuffer);
    return resultArray;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_matchPayToScriptHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    uint8_t *resultBuffer = (uint8_t *) malloc(TWBitcoinScriptMatchPayToScriptHash(instance, resultBuffer));
    jsize resultSize = (jsize) TWBitcoinScriptMatchPayToScriptHash(instance, resultBuffer);

    jbyteArray resultArray = (*env)->NewByteArray(env, resultSize);
    (*env)->SetByteArrayRegion(env, resultArray, 0, resultSize, (jbyte *) resultBuffer);
    free(resultBuffer);
    return resultArray;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_matchPayToWitnessPublicKeyHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    uint8_t *resultBuffer = (uint8_t *) malloc(TWBitcoinScriptMatchPayToWitnessPublicKeyHash(instance, resultBuffer));
    jsize resultSize = (jsize) TWBitcoinScriptMatchPayToWitnessPublicKeyHash(instance, resultBuffer);

    jbyteArray resultArray = (*env)->NewByteArray(env, resultSize);
    (*env)->SetByteArrayRegion(env, resultArray, 0, resultSize, (jbyte *) resultBuffer);
    free(resultBuffer);
    return resultArray;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_matchPayToWitnessScriptHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    uint8_t *resultBuffer = (uint8_t *) malloc(TWBitcoinScriptMatchPayToWitnessScriptHash(instance, resultBuffer));
    jsize resultSize = (jsize) TWBitcoinScriptMatchPayToWitnessScriptHash(instance, resultBuffer);

    jbyteArray resultArray = (*env)->NewByteArray(env, resultSize);
    (*env)->SetByteArrayRegion(env, resultArray, 0, resultSize, (jbyte *) resultBuffer);
    free(resultBuffer);
    return resultArray;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_encode(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);

    uint8_t *resultBuffer = (uint8_t *) malloc(TWBitcoinScriptEncode(instance, resultBuffer));
    jsize resultSize = (jsize) TWBitcoinScriptEncode(instance, resultBuffer);

    jbyteArray resultArray = (*env)->NewByteArray(env, resultSize);
    (*env)->SetByteArrayRegion(env, resultArray, 0, resultSize, (jbyte *) resultBuffer);
    free(resultBuffer);
    return resultArray;
}

