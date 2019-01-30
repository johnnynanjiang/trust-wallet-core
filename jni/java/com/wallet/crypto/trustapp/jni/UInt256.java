// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

package com.wallet.crypto.trustapp.jni;

import java.security.InvalidParameterException;
import java.util.HashSet;

public class UInt256 implements Comparable<UInt256> {
    private long nativeHandle;

    private UInt256() {
        nativeHandle = 0;
    }

    static UInt256 createFromNative(long nativeHandle) {
        UInt256 instance = new UInt256();
        instance.nativeHandle = nativeHandle;
        UInt256PhantomReference.register(instance, nativeHandle);
        return instance;
    }

    static native long nativeCreateWithData(byte[] data);
    static native long nativeCreateWithUInt32(int value);
    static native long nativeCreateWithUInt64(long value);
    static native void nativeDelete(long handle);

    public static native UInt256 zero();
    public static native UInt256 one();
    public static native boolean equals(UInt256 lhs, UInt256 rhs);
    public static native boolean less(UInt256 lhs, UInt256 rhs);
    public native boolean isZero();
    public native int uint32Value();
    public native long uint64Value();
    public native byte[] data();
    public native String format(int decimals, int exponent);
    public native int compareTo(UInt256 other);

    public UInt256(byte[] data) {
        nativeHandle = nativeCreateWithData(data);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        UInt256PhantomReference.register(this, nativeHandle);
    }

    public UInt256(int value) {
        nativeHandle = nativeCreateWithUInt32(value);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        UInt256PhantomReference.register(this, nativeHandle);
    }

    public UInt256(long value) {
        nativeHandle = nativeCreateWithUInt64(value);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        UInt256PhantomReference.register(this, nativeHandle);
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
            UInt256.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
