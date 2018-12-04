// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWPrivateKey.h>
#include "TWJNI.h"
#include "PrivateKey.h"

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_nativeCreate(JNIEnv *env, jclass thisClass) {
    currentEnv = env;
    struct TWPrivateKey *instance = TWPrivateKeyCreate();
    return (jlong) instance;
}

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_nativeCreateWithData(JNIEnv *env, jclass thisClass, jbyteArray data) {
    currentEnv = env;
    struct TWPrivateKey *instance = TWPrivateKeyCreateWithData(data);
    return (jlong) instance;
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    currentEnv = env;
    TWPrivateKeyDelete((struct TWPrivateKey *) handle);
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_isValid(JNIEnv *env, jclass thisClass, jbyteArray data) {
    currentEnv = env;
    jboolean resultValue = (jboolean) TWPrivateKeyIsValid(data);

    return resultValue;
}


jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_data(JNIEnv *env, jobject thisObject) {
    currentEnv = env;
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray resultValue = (jbyteArray) TWPrivateKeyData(instance);

    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_sign(JNIEnv *env, jobject thisObject, jbyteArray digest) {
    currentEnv = env;
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray resultValue = (jbyteArray) TWPrivateKeySign(instance, digest);

    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_signAsDER(JNIEnv *env, jobject thisObject, jbyteArray digest) {
    currentEnv = env;
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey *instance = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray resultValue = (jbyteArray) TWPrivateKeySignAsDER(instance, digest);

    return resultValue;
}

