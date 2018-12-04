// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <assert.h>
#include <string.h>
#include "TWJNIString.h"

TWString *_Nonnull TWStringCreateWithUTF8Bytes(const char *_Nonnull bytes) {
    return (*currentEnv)->NewStringUTF(currentEnv, bytes);
}

size_t TWStringSize(TWString *_Nonnull string) {
    return (*currentEnv)->GetStringUTFLength(currentEnv, (jstring) string);
}

char TWStringGet(TWString *_Nonnull string, size_t index) {
    char c;
    (*currentEnv)->GetStringUTFRegion(currentEnv, (jstring) string, index, 1, &c);
    return c;
}

void TWStringDelete(const TWString *_Nonnull string) {
    // Nothing to do, reference will be garbage-collected by Java
}
