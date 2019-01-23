// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWBitcoinTransactionSigner.h>

#include "TWJNI.h"
#include "BitcoinTransactionSigner.h"

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionSigner_nativeCreate(JNIEnv *env, jclass thisClass, jbyteArray input) {
    jclass inputClass = (*env)->GetObjectClass(env, input);
    jmethodID inputToByteArrayMethodID = (*env)->GetMethodID(env, inputClass, "toByteArray", "()[B");
    jbyteArray inputByteArray = (*env)->CallObjectMethod(env, input, inputToByteArrayMethodID);
    struct TWBitcoinTransactionSigner *instance = TWBitcoinTransactionSignerCreate(inputByteArray);
    (*env)->DeleteLocalRef(env, inputByteArray);
    (*env)->DeleteLocalRef(env, inputClass);
    return (jlong) instance;
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionSigner_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWBitcoinTransactionSignerDelete((struct TWBitcoinTransactionSigner *) handle);
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinTransactionSigner_sign(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinTransactionSigner *instance = (struct TWBitcoinTransactionSigner *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWBitcoinTransaction *result = TWBitcoinTransactionSignerSign(instance);

    (*env)->DeleteLocalRef(env, thisClass);

    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/BitcoinTransaction");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lcom/wallet/crypto/trustapp/jni/BitcoinTransaction;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

