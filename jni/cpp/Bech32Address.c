// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWBech32Address.h>
#include <TrustWalletCore/TWPublicKey.h>

#include "TWJNI.h"
#include "Bech32Address.h"

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_initWithString(JNIEnv *env, jclass thisClass, jstring string) {
    jbyteArray array = (*env)->NewByteArray(env, sizeof(struct TWBech32Address));
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, array, NULL);
    struct TWBech32Address *instance = (struct TWBech32Address *) bytesBuffer;
    TWString *stringString = TWStringCreateWithJString(env, string);
    jboolean result = (jboolean) TWBech32AddressInitWithString(instance, stringString);
    TWStringDelete(stringString);
    (*env)->ReleaseByteArrayElements(env, array, bytesBuffer, 0);

    if (result) {
        return array;
    } else {
        return NULL;
    }
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_initWithData(JNIEnv *env, jclass thisClass, jbyteArray data, jstring hrp) {
    jbyteArray array = (*env)->NewByteArray(env, sizeof(struct TWBech32Address));
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, array, NULL);
    struct TWBech32Address *instance = (struct TWBech32Address *) bytesBuffer;
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    TWString *hrpString = TWStringCreateWithJString(env, hrp);
    jboolean result = (jboolean) TWBech32AddressInitWithData(instance, dataData, hrpString);
    TWDataDelete(dataData);
    TWStringDelete(hrpString);
    (*env)->ReleaseByteArrayElements(env, array, bytesBuffer, 0);

    if (result) {
        return array;
    } else {
        return NULL;
    }
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_initWithPublicKey(JNIEnv *env, jclass thisClass, jobject publicKey, jstring hrp) {
    jbyteArray array = (*env)->NewByteArray(env, sizeof(struct TWBech32Address));
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, array, NULL);
    struct TWBech32Address *instance = (struct TWBech32Address *) bytesBuffer;
    jclass publicKeyClass = (*env)->GetObjectClass(env, publicKey);
    jfieldID publicKeyBytesFieldID = (*env)->GetFieldID(env, publicKeyClass, "bytes", "[B");
    jbyteArray publicKeyBytesArray = (*env)->GetObjectField(env, publicKey, publicKeyBytesFieldID);
    jbyte* publicKeyBytesBuffer = (*env)->GetByteArrayElements(env, publicKeyBytesArray, NULL);
    struct TWPublicKey *publicKeyInstance = (struct TWPublicKey *) publicKeyBytesBuffer;
    TWString *hrpString = TWStringCreateWithJString(env, hrp);
    jboolean result = (jboolean) TWBech32AddressInitWithPublicKey(instance, *publicKeyInstance, hrpString);
    (*env)->ReleaseByteArrayElements(env, publicKeyBytesArray, publicKeyBytesBuffer, JNI_ABORT);
    TWStringDelete(hrpString);
    (*env)->ReleaseByteArrayElements(env, array, bytesBuffer, 0);

    if (result) {
        return array;
    } else {
        return NULL;
    }
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_equals(JNIEnv *env, jclass thisClass, jobject lhs, jobject rhs) {
    jclass lhsClass = (*env)->GetObjectClass(env, lhs);
    jfieldID lhsBytesFieldID = (*env)->GetFieldID(env, lhsClass, "bytes", "[B");
    jbyteArray lhsBytesArray = (*env)->GetObjectField(env, lhs, lhsBytesFieldID);
    jbyte* lhsBytesBuffer = (*env)->GetByteArrayElements(env, lhsBytesArray, NULL);
    struct TWBech32Address *lhsInstance = (struct TWBech32Address *) lhsBytesBuffer;
    jclass rhsClass = (*env)->GetObjectClass(env, rhs);
    jfieldID rhsBytesFieldID = (*env)->GetFieldID(env, rhsClass, "bytes", "[B");
    jbyteArray rhsBytesArray = (*env)->GetObjectField(env, rhs, rhsBytesFieldID);
    jbyte* rhsBytesBuffer = (*env)->GetByteArrayElements(env, rhsBytesArray, NULL);
    struct TWBech32Address *rhsInstance = (struct TWBech32Address *) rhsBytesBuffer;
    jboolean resultValue = (jboolean) TWBech32AddressEqual(*lhsInstance, *rhsInstance);
    (*env)->ReleaseByteArrayElements(env, lhsBytesArray, lhsBytesBuffer, JNI_ABORT);
    (*env)->ReleaseByteArrayElements(env, rhsBytesArray, rhsBytesBuffer, JNI_ABORT);

    return resultValue;
}

jboolean JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_isValid(JNIEnv *env, jclass thisClass, jbyteArray data) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    jboolean resultValue = (jboolean) TWBech32AddressIsValid(dataData);
    TWDataDelete(dataData);

    return resultValue;
}

jstring JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_description(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID bytesFieldID = (*env)->GetFieldID(env, thisClass, "bytes", "[B");
    jbyteArray bytesArray = (*env)->GetObjectField(env, thisObject, bytesFieldID);
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, bytesArray, NULL);
    struct TWBech32Address *instance = (struct TWBech32Address *) bytesBuffer;

    jstring result = TWStringJString(TWBech32AddressDescription(*instance), env);
    (*env)->ReleaseByteArrayElements(env, bytesArray, bytesBuffer, JNI_ABORT);

    return result;
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_Bech32Address_data(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID bytesFieldID = (*env)->GetFieldID(env, thisClass, "bytes", "[B");
    jbyteArray bytesArray = (*env)->GetObjectField(env, thisObject, bytesFieldID);
    jbyte* bytesBuffer = (*env)->GetByteArrayElements(env, bytesArray, NULL);
    struct TWBech32Address *instance = (struct TWBech32Address *) bytesBuffer;

    jbyteArray resultValue = TWDataJByteArray(TWBech32AddressData(*instance), env);
    (*env)->ReleaseByteArrayElements(env, bytesArray, bytesBuffer, JNI_ABORT);

    return resultValue;
}

