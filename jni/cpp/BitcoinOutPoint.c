// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWBitcoinOutPoint.h>

#include "TWJNI.h"
#include "BitcoinOutPoint.h"

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinOutPoint_initWithHash(JNIEnv *env, jclass thisObject, jbyteArray hash, jint index) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID bytesFieldID = (*env)->GetFieldID(env, thisClass, "bytes", "[B");
    jbyteArray bytesArray = (*env)->GetObjectField(env, thisObject, bytesFieldID);
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, bytesArray, NULL);
    struct TWBitcoinOutPoint *instance = (struct TWBitcoinOutPoint *) bytesBuffer;

    TWData *hashData = TWDataCreateWithJByteArray(env, hash);
    jboolean result = (jboolean) TWBitcoinOutPointInitWithHash(instance, hashData, index);
    TWDataDelete(hashData);
    (*env)->ReleaseByteArrayElements(env, bytesArray, bytesBuffer, JNI_ABORT);

    return result;
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinOutPoint_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs) {
    jclass lhsClass = (*env)->GetObjectClass(env, lhs);
    jfieldID lhsBytesFieldID = (*env)->GetFieldID(env, lhsClass, "bytes", "[B");
    jbyteArray lhsBytesArray = (*env)->GetObjectField(env, lhs, lhsBytesFieldID);
    jbyte* lhsBytesBuffer = (*env)->GetByteArrayElements(env, lhsBytesArray, NULL);
    struct TWBitcoinOutPoint *lhsInstance = (struct TWBitcoinOutPoint *) lhsBytesBuffer;
    jclass rhsClass = (*env)->GetObjectClass(env, rhs);
    jfieldID rhsBytesFieldID = (*env)->GetFieldID(env, rhsClass, "bytes", "[B");
    jbyteArray rhsBytesArray = (*env)->GetObjectField(env, rhs, rhsBytesFieldID);
    jbyte* rhsBytesBuffer = (*env)->GetByteArrayElements(env, rhsBytesArray, NULL);
    struct TWBitcoinOutPoint *rhsInstance = (struct TWBitcoinOutPoint *) rhsBytesBuffer;
    jboolean resultValue = (jboolean) TWBitcoinOutPointEqual(*lhsInstance, *rhsInstance);
    (*env)->ReleaseByteArrayElements(env, lhsBytesArray, lhsBytesBuffer, JNI_ABORT);
    (*env)->ReleaseByteArrayElements(env, rhsBytesArray, rhsBytesBuffer, JNI_ABORT);

    return resultValue;
}


jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinOutPoint_hash(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID bytesFieldID = (*env)->GetFieldID(env, thisClass, "bytes", "[B");
    jbyteArray bytesArray = (*env)->GetObjectField(env, thisObject, bytesFieldID);
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, bytesArray, NULL);
    struct TWBitcoinOutPoint *instance = (struct TWBitcoinOutPoint *) bytesBuffer;
    jbyteArray resultValue = TWDataJByteArray(TWBitcoinOutPointHash(*instance), env);
    (*env)->ReleaseByteArrayElements(env, bytesArray, bytesBuffer, JNI_ABORT);

    return resultValue;
}

jint JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinOutPoint_index(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID bytesFieldID = (*env)->GetFieldID(env, thisClass, "bytes", "[B");
    jbyteArray bytesArray = (*env)->GetObjectField(env, thisObject, bytesFieldID);
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, bytesArray, NULL);
    struct TWBitcoinOutPoint *instance = (struct TWBitcoinOutPoint *) bytesBuffer;
    jint resultValue = (jint) TWBitcoinOutPointIndex(*instance);
    (*env)->ReleaseByteArrayElements(env, bytesArray, bytesBuffer, JNI_ABORT);

    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_BitcoinOutPoint_encode(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID bytesFieldID = (*env)->GetFieldID(env, thisClass, "bytes", "[B");
    jbyteArray bytesArray = (*env)->GetObjectField(env, thisObject, bytesFieldID);
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, bytesArray, NULL);
    struct TWBitcoinOutPoint *instance = (struct TWBitcoinOutPoint *) bytesBuffer;
    jbyteArray resultValue = TWDataJByteArray(TWBitcoinOutPointEncode(*instance), env);
    (*env)->ReleaseByteArrayElements(env, bytesArray, bytesBuffer, JNI_ABORT);

    return resultValue;
}

