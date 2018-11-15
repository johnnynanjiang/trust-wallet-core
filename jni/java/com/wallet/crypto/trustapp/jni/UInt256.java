// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.wallet.crypto.trustapp.jni;

import org.web3j.abi.datatypes.generated.Int256;

import java.security.InvalidParameterException;
import java.util.HashSet;

public class UInt256 {
    private long nativeHandle;

    static {
        System.loadLibrary("TrustWalletCore");
    }

    private static native long nativeCreateZero();
    private static native long nativeCreateOne();
    private static native long nativeCreateWithData(byte[] data);
    private static native long nativeCreateWithInt(int value);
    static native void delete(long handle);

    public native boolean isZero();
    public native int intValue();
    public native byte[] getBytes();
    public native boolean equals(UInt256 other);
    public native int compareTo(UInt256 other);
    public native String format(int decimals, int exponent);

    private UInt256(long nativeHandle) {
        this.nativeHandle = nativeHandle;
    }

    public static UInt256 zero() {
        long handle = nativeCreateZero();
        UInt256 instance = new UInt256(handle);
        UInt256PhantomReference.register(instance, handle);
        return instance;
    }

    public static UInt256 one() {
        long handle = nativeCreateOne();
        UInt256 instance = new UInt256(handle);
        UInt256PhantomReference.register(instance, handle);
        return instance;
    }

    public static UInt256 createWithData(byte[] data) {
        long handle = nativeCreateWithData(data);
        if (handle == 0) {
            throw new InvalidParameterException();
        }

        UInt256 instance = new UInt256(handle);
        UInt256PhantomReference.register(instance, handle);
        return instance;
    }

    public static UInt256 createWithInt(int value) {
        long handle = nativeCreateWithInt(value);
        if (handle == 0) {
            throw new InvalidParameterException();
        }

        UInt256 instance = new UInt256(handle);
        UInt256PhantomReference.register(instance, handle);
        return instance;
    }
}

class UInt256PhantomReference extends java.lang.ref.PhantomReference<UInt256> {
    private static java.util.Set<UInt256PhantomReference> references = new HashSet<UInt256PhantomReference>();
    private static java.lang.ref.ReferenceQueue<UInt256> queue = new java.lang.ref.ReferenceQueue<UInt256>();
    private long nativeHandle;

    private UInt256PhantomReference(UInt256 referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(UInt256 referent, long nativeHandle) {
        references.add(new UInt256PhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        UInt256PhantomReference ref = (UInt256PhantomReference) queue.poll();
        for (; ref != null; ref = (UInt256PhantomReference) queue.poll()) {
            UInt256.delete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
