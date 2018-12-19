// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

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
    return resultValue;
}

jsize JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_inputCount(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jsize resultValue = (jsize) TWBitcoinTransactionInputCount(instance);
    return resultValue;
}

jsize JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_outputCount(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jsize resultValue = (jsize) TWBitcoinTransactionOutputCount(instance);
    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_hash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray resultValue = TWDataJByteArray(TWBitcoinTransactionHash(instance), env);
    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_witnessHash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray resultValue = TWDataJByteArray(TWBitcoinTransactionWitnessHash(instance), env);
    return resultValue;
}

jstring JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_identifier(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = TWStringJString(TWBitcoinTransactionIdentifier(instance), env);
    return result;
}

jstring JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_witnessIdentifier(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = TWStringJString(TWBitcoinTransactionWitnessIdentifier(instance), env);
    return result;
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_getInput(JNIEnv *env, jobject thisObject, jsize index) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWBitcoinTransactionInput *result = TWBitcoinTransactionGetInput(instance, index);
    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/BitcoinTransactionInput");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lcom/wallet/crypto/trustapp/jni/BitcoinTransactionInput;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_addInput(JNIEnv *env, jobject thisObject, jobject previousOutput, jobject script, jint sequence) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass previousOutputClass = (*env)->GetObjectClass(env, previousOutput);
    jfieldID previousOutputBytesFieldID = (*env)->GetFieldID(env, previousOutputClass, "bytes", "[B");
    jbyteArray previousOutputBytesArray = (*env)->GetObjectField(env, previousOutput, previousOutputBytesFieldID);
    jbyte* previousOutputBytesBuffer = (*env)->GetByteArrayElements(env, previousOutputBytesArray, NULL);
    struct TWBitcoinOutPoint *previousOutputInstance = (struct TWBitcoinOutPoint *) previousOutputBytesBuffer;
    jclass scriptClass = (*env)->GetObjectClass(env, script);
    jfieldID scriptHandleFieldID = (*env)->GetFieldID(env, scriptClass, "nativeHandle", "J");
    struct TWBitcoinScript *scriptInstance = (struct TWBitcoinScript *) (*env)->GetLongField(env, script, scriptHandleFieldID);
    TWBitcoinTransactionAddInput(instance, *previousOutputInstance, scriptInstance, sequence);
    (*env)->ReleaseByteArrayElements(env, previousOutputBytesArray, previousOutputBytesBuffer, JNI_ABORT);
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_getOutput(JNIEnv *env, jobject thisObject, jsize index) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWBitcoinTransactionOutput *result = TWBitcoinTransactionGetOutput(instance, index);
    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/BitcoinTransactionOutput");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lcom/wallet/crypto/trustapp/jni/BitcoinTransactionOutput;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_addOutput(JNIEnv *env, jobject thisObject, jlong value, jobject script) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass scriptClass = (*env)->GetObjectClass(env, script);
    jfieldID scriptHandleFieldID = (*env)->GetFieldID(env, scriptClass, "nativeHandle", "J");
    struct TWBitcoinScript *scriptInstance = (struct TWBitcoinScript *) (*env)->GetLongField(env, script, scriptHandleFieldID);
    TWBitcoinTransactionAddOutput(instance, value, scriptInstance);
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransaction_encode(JNIEnv *env, jobject thisObject, jboolean witness) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *instance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray resultValue = TWDataJByteArray(TWBitcoinTransactionEncode(instance, witness), env);
    return resultValue;
}

