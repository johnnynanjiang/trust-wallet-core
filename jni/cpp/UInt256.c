// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWData.h>
#include <TrustWalletCore/TWUInt256.h>
#include "UInt256.h"

static struct TWUInt256 *load(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID fieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    return (struct TWUInt256 *) (*env)->GetLongField(env, thisObject, fieldID);
}

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_nativeCreateZero(JNIEnv *env, jclass thisClass) {
    struct TWUInt256 * ptr = TWUInt256Zero();
    return (jlong) ptr;
}

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_nativeCreateOne(JNIEnv *env, jclass thisClass) {
    struct TWUInt256 * ptr = TWUInt256One();
    return (jlong) ptr;
}

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_nativeCreateWithData(JNIEnv *env, jclass thisClass, jbyteArray array) {
    jbyte* bufferPtr = (*env)->GetByteArrayElements(env, array, NULL);
    jsize lengthOfArray = (*env)->GetArrayLength(env, array);
    struct TWData data = {
            .bytes = (uint8_t *) bufferPtr,
            .len = (size_t) lengthOfArray
    };

    struct TWUInt256 * ptr = TWUInt256CreateWithData(data);

    (*env)->ReleaseByteArrayElements(env, array, bufferPtr, JNI_ABORT);

    return (jlong) ptr;
}

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_nativeCreateWithInt(JNIEnv *env, jclass thisClass, jint value) {
    struct TWUInt256 * ptr = TWUInt256CreateWithUInt32((uint32_t) value);
    return (jlong)ptr;
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_delete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWUInt256Delete((struct TWUInt256 *) handle);
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_isZero(JNIEnv *env, jobject thisObject) {
    struct TWUInt256 * ptr = load(env, thisObject);
    return (jboolean) TWUInt256IsZero(ptr);
}

jint JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_intValue(JNIEnv *env, jobject thisObject) {
    struct TWUInt256 * ptr = load(env, thisObject);
    return TWUInt256UInt32Value(ptr);
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_getBytes(JNIEnv *env, jobject thisObject) {
    struct TWUInt256 * ptr = load(env, thisObject);

    uint8_t bytes[32];
    TWUInt256CopyData(ptr, bytes);

    jbyteArray array = (*env)->NewByteArray(env, 32);
    (*env)->SetByteArrayRegion(env, array, 0, 32, (jbyte *) bytes);

    return array;
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_equals(JNIEnv *env, jobject lhsObject, jobject rhsObject) {
    struct TWUInt256 * lhs = load(env, lhsObject);
    struct TWUInt256 * rhs = load(env, rhsObject);
    return (jboolean) TWUInt256Equal(lhs, rhs);
}

jint JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_compareTo(JNIEnv *env, jobject lhsObject, jobject rhsObject) {
    struct TWUInt256 * lhs = load(env, lhsObject);
    struct TWUInt256 * rhs = load(env, rhsObject);
    if (TWUInt256Equal(lhs, rhs))
        return 0;
    if (TWUInt256Less(lhs, rhs))
        return -1;
    return 1;
}

jstring JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_format(JNIEnv *env, jobject thisObject, jint decimals, jint exponent) {
    struct TWUInt256 * ptr = load(env, thisObject);
    char output[80];
    size_t len = TWUInt256Format(ptr, decimals, exponent, output, 80);
    return (*env)->NewStringUTF(env, output);
}
