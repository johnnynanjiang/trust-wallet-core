// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <TrustWalletCore/TWData.h>
#include <TrustWalletCore/TWPrivateKey.h>
#include "PrivateKey.h"

JNIEXPORT
jlong JNICALL Java_com_wallet_crypto_trustapp_jni_PrivateKey_nativeCreateWithData(JNIEnv *env, jclass thisClas, jbyteArray array) {
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
