// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

@import Foundation;

#include "TWFoundationString.h"

TWString *_Nonnull TWStringCreateWithUTF8Bytes(const char *_Nonnull bytes) {
    NSMutableString *string = [[NSMutableString alloc] initWithUTF8String:bytes];
    return (__bridge_retained CFTypeRef) string;
}

TWString *_Nonnull TWStringCreateWithReference(NSString *string) {
    return (__bridge_retained CFTypeRef) string;
}

NSString *_Nonnull TWStringNSString(TWString *_Nonnull string) {
    return (__bridge NSString *) string;
}

size_t TWStringSize(const  TWString *_Nonnull string) {
    NSMutableString *nsstring = (__bridge NSMutableString*) string;
    return nsstring.length;
}

char TWStringGet(TWData *_Nonnull string, size_t index) {
    NSMutableString *nsstring = (__bridge NSMutableString*) string;
    return [nsstring characterAtIndex:index];
}

void TWStringAppend(const TWString *_Nonnull string, const TWString *_Nonnull append) {
    NSMutableString *nsstring = (__bridge NSMutableString*) string;
    [nsstring appendString:(__bridge NSMutableString*) append];
}

void TWStringDelete(const TWString *_Nonnull string) {
    NSMutableString *str __attribute__ ((unused)) = (__bridge_transfer NSMutableString *) string;
}
