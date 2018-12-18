// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWBitcoinOutPoint.h>
#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWBitcoinTransactionInput.h>

#include "TWJNI.h"
#include "BitcoinTransactionInput.h"

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionInput_nativeCreate(JNIEnv *env, jclass thisClass, jobject previousOutput, jobject script, jint sequence) {
    jclass previousOutputClass = (*env)->GetObjectClass(env, previousOutput);
    jfieldID previousOutputBytesFieldID = (*env)->GetFieldID(env, previousOutputClass, "bytes", "[B");
    jbyteArray previousOutputBytesArray = (*env)->GetObjectField(env, previousOutput, previousOutputBytesFieldID);
    jbyte* previousOutputBytesBuffer = (*env)->GetByteArrayElements(env, previousOutputBytesArray, NULL);
    struct TWBitcoinOutPoint *previousOutputInstance = (struct TWBitcoinOutPoint *) previousOutputBytesBuffer;
    jclass scriptClass = (*env)->GetObjectClass(env, script);
    jfieldID scriptHandleFieldID = (*env)->GetFieldID(env, scriptClass, "nativeHandle", "J");
    struct TWBitcoinScript *scriptInstance = (struct TWBitcoinScript *) (*env)->GetLongField(env, script, scriptHandleFieldID);
    struct TWBitcoinTransactionInput *instance = TWBitcoinTransactionInputCreate(*previousOutputInstance, scriptInstance, sequence);
    (*env)->ReleaseByteArrayElements(env, previousOutputBytesArray, previousOutputBytesBuffer, JNI_ABORT);
    return (jlong) instance;
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionInput_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWBitcoinTransactionInputDelete((struct TWBitcoinTransactionInput *) handle);
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionInput_previousOutput(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransactionInput *instance = (struct TWBitcoinTransactionInput *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWBitcoinOutPoint result = TWBitcoinTransactionInputPreviousOutput(instance);
    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/BitcoinOutPoint");
    jbyteArray resultArray = (*env)->NewByteArray(env, sizeof(struct TWBitcoinOutPoint));
    (*env)->SetByteArrayRegion(env, resultArray, 0, sizeof(struct TWBitcoinOutPoint), (jbyte *) &result);
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "([B)Lcom/wallet/crypto/trustapp/jni/BitcoinOutPoint;");
    return (*env)->CallStaticObjectMethod(env, class, method, resultArray);
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionInput_script(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransactionInput *instance = (struct TWBitcoinTransactionInput *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWBitcoinScript *result = TWBitcoinTransactionInputScript(instance);
    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/BitcoinScript");
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lcom/wallet/crypto/trustapp/jni/BitcoinScript;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jint JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionInput_sequence(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransactionInput *instance = (struct TWBitcoinTransactionInput *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWBitcoinTransactionInputSequence(instance);
    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionInput_encode(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransactionInput *instance = (struct TWBitcoinTransactionInput *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray resultValue = TWDataJByteArray(TWBitcoinTransactionInputEncode(instance), env);
    return resultValue;
}
