// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.wallet.crypto.trustapp.jni;

import java.security.InvalidParameterException;
import java.util.HashSet;

public class BitcoinTransactionOutput {
    private long nativeHandle;

    private BitcoinTransactionOutput() {
        nativeHandle = 0;
    }

    static BitcoinTransactionOutput createFromNative(long nativeHandle) {
        BitcoinTransactionOutput instance = new BitcoinTransactionOutput();
        instance.nativeHandle = nativeHandle;
        BitcoinTransactionOutputPhantomReference.register(instance, nativeHandle);
        return instance;
    }

    static native long nativeCreate(long value, BitcoinScript script);
    static native void nativeDelete(long handle);

    public static native boolean equals(BitcoinTransactionOutput lhs, BitcoinTransactionOutput rhs);
    public native long amount();
    public native BitcoinScript script();
    public native byte[] encode();

    public BitcoinTransactionOutput(long value, BitcoinScript script) {
        nativeHandle = nativeCreate(value, script);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        BitcoinTransactionOutputPhantomReference.register(this, nativeHandle);
    }

}

class BitcoinTransactionOutputPhantomReference extends java.lang.ref.PhantomReference<BitcoinTransactionOutput> {
    private static java.util.Set<BitcoinTransactionOutputPhantomReference> references = new HashSet<BitcoinTransactionOutputPhantomReference>();
    private static java.lang.ref.ReferenceQueue<BitcoinTransactionOutput> queue = new java.lang.ref.ReferenceQueue<BitcoinTransactionOutput>();
    private long nativeHandle;

    private BitcoinTransactionOutputPhantomReference(BitcoinTransactionOutput referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(BitcoinTransactionOutput referent, long nativeHandle) {
        references.add(new BitcoinTransactionOutputPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        BitcoinTransactionOutputPhantomReference ref = (BitcoinTransactionOutputPhantomReference) queue.poll();
        for (; ref != null; ref = (BitcoinTransactionOutputPhantomReference) queue.poll()) {
            BitcoinTransactionOutput.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
