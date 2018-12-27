// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include <TrustWalletCore/TWHDWallet.h>
#include <TrustWalletCore/TWPublicKey.h>

#include "TWJNI.h"
#include "HDWallet.h"

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_nativeCreate(JNIEnv *env, jclass thisClass, jint strength, jstring passphrase) {
    TWString *passphraseString = TWStringCreateWithJString(env, passphrase);
    struct TWHDWallet *instance = TWHDWalletCreate(strength, passphraseString);
    TWStringDelete(passphraseString);
    return (jlong) instance;
}

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_nativeCreateWithMnemonic(JNIEnv *env, jclass thisClass, jstring mnemonic, jstring passphrase) {
    TWString *mnemonicString = TWStringCreateWithJString(env, mnemonic);
    TWString *passphraseString = TWStringCreateWithJString(env, passphrase);
    struct TWHDWallet *instance = TWHDWalletCreateWithMnemonic(mnemonicString, passphraseString);
    TWStringDelete(mnemonicString);
    TWStringDelete(passphraseString);
    return (jlong) instance;
}

jlong JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_nativeCreateWithData(JNIEnv *env, jclass thisClass, jbyteArray data, jstring passphrase) {
    TWData *dataData = TWDataCreateWithJByteArray(env, data);
    TWString *passphraseString = TWStringCreateWithJString(env, passphrase);
    struct TWHDWallet *instance = TWHDWalletCreateWithData(dataData, passphraseString);
    TWDataDelete(dataData);
    TWStringDelete(passphraseString);
    return (jlong) instance;
}

void JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_nativeDelete(JNIEnv *env, jclass thisClass, jlong handle) {
    TWHDWalletDelete((struct TWHDWallet *) handle);
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_getPublicKeyFromExtended(JNIEnv *env, jclass thisClass, jstring extended, jint versionPublic, jint versionPrivate, jint change, jint address) {
    TWString *extendedString = TWStringCreateWithJString(env, extended);
    struct TWPublicKey result = TWHDWalletGetPublicKeyFromExtended(extendedString, versionPublic, versionPrivate, change, address);
    TWStringDelete(extendedString);

    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/PublicKey");
    jbyteArray resultArray = (*env)->NewByteArray(env, sizeof(struct TWPublicKey));
    (*env)->SetByteArrayRegion(env, resultArray, 0, sizeof(struct TWPublicKey), (jbyte *) &result);
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "([B)Lcom/wallet/crypto/trustapp/jni/PublicKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, resultArray);
}

jbyteArray JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_seed(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jbyteArray resultValue = TWDataJByteArray(TWHDWalletSeed(instance), env);
    return resultValue;
}

jstring JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_mnemonic(JNIEnv *env, jobject thisObject) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = TWStringJString(TWHDWalletMnemonic(instance), env);
    return result;
}

jobject JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_getKey(JNIEnv *env, jobject thisObject, jint purpose, jint coin, jint account, jint change, jint address) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    struct TWPrivateKey *result = TWHDWalletGetKey(instance, purpose, coin, account, change, address);
    jclass class = (*env)->FindClass(env, "com/wallet/crypto/trustapp/jni/PrivateKey");
    if (result == NULL) {
        return NULL;
    }
    jmethodID method = (*env)->GetStaticMethodID(env, class, "createFromNative", "(J)Lcom/wallet/crypto/trustapp/jni/PrivateKey;");
    return (*env)->CallStaticObjectMethod(env, class, method, (jlong) result);
}

jstring JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_getExtendedPrivateKey(JNIEnv *env, jobject thisObject, jint purpose, jint coin, jint version) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = TWStringJString(TWHDWalletGetExtendedPrivateKey(instance, purpose, coin, version), env);
    return result;
}

jstring JNICALL Java_com_wallet_crypto_trustapp_jni_HDWallet_getExtendedPublicKey(JNIEnv *env, jobject thisObject, jint purpose, jint coin, jint version) {
    jclass thisClass = (*env)->GetObjectClass(env, thisObject);
    jfieldID handleFieldID = (*env)->GetFieldID(env, thisClass, "nativeHandle", "J");
    struct TWHDWallet *instance = (struct TWHDWallet *) (*env)->GetLongField(env, thisObject, handleFieldID);

    jstring result = TWStringJString(TWHDWalletGetExtendedPublicKey(instance, purpose, coin, version), env);
    return result;
}

