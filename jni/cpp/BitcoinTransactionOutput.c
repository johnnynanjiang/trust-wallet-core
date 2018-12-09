// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWBitcoinTransactionOutput.h>
#include "TWJNI.h"
#include "BitcoinTransactionOutput.h"

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionOutput_nativeCreate(JNIEnv *env, jclass thisClass, jlong value, jobject script) {
    jclass scriptClass = (*env)->GetObjectClass(env, script);
    jfieldID scriptHandleFieldID = (*env)->GetFieldID(env, scriptClass, "nativeHandle", "J");
    struct TWBitcoinScript *scriptInstance = (struct TWBitcoinScript *) (*env)->GetLongField(env, script, scriptHandleFieldID);
    struct TWBitcoinTransactionOutput *instance = TWBitcoinTransactionOutputCreate(value, scriptInstance);
    return (jlong) instance;
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionOutput_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWBitcoinTransactionOutputDelete((struct TWBitcoinTransactionOutput *) handle);
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionOutput_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs) {
    jclass lhsClass = (*env)->GetObjectClass(env, lhs);
    jfieldID lhsHandleFieldID = (*env)->GetFieldID(env, lhsClass, "nativeHandle", "J");
    struct TWBitcoinTransactionOutput *lhsInstance = (struct TWBitcoinTransactionOutput *) (*env)->GetLongField(env, lhs, lhsHandleFieldID);
    jclass rhsClass = (*env)->GetObjectClass(env, rhs);
    jfieldID rhsHandleFieldID = (*env)->GetFieldID(env, rhsClass, "nativeHandle", "J");
    struct TWBitcoinTransactionOutput *rhsInstance = (struct TWBitcoinTransactionOutput *) (*env)->GetLongField(env, rhs, rhsHandleFieldID);
    jboolean resultValue = (jboolean) TWBitcoinTransactionOutputEqual(lhsInstance, rhsInstance);

    return resultValue;
}


jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionOutput_amount(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransactionOutput *instance = (struct TWBitcoinTransactionOutput *) (*env)->GetLongField(env, thisObject, handleFieldID);
    jlong resultValue = (jlong) TWBitcoinTransactionOutputAmount(instance);
    return resultValue;
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionOutput_script(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransactionOutput *instance = (struct TWBitcoinTransactionOutput *) (*env)->GetLongField(env, thisObject, handleFieldID);
    struct TWBitcoinScript result = TWBitcoinTransactionOutputScript(instance);
    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/BitcoinScript");
    jmethodID init = (*env)->GetMethodID(env, class, "createFromNative", "(J)V");
    return (*env)->NewObject(env, class, init, (jlong) result);
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionOutput_encode(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransactionOutput *instance = (struct TWBitcoinTransactionOutput *) (*env)->GetLongField(env, thisObject, handleFieldID);
    jbyteArray resultValue = TWDataJByteArray(TWBitcoinTransactionOutputEncode(instance), env);
    return resultValue;
}

