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

#include <TrustWalletCore/TWBitcoinTransaction.h>

#include "TWJNI.h"
#include "BitcoinTransaction.h"

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_nativeCreate(JNIEnv *env, jclass thisClass, jint version, jint lockTime) {
    struct TWBitcoinTransaction *instance = TWBitcoinTransactionCreate(version, lockTime);
    return (jlong) instance;
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWBitcoinTransactionDelete((struct TWBitcoinTransaction *) handle);
}

jint JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_lockTime(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWBitcoinTransactionLockTime(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jsize JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_inputCount(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jsize resultValue = (jsize) TWBitcoinTransactionInputCount(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jsize JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_outputCount(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jsize resultValue = (jsize) TWBitcoinTransactionOutputCount(instance);


    (*env)->DeleteLocalRef(env, thisClass);

    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_hash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = TWDataJByteArray(TWBitcoinTransactionHash(instance), env);


    (*env)->DeleteLocalRef(env, thisClass);

    return result;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_witnessHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = TWDataJByteArray(TWBitcoinTransactionWitnessHash(instance), env);


    (*env)->DeleteLocalRef(env, thisClass);

    return result;
}

jstring JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_identifier(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = TWStringJString(TWBitcoinTransactionIdentifier(instance), env);


    (*env)->DeleteLocalRef(env, thisClass);

    return result;
}

jstring JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_witnessIdentifier(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = TWStringJString(TWBitcoinTransactionWitnessIdentifier(instance), env);


    (*env)->DeleteLocalRef(env, thisClass);

    return result;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_encode(JNIEnv *env, jobject thisObject, jboolean witness) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray result = TWDataJByteArray(TWBitcoinTransactionEncode(instance, witness), env);


    (*env)->DeleteLocalRef(env, thisClass);

    return result;
}

