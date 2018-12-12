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
#include <TrustWalletCore/TWBitcoinTransactionOutput.h>
#include <TrustWalletCore/TWBitcoinUnspentTransaction.h>

#include "TWJNI.h"
#include "BitcoinUnspentTransaction.h"

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinUnspentTransaction_nativeCreateWithOutput(JNIEnv *env, jclass thisClass, jobject outpoint, jobject output) {
    jclass outpointClass = (*env)->GetObjectClass(env, outpoint);
    jfieldID outpointBytesFieldID = (*env)->GetFieldID(env, outpointClass, "bytes", "[B");
    jbyteArray outpointBytesArray = (*env)->GetObjectField(env, outpoint, outpointBytesFieldID);
    jbyte* outpointBytesBuffer = (*env)->GetByteArrayElements(env, outpointBytesArray, NULL);
    struct TWBitcoinOutPoint *outpointInstance = (struct TWBitcoinOutPoint *) outpointBytesBuffer;
    jclass outputClass = (*env)->GetObjectClass(env, output);
    jfieldID outputHandleFieldID = (*env)->GetFieldID(env, outputClass, "nativeHandle", "J");
    struct TWBitcoinTransactionOutput *outputInstance = (struct TWBitcoinTransactionOutput *) (*env)->GetLongField(env, output, outputHandleFieldID);
    struct TWBitcoinUnspentTransaction *instance = TWBitcoinUnspentTransactionCreateWithOutput(*outpointInstance, outputInstance);
    (*env)->ReleaseByteArrayElements(env, outpointBytesArray, outpointBytesBuffer, JNI_ABORT);
    return (jlong) instance;
}

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinUnspentTransaction_nativeCreate(JNIEnv *env, jclass thisClass, jbyteArray hash, jint index, jobject script, jlong amount) {
    TWData *hashData = TWDataCreateWithJByteArray(env, hash);
    jclass scriptClass = (*env)->GetObjectClass(env, script);
    jfieldID scriptHandleFieldID = (*env)->GetFieldID(env, scriptClass, "nativeHandle", "J");
    struct TWBitcoinScript *scriptInstance = (struct TWBitcoinScript *) (*env)->GetLongField(env, script, scriptHandleFieldID);
    struct TWBitcoinUnspentTransaction *instance = TWBitcoinUnspentTransactionCreate(hashData, index, scriptInstance, amount);
    TWDataDelete(hashData);
    return (jlong) instance;
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinUnspentTransaction_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWBitcoinUnspentTransactionDelete((struct TWBitcoinUnspentTransaction *) handle);
}


jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinUnspentTransaction_outPoint(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinUnspentTransaction *instance = (struct TWBitcoinUnspentTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWBitcoinOutPoint result = TWBitcoinUnspentTransactionOutPoint(instance);
    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/BitcoinOutPoint");
    jbyteArray resultArray = (*env)->NewByteArray(env, sizeof(struct TWBitcoinOutPoint));
    (*env)->SetByteArrayRegion(env, resultArray, 0, sizeof(struct TWBitcoinOutPoint), (jbyte *) &result);
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "([B)Lcom/wallet/crypto/trustapp/jni/BitcoinOutPoint;");
    return (*env)->CallStaticObjectMethod(env, class, method, resultArray);
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinUnspentTransaction_output(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinUnspentTransaction *instance = (struct TWBitcoinUnspentTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWBitcoinTransactionOutput *result = TWBitcoinUnspentTransactionOutput(instance);
    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/BitcoinTransactionOutput");
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lcom/wallet/crypto/trustapp/jni/BitcoinTransactionOutput;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinUnspentTransaction_amount(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinUnspentTransaction *instance = (struct TWBitcoinUnspentTransaction *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jlong resultValue = (jlong) TWBitcoinUnspentTransactionAmount(instance);
    return resultValue;
}

