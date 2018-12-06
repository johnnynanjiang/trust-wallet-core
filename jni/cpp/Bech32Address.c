// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWBech32Address.h>
#include "TWJNI.h"
#include "Bech32Address.h"

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_initWithString(JNIEnv *env, jclass thisObject, jstring string) {
    currentEnv = env;
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID bytesFieldID = (*env)->GetFieldID(env, thisClass, "bytes", "[b");
    jbyteArray bytesArray = (*env)->GetObjectField(env, thisObject, bytesFieldID);
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, bytesArray, NULL);

    struct TWBech32Address *instance = (struct TWBech32Address *) bytesBuffer;

    jboolean result = (jboolean) TWBech32AddressInitWithString(instance, string);

    (*env)->ReleaseByteArrayElements(env, bytesArray, bytesBuffer, JNI_ABORT);

    return result;
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_initWithData(JNIEnv *env, jclass thisObject, jbyteArray data, jstring hrp) {
    currentEnv = env;
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID bytesFieldID = (*env)->GetFieldID(env, thisClass, "bytes", "[b");
    jbyteArray bytesArray = (*env)->GetObjectField(env, thisObject, bytesFieldID);
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, bytesArray, NULL);

    struct TWBech32Address *instance = (struct TWBech32Address *) bytesBuffer;

    jboolean result = (jboolean) TWBech32AddressInitWithData(instance, data, hrp);

    (*env)->ReleaseByteArrayElements(env, bytesArray, bytesBuffer, JNI_ABORT);

    return result;
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_initWithPublicKey(JNIEnv *env, jclass thisObject, jobject publicKey, jstring hrp) {
    currentEnv = env;
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID bytesFieldID = (*env)->GetFieldID(env, thisClass, "bytes", "[b");
    jbyteArray bytesArray = (*env)->GetObjectField(env, thisObject, bytesFieldID);
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, bytesArray, NULL);

    jclass publicKeyClass = (*env)->GetObjectClass(env, publicKey);
    jfieldID publicKeyBytesFieldID = (*env)->GetFieldID(env, publicKeyClass, "bytes", "[b");
    jbyteArray publicKeyBytesArray = (*env)->GetObjectField(env, publicKey, publicKeyBytesFieldID);
    jbyte* publicKeyBytesBuffer = (*env)->GetByteArrayElements(env, publicKeyBytesArray, NULL);
    struct TWPublicKey *publicKeyInstance = (struct TWPublicKey *) publicKeyBytesBuffer;

    struct TWBech32Address *instance = (struct TWBech32Address *) bytesBuffer;

    jboolean result = (jboolean) TWBech32AddressInitWithPublicKey(instance, *publicKeyInstance, hrp);

    (*env)->ReleaseByteArrayElements(env, publicKeyBytesArray, publicKeyBytesBuffer, JNI_ABORT);
    (*env)->ReleaseByteArrayElements(env, bytesArray, bytesBuffer, JNI_ABORT);

    return result;
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs) {
    currentEnv = env;

    jclass lhsClass = (*env)->GetObjectClass(env, lhs);
    jfieldID lhsBytesFieldID = (*env)->GetFieldID(env, lhsClass, "bytes", "[b");
    jbyteArray lhsBytesArray = (*env)->GetObjectField(env, lhs, lhsBytesFieldID);
    jbyte* lhsBytesBuffer = (*env)->GetByteArrayElements(env, lhsBytesArray, NULL);
    struct TWBech32Address *lhsInstance = (struct TWBech32Address *) lhsBytesBuffer;

    jclass rhsClass = (*env)->GetObjectClass(env, rhs);
    jfieldID rhsBytesFieldID = (*env)->GetFieldID(env, rhsClass, "bytes", "[b");
    jbyteArray rhsBytesArray = (*env)->GetObjectField(env, rhs, rhsBytesFieldID);
    jbyte* rhsBytesBuffer = (*env)->GetByteArrayElements(env, rhsBytesArray, NULL);
    struct TWBech32Address *rhsInstance = (struct TWBech32Address *) rhsBytesBuffer;

    jboolean resultValue = (jboolean) TWBech32AddressEqual(*lhsInstance, *rhsInstance);
    (*env)->ReleaseByteArrayElements(env, lhsBytesArray, lhsBytesBuffer, JNI_ABORT);
    (*env)->ReleaseByteArrayElements(env, rhsBytesArray, rhsBytesBuffer, JNI_ABORT);

    return resultValue;
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_isValid(JNIEnv *env, jclass thisClass, jbyteArray data) {
    currentEnv = env;

    jboolean resultValue = (jboolean) TWBech32AddressIsValid(data);

    return resultValue;
}


jstring JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_description(JNIEnv *env, jobject thisObject) {
    currentEnv = env;
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID bytesFieldID = (*env)->GetFieldID(env, thisClass, "bytes", "[b");
    jbyteArray bytesArray = (*env)->GetObjectField(env, thisObject, bytesFieldID);
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, bytesArray, NULL);
    struct TWBech32Address *instance = (struct TWBech32Address *) bytesBuffer;

    jstring result = (jstring) TWBech32AddressDescription(*instance);

    (*env)->ReleaseByteArrayElements(env, bytesArray, bytesBuffer, JNI_ABORT);

    return result;
}

