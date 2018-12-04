// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

@import Foundation;

#include "TWFoundationData.h"

TWData *_Nonnull TWDataCreateWithBytes(const uint8_t *_Nonnull bytes, size_t size) {
    NSMutableData *data = [[NSMutableData alloc] initWithBytes:bytes length:size];
    return (__bridge_retained CFTypeRef) data;
}

TWData *_Nonnull TWDataCreateWithReference(NSMutableData *data) {
    return (__bridge_retained CFTypeRef) data;
}

NSMutableData *_Nonnull TWDataNSData(TWData *_Nonnull data) {
    return (__bridge NSMutableData *) data;
}

TWData *_Nonnull TWDataCreateWithSize(size_t size) {
    NSMutableData *data = [[NSMutableData alloc] init];
    [data setLength:size];
    return (__bridge_retained CFTypeRef) data;
}

TWData *_Nonnull TWDataCreateWithData(TWData *_Nonnull data) {
    NSMutableData *copy = [[NSMutableData alloc] initWithData:(__bridge NSData*) data];
    return (__bridge_retained CFTypeRef) copy;
}

size_t TWDataSize(TWData *_Nonnull data) {
    return ((__bridge NSData*) data).length;
}

uint8_t *_Nonnull TWDataBytes(TWData *_Nonnull data) {
    NSMutableData *nsdata = (__bridge NSMutableData*) data;
    return nsdata.mutableBytes;
}

void TWDataReleaseBytes(TWData *_Nonnull data, uint8_t *_Nonnull bytes) {
    // Not necessary
}

uint8_t TWDataGet(TWData *_Nonnull data, size_t index) {
    NSMutableData *nsdata = (__bridge NSMutableData*) data;
    return ((uint8_t *) nsdata.bytes)[index];
}

void TWDataSet(TWData *_Nonnull data, size_t index, uint8_t byte) {
    NSMutableData *nsdata = (__bridge NSMutableData*) data;
    ((uint8_t *) nsdata.mutableBytes)[index] = byte;
}

void TWDataCopyBytes(TWData *_Nonnull data, size_t start, size_t size, uint8_t *_Nonnull output) {
    NSMutableData *nsdata = (__bridge NSMutableData*) data;
    [nsdata getBytes:output range:NSMakeRange(start, size)];
}

void TWDataReplaceBytes(TWData *_Nonnull data, size_t start, size_t size, const uint8_t *bytes) {
    NSMutableData *nsdata = (__bridge NSMutableData*) data;
    [nsdata replaceBytesInRange:NSMakeRange(start, size) withBytes:bytes];
}

TWData *_Nonnull TWDataAppendBytes(TWData *_Nonnull data, const uint8_t *_Nonnull bytes, size_t size) {
    NSMutableData *nsdata = (__bridge NSMutableData*) data;
    [nsdata appendBytes:bytes length:size];
    return data;
}

TWData *_Nonnull TWDataAppendByte(TWData *_Nonnull data, uint8_t byte) {
    NSMutableData *nsdata = (__bridge NSMutableData*) data;
    [nsdata appendBytes:&byte length:1];
    return data;
}

TWData *_Nonnull TWDataAppendData(TWData *_Nonnull data, TWData *_Nonnull append) {
    NSMutableData *nsdata = (__bridge NSMutableData*) data;
    [nsdata appendData:(__bridge NSMutableData*) append];
    return data;
}

void TWDataReset(TWData *_Nonnull data) {
    NSMutableData *nsdata = (__bridge NSMutableData*) data;
    [nsdata resetBytesInRange:NSMakeRange(0, nsdata.length)];
}

void TWDataDelete(TWData *_Nonnull data) {
    NSMutableData *str __attribute__ ((unused)) = (__bridge_transfer NSMutableData *) data;
}
