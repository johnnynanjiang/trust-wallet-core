// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <assert.h>
#include "TWJNIData.h"

JNIEnv *currentEnv;

TWData *_Nonnull TWDataCreateWithBytes(const uint8_t *_Nonnull bytes, size_t size) {
    jbyteArray array = (*currentEnv)->NewByteArray(currentEnv, size);
    (*currentEnv)->SetByteArrayRegion(currentEnv, array, 0, size, (jbyte *) bytes);
    return array;
}

TWData *_Nonnull TWDataCreateWithSize(size_t size) {
    jbyteArray array = (*currentEnv)->NewByteArray(currentEnv, size);
    return array;
}

TWData *_Nonnull TWDataCreateWithData(TWData *_Nonnull data) {
    JNIEnv *env = currentEnv;
    jbyteArray dataArray = (jbyteArray) data;
    jsize size = (*env)->GetArrayLength(env, dataArray);
    jbyteArray newArray = (*env)->NewByteArray(env, size);
    jbyte *bytes = (*env)->GetByteArrayElements(env, dataArray, 0);
    (*env)->SetByteArrayRegion(env, newArray, 0, size, bytes);
    (*env)->ReleaseByteArrayElements(env, dataArray, bytes, JNI_ABORT);
    return newArray;
}

size_t TWDataSize(TWData *_Nonnull data) {
    jbyteArray array = (jbyteArray) data;
    return (*currentEnv)->GetArrayLength(currentEnv, array);
}

uint8_t *_Nonnull TWDataBytes(TWData *_Nonnull data) {
    jbyteArray array = (jbyteArray) data;
    jbyte *bytes = (*currentEnv)->GetByteArrayElements(currentEnv, array, NULL);
    return (uint8_t *) bytes;
}

void TWDataReleaseBytes(TWData *_Nonnull data, uint8_t *_Nonnull bytes) {
    jbyteArray array = (jbyteArray) data;
    (*currentEnv)->ReleaseByteArrayElements(currentEnv, array, (jbyte *) bytes, JNI_ABORT);
}

uint8_t TWDataGet(TWData *_Nonnull data, size_t index) {
    jbyteArray array = (jbyteArray) data;
    jbyte byte;
    (*currentEnv)->GetByteArrayRegion(currentEnv, array, index, index + 1, &byte);
    return byte;
}

void TWDataSet(TWData *_Nonnull data, size_t index, uint8_t byte) {
    jbyteArray array = (jbyteArray) data;
    (*currentEnv)->SetByteArrayRegion(currentEnv, array, index, index + 1, (const jbyte *) &byte);
}

void TWDataCopyBytes(TWData *_Nonnull data, size_t start, size_t size, uint8_t *_Nonnull output) {
    jbyteArray array = (jbyteArray) data;
    (*currentEnv)->GetByteArrayRegion(currentEnv, array, start, size, (jbyte *) output);
}

void TWDataReplaceBytes(TWData *_Nonnull data, size_t start, size_t size, const uint8_t *bytes) {
    jbyteArray array = (jbyteArray) data;
    (*currentEnv)->SetByteArrayRegion(currentEnv, array, start, size, (const jbyte *) bytes);
}

TWData *_Nonnull TWDataAppendBytes(TWData *_Nonnull data, const uint8_t *_Nonnull bytes, size_t size) {
    jbyteArray array = (jbyteArray) data;
    jsize newSize = TWDataSize(data) + size;
    jbyteArray newArray = (jbyteArray) TWDataCreateWithSize(newSize);
    TWDataReplaceBytes(newArray, 0, TWDataSize(data), TWDataBytes(data));
    TWDataReplaceBytes(newArray, TWDataSize(data), size, bytes);
    (*currentEnv)->DeleteLocalRef(currentEnv, array);
    return newArray;
}

TWData *_Nonnull TWDataAppendByte(TWData *_Nonnull data, uint8_t byte) {
    jbyteArray array = (jbyteArray) data;
    jsize newSize = TWDataSize(data) + 1;
    jbyteArray newArray = (jbyteArray) TWDataCreateWithSize(newSize);
    TWDataReplaceBytes(newArray, 0, TWDataSize(data), TWDataBytes(data));
    TWDataSet(newArray, TWDataSize(data), byte);
    (*currentEnv)->DeleteLocalRef(currentEnv, array);
    return newArray;
}

TWData *_Nonnull TWDataAppendData(TWData *_Nonnull data, TWData *_Nonnull append) {
    jbyteArray array = (jbyteArray) data;
    jsize newSize = TWDataSize(data) + TWDataSize(append);
    jbyteArray newArray = (jbyteArray) TWDataCreateWithSize(newSize);
    TWDataReplaceBytes(newArray, 0, TWDataSize(data), TWDataBytes(data));
    uint8_t *appendBytes = TWDataBytes(append);
    TWDataReplaceBytes(newArray, TWDataSize(data), TWDataSize(append), appendBytes);
    TWDataReleaseBytes(append, appendBytes);
    (*currentEnv)->DeleteLocalRef(currentEnv, array);
    return newArray;
}

void TWDataReset(TWData *_Nonnull data) {
    jbyteArray array = (jbyteArray) data;
    jsize size = (*currentEnv)->GetArrayLength(currentEnv, array);
    jbyte byte = 0;
    for (size_t i = 0; i < size; i += 1) {
        (*currentEnv)->SetByteArrayRegion(currentEnv, array, i, i + 1, &byte);
    }
}

void TWDataDelete(TWData *_Nonnull data) {
    // Nothing to do, reference will be garbage-collected by Java
}
