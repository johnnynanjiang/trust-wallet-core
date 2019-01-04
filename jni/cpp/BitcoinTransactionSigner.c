// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWBitcoinSigningProvider.h>
#include <TrustWalletCore/TWBitcoinTransaction.h>
#include <TrustWalletCore/TWBitcoinTransactionSigner.h>

#include "TWJNI.h"
#include "BitcoinTransactionSigner.h"

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionSigner_nativeCreate(JNIEnv *env, jclass thisClass, jobject provider, jobject transaction, jint hashType) {
    jclass providerClass = (*env)->GetObjectClass(env, provider);
    jfieldID providerHandleFieldID = (*env)->GetFieldID(env, providerClass, "nativeHandle", "J");
    struct TWBitcoinSigningProvider *providerInstance = (struct TWBitcoinSigningProvider *) (*env)->GetLongField(env, provider, providerHandleFieldID);
    jclass transactionClass = (*env)->GetObjectClass(env, transaction);
    jfieldID transactionHandleFieldID = (*env)->GetFieldID(env, transactionClass, "nativeHandle", "J");
    struct TWBitcoinTransaction *transactionInstance = (struct TWBitcoinTransaction *) (*env)->GetLongField(env, transaction, transactionHandleFieldID);
    struct TWBitcoinTransactionSigner *instance = TWBitcoinTransactionSignerCreate(providerInstance, transactionInstance, hashType);
    return (jlong) instance;
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionSigner_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWBitcoinTransactionSignerDelete((struct TWBitcoinTransactionSigner *) handle);
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionSigner_addUnspent(JNIEnv *env, jobject thisObject, jobject outPoint, jobject script, jlong amount) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransactionSigner *instance = (struct TWBitcoinTransactionSigner *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass outPointClass = (*env)->GetObjectClass(env, outPoint);
    jfieldID outPointBytesFieldID = (*env)->GetFieldID(env, outPointClass, "bytes", "[B");
    jbyteArray outPointBytesArray = (*env)->GetObjectField(env, outPoint, outPointBytesFieldID);
    jbyte* outPointBytesBuffer = (*env)->GetByteArrayElements(env, outPointBytesArray, NULL);
    struct TWBitcoinOutPoint *outPointInstance = (struct TWBitcoinOutPoint *) outPointBytesBuffer;
    jclass scriptClass = (*env)->GetObjectClass(env, script);
    jfieldID scriptHandleFieldID = (*env)->GetFieldID(env, scriptClass, "nativeHandle", "J");
    struct TWBitcoinScript *scriptInstance = (struct TWBitcoinScript *) (*env)->GetLongField(env, script, scriptHandleFieldID);
    TWBitcoinTransactionSignerAddUnspent(instance, *outPointInstance, scriptInstance, amount);
    (*env)->ReleaseByteArrayElements(env, outPointBytesArray, outPointBytesBuffer, JNI_ABORT);
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionSigner_sign(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransactionSigner *instance = (struct TWBitcoinTransactionSigner *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWBitcoinTransaction *result = TWBitcoinTransactionSignerSign(instance);
    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/BitcoinTransaction");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lcom/wallet/crypto/trustapp/jni/BitcoinTransaction;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

