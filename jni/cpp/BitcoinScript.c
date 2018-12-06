// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWBitcoinScript.h>
#include "TWJNI.h"
#include "BitcoinScript.h"

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_nativeCreate(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    struct TWBitcoinScript *instance = TWBitcoinScriptCreate(dataData);
    TWDataDelete(dataData);
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
    TWData *hashData = TWDataCreateWithJByteArray(env, hash);
    struct TWBitcoinScript *result = TWBitcoinScriptBuildPayToPublicKeyHash(hashData);
    TWDataDelete(hashData);

    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/BitcoinScript");
    jmethodID init = (*env)->GetMethodID(env, class, "createFromNative", "(J)V");
    return (*env)->NewObject(env, class, init, (jlong) result);
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_buildPayToScriptHash(JNIEnv *env, jclass thisClass, jbyteArray scriptHash) {
    TWData *scriptHashData = TWDataCreateWithJByteArray(env, scriptHash);
    struct TWBitcoinScript *result = TWBitcoinScriptBuildPayToScriptHash(scriptHashData);
    TWDataDelete(scriptHashData);

    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/BitcoinScript");
    jmethodID init = (*env)->GetMethodID(env, class, "createFromNative", "(J)V");
    return (*env)->NewObject(env, class, init, (jlong) result);
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_buildPayToWitnessPubkeyHash(JNIEnv *env, jclass thisClass, jbyteArray hash) {
    TWData *hashData = TWDataCreateWithJByteArray(env, hash);
    struct TWBitcoinScript *result = TWBitcoinScriptBuildPayToWitnessPubkeyHash(hashData);
    TWDataDelete(hashData);

    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/BitcoinScript");
    jmethodID init = (*env)->GetMethodID(env, class, "createFromNative", "(J)V");
    return (*env)->NewObject(env, class, init, (jlong) result);
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_buildPayToWitnessScriptHash(JNIEnv *env, jclass thisClass, jbyteArray scriptHash) {
    TWData *scriptHashData = TWDataCreateWithJByteArray(env, scriptHash);
    struct TWBitcoinScript *result = TWBitcoinScriptBuildPayToWitnessScriptHash(scriptHashData);
    TWDataDelete(scriptHashData);

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
    jbyteArray resultValue = TWDataJByteArray(TWBitcoinScriptData(instance), env);
    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_scriptHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);
    jbyteArray resultValue = TWDataJByteArray(TWBitcoinScriptScriptHash(instance), env);
    return resultValue;
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
    jbyteArray resultValue = TWDataJByteArray(TWBitcoinScriptMatchPayToPubkey(instance), env);
    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_matchPayToPubkeyHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);
    jbyteArray resultValue = TWDataJByteArray(TWBitcoinScriptMatchPayToPubkeyHash(instance), env);
    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_matchPayToScriptHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);
    jbyteArray resultValue = TWDataJByteArray(TWBitcoinScriptMatchPayToScriptHash(instance), env);
    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_matchPayToWitnessPublicKeyHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);
    jbyteArray resultValue = TWDataJByteArray(TWBitcoinScriptMatchPayToWitnessPublicKeyHash(instance), env);
    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_matchPayToWitnessScriptHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);
    jbyteArray resultValue = TWDataJByteArray(TWBitcoinScriptMatchPayToWitnessScriptHash(instance), env);
    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinScript_encode(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinScript *instance = (struct TWBitcoinScript *) (*env)->GetLongField(env, thisObject, handleFieldID);
    jbyteArray resultValue = TWDataJByteArray(TWBitcoinScriptEncode(instance), env);
    return resultValue;
}

