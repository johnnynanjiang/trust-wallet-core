// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWData.h>
#include <TrustWalletCore/TWPublicKey.h>
#include "PublicKey.h"

static inline struct TWPublicKey *getPublicKey(JNIEnv *env, jbyteArray array) {
    jbyte* bufferPtr = (*env)->GetByteArrayElements(env, array, NULL);
    return (struct TWPublicKey *) bufferPtr;
}

static inline jbyteArray getBytes(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID fieldID = (*env)->GetFieldID(env, thisClass, "bytes", "[");
    return (*env)->GetObjectField(env, thisObject, fieldID);
}

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_PublicKey_isValid(JNIEnv *env, jclass thisClass, jbyteArray data) {
    jbyte* bufferPtr = (*env)->GetByteArrayElements(env, data, NULL);
    jsize lengthOfArray = (*env)->GetArrayLength(env, data);
    struct TWData twData = {
            .bytes = (uint8_t *) bufferPtr,
            .len = (size_t) lengthOfArray
    };
    jboolean result = (jboolean) TWPublicKeyIsValid(twData);

    (*env)->ReleaseByteArrayElements(env, data, bufferPtr, JNI_ABORT);

    return result;
}

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_PublicKey_initWithData(JNIEnv *env, jobject thisObject, jbyteArray data) {
    jbyteArray bytes = getBytes(env, thisObject);
    struct TWPublicKey *key = getPublicKey(env, bytes);

    jbyte* bufferPtr = (*env)->GetByteArrayElements(env, data, NULL);
    jsize lengthOfArray = (*env)->GetArrayLength(env, data);
    struct TWData twData = {
            .bytes = (uint8_t *) bufferPtr,
            .len = (size_t) lengthOfArray
    };

    jboolean result = (jboolean) TWPublicKeyInitWithData(key, twData);

    (*env)->ReleaseByteArrayElements(env, bytes, (jbyte *) key, JNI_ABORT);
    (*env)->ReleaseByteArrayElements(env, data, bufferPtr, JNI_ABORT);

    return result;
}

JNIEXPORT
jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_PublicKey_isCompressed(JNIEnv *env, jobject thisObject) {
    jbyteArray bytes = getBytes(env, thisObject);
    struct TWPublicKey *key = getPublicKey(env, bytes);

    jboolean result = (jboolean) TWPublicKeyIsCompressed(*key);
    (*env)->ReleaseByteArrayElements(env, bytes, (jbyte *) key, JNI_ABORT);

    return result;
}

JNIEXPORT
jobject JNICALL Java_com_wallet_crypto_trustapp_jni_PublicKey_compressed(JNIEnv *env, jobject thisObject) {
    jbyteArray bytes = getBytes(env, thisObject);
    struct TWPublicKey *key = getPublicKey(env, bytes);

    struct TWPublicKey newKey;
    TWPublicKeyCompressedCopy(*key, &newKey);

    (*env)->ReleaseByteArrayElements(env, bytes, (jbyte *) key, JNI_ABORT);

    jbyteArray resultArray = (*env)->NewByteArray(env, sizeof(struct TWPublicKey));
    (*env)->SetByteArrayRegion(env, resultArray, 0, sizeof(struct TWPublicKey), (jbyte *) newKey.bytes);

    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/PublicKey");
    jmethodID init = (*env)->GetMethodID(env, class, "<init>", "([b)V");
    return (*env)->NewObject(env, class, init);
}
