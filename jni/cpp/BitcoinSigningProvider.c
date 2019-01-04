// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWBitcoinSigningProvider.h>

#include "TWJNI.h"
#include "BitcoinSigningProvider.h"

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinSigningProvider_nativeCreate(JNIEnv *env, jclass thisClass) {
    struct TWBitcoinSigningProvider *instance = TWBitcoinSigningProviderCreate();
    return (jlong) instance;
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinSigningProvider_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWBitcoinSigningProviderDelete((struct TWBitcoinSigningProvider *) handle);
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinSigningProvider_addKey(JNIEnv *env, jobject thisObject, jobject key) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinSigningProvider *instance = (struct TWBitcoinSigningProvider *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jclass keyClass = (*env)->GetObjectClass(env, key);
    jfieldID keyHandleFieldID = (*env)->GetFieldID(env, keyClass, "nativeHandle", "J");
    struct TWPrivateKey *keyInstance = (struct TWPrivateKey *) (*env)->GetLongField(env, key, keyHandleFieldID);
    TWBitcoinSigningProviderAddKey(instance, keyInstance);
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinSigningProvider_addRedeemScript(JNIEnv *env, jobject thisObject, jbyteArray hash, jobject script) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWBitcoinSigningProvider *instance = (struct TWBitcoinSigningProvider *) (*env)->GetLongField(env, thisObject, handleFieldID);

    TWData *hashData = TWDataCreateWithJByteArray(env, hash);
    jclass scriptClass = (*env)->GetObjectClass(env, script);
    jfieldID scriptHandleFieldID = (*env)->GetFieldID(env, scriptClass, "nativeHandle", "J");
    struct TWBitcoinScript *scriptInstance = (struct TWBitcoinScript *) (*env)->GetLongField(env, script, scriptHandleFieldID);
    TWBitcoinSigningProviderAddRedeemScript(instance, hashData, scriptInstance);
    TWDataDelete(hashData);
}

