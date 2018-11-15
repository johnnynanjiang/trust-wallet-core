// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWData.h>
#include <TrustWalletCore/TWPrivateKey.h>
#include "PrivateKey.h"

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_nativeCreateWithData(JNIEnv *env, jclass thisClass, jbyteArray array) {
    jbyte* bufferPtr = (*env)->GetByteArrayElements(env, array, NULL);
    jsize lengthOfArray = (*env)->GetArrayLength(env, array);
    struct TWData data = {
        .bytes = (uint8_t *) bufferPtr,
        .len = (size_t) lengthOfArray
    };

    struct TWPrivateKey * privateKey = TWPrivateKeyCreateWithData(&data);

    (*env)->ReleaseByteArrayElements(env, array, bufferPtr, JNI_ABORT);

    return (jlong)privateKey;
}

JNIEXPORT
void JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_delete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWPrivateKeyFree((struct TWPrivateKey *) handle);
}

JNIEXPORT
jbyteArray Java_com_wallet_crypto_trustapp_jni_PrivateKey_getBytes(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID fieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWPrivateKey * key = (struct TWPrivateKey *) (*env)->GetLongField(env, thisObject, fieldID);

    uint8_t bytes[TWPrivateKeySize];
    TWPrivateKeyCopyBytes(key, bytes);

    jbyteArray array = (*env)->NewByteArray(env, TWPrivateKeySize);
    (*env)->SetByteArrayRegion(env, array, 0, TWPrivateKeySize, bytes);

    // Clear private key on stack before returning
    memset(bytes, 0, TWPrivateKeySize);

    return array;
}
