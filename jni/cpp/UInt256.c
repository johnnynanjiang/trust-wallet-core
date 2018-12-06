// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWUInt256.h>
#include "TWJNI.h"
#include "UInt256.h"

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_nativeCreateWithData(JNIEnv *env, jclass thisClass, jbyteArray data) {
    currentEnv = env;

    struct TWUInt256 *instance = TWUInt256CreateWithData(data);

    return (jlong) instance;
}

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_nativeCreateWithUInt32(JNIEnv *env, jclass thisClass, jint value) {
    currentEnv = env;

    struct TWUInt256 *instance = TWUInt256CreateWithUInt32(value);

    return (jlong) instance;
}

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_nativeCreateWithUInt64(JNIEnv *env, jclass thisClass, jlong value) {
    currentEnv = env;

    struct TWUInt256 *instance = TWUInt256CreateWithUInt64(value);

    return (jlong) instance;
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    currentEnv = env;
    TWUInt256Delete((struct TWUInt256 *) handle);
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_zero(JNIEnv *env, jclass thisClass) {
    currentEnv = env;
    struct TWUInt256 *result = TWUInt256Zero();

    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/UInt256");
    jmethodID init = (*env)->GetMethodID(env, class, "createFromNative", "(J)V");
    return (*env)->NewObject(env, class, init, (jlong) result);
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_one(JNIEnv *env, jclass thisClass) {
    currentEnv = env;
    struct TWUInt256 *result = TWUInt256One();

    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/UInt256");
    jmethodID init = (*env)->GetMethodID(env, class, "createFromNative", "(J)V");
    return (*env)->NewObject(env, class, init, (jlong) result);
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs) {
    currentEnv = env;

    jclass lhsClass = (*env)->GetObjectClass(env, lhs);
    jfieldID lhsHandleFieldID = (*env)->GetFieldID(env, lhsClass, "nativeHandle", "J");
    struct TWUInt256 *lhsInstance = (struct TWUInt256 *) (*env)->GetLongField(env, lhs, lhsHandleFieldID);

    jclass rhsClass = (*env)->GetObjectClass(env, rhs);
    jfieldID rhsHandleFieldID = (*env)->GetFieldID(env, rhsClass, "nativeHandle", "J");
    struct TWUInt256 *rhsInstance = (struct TWUInt256 *) (*env)->GetLongField(env, rhs, rhsHandleFieldID);

    jboolean resultValue = (jboolean) TWUInt256Equal(lhsInstance, rhsInstance);

    return resultValue;
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_compareTo(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs) {
    currentEnv = env;

    jclass lhsClass = (*env)->GetObjectClass(env, lhs);
    jfieldID lhsHandleFieldID = (*env)->GetFieldID(env, lhsClass, "nativeHandle", "J");
    struct TWUInt256 *lhsInstance = (struct TWUInt256 *) (*env)->GetLongField(env, lhs, lhsHandleFieldID);

    jclass rhsClass = (*env)->GetObjectClass(env, rhs);
    jfieldID rhsHandleFieldID = (*env)->GetFieldID(env, rhsClass, "nativeHandle", "J");
    struct TWUInt256 *rhsInstance = (struct TWUInt256 *) (*env)->GetLongField(env, rhs, rhsHandleFieldID);

    jboolean resultValue = (jboolean) TWUInt256Less(lhsInstance, rhsInstance);

    return resultValue;
}


jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_isZero(JNIEnv *env, jobject thisObject) {
    currentEnv = env;
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWUInt256 *instance = (struct TWUInt256 *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jboolean resultValue = (jboolean) TWUInt256IsZero(instance);

    return resultValue;
}

jint JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_uint32Value(JNIEnv *env, jobject thisObject) {
    currentEnv = env;
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWUInt256 *instance = (struct TWUInt256 *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jint resultValue = (jint) TWUInt256UInt32Value(instance);

    return resultValue;
}

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_uint64Value(JNIEnv *env, jobject thisObject) {
    currentEnv = env;
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWUInt256 *instance = (struct TWUInt256 *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jlong resultValue = (jlong) TWUInt256UInt64Value(instance);

    return resultValue;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_data(JNIEnv *env, jobject thisObject) {
    currentEnv = env;
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWUInt256 *instance = (struct TWUInt256 *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray resultValue = (jbyteArray) TWUInt256Data(instance);

    return resultValue;
}

jstring JNICALL Java_com_wallet_crypto_trustapp_jni_UInt256_format(JNIEnv *env, jobject thisObject, jint decimals, jint exponent) {
    currentEnv = env;
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWUInt256 *instance = (struct TWUInt256 *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = (jstring) TWUInt256Format(instance, decimals, exponent);

    return result;
}

