// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWZcashTransaction.h>

#include "TWJNI.h"
#include "ZcashTransaction.h"

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_ZcashTransaction_nativeCreate(JNIEnv *env, jclass thisClass) {
    struct TWZcashTransaction *instance = TWZcashTransactionCreate();
    return (jlong) instance;
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_ZcashTransaction_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWZcashTransactionDelete((struct TWZcashTransaction *) handle);
}

jint JNICALL Java_com_wallet_crypto_trustapp_jni_ZcashTransaction_lockTime(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWZcashTransaction *instance = (struct TWZcashTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWZcashTransactionLockTime(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jsize JNICALL Java_com_wallet_crypto_trustapp_jni_ZcashTransaction_inputCount(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWZcashTransaction *instance = (struct TWZcashTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jsize resultValue = (jsize) TWZcashTransactionInputCount(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jsize JNICALL Java_com_wallet_crypto_trustapp_jni_ZcashTransaction_outputCount(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWZcashTransaction *instance = (struct TWZcashTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jsize resultValue = (jsize) TWZcashTransactionOutputCount(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_ZcashTransaction_hash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWZcashTransaction *instance = (struct TWZcashTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = TWDataJByteArray(TWZcashTransactionHash(instance), env);


    (*env)->DeleteLocalRef(env, thisClass);

    return result;
}

jstring JNICALL Java_com_wallet_crypto_trustapp_jni_ZcashTransaction_identifier(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWZcashTransaction *instance = (struct TWZcashTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = TWStringJString(TWZcashTransactionIdentifier(instance), env);


    (*env)->DeleteLocalRef(env, thisClass);

    return result;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_ZcashTransaction_encode(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWZcashTransaction *instance = (struct TWZcashTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = TWDataJByteArray(TWZcashTransactionEncode(instance), env);


    (*env)->DeleteLocalRef(env, thisClass);

    return result;
}

