// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.wallet.crypto.trustapp.jni;

import java.security.InvalidParameterException;
import java.util.HashSet;

public class BitcoinTransactionInput {
    private long nativeHandle;

    private BitcoinTransactionInput() {
        nativeHandle = 0;
    }

    static BitcoinTransactionInput createFromNative(long nativeHandle) {
        BitcoinTransactionInput instance = new BitcoinTransactionInput();
        instance.nativeHandle = nativeHandle;
        BitcoinTransactionInputPhantomReference.register(instance, nativeHandle);
        return instance;
    }

    static native long nativeCreate(BitcoinOutPoint previousOutput, BitcoinScript script, int sequence);
    static native void nativeDelete(long handle);

    public native BitcoinOutPoint previousOutput();
    public native BitcoinScript script();
    public native int sequence();
    public native byte[] encode();

    public BitcoinTransactionInput(BitcoinOutPoint previousOutput, BitcoinScript script, int sequence) {
        nativeHandle = nativeCreate(previousOutput, script, sequence);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        BitcoinTransactionInputPhantomReference.register(this, nativeHandle);
    }

}

class BitcoinTransactionInputPhantomReference extends java.lang.ref.PhantomReference<BitcoinTransactionInput> {
    private static java.util.Set<BitcoinTransactionInputPhantomReference> references = new HashSet<BitcoinTransactionInputPhantomReference>();
    private static java.lang.ref.ReferenceQueue<BitcoinTransactionInput> queue = new java.lang.ref.ReferenceQueue<BitcoinTransactionInput>();
    private long nativeHandle;

    private BitcoinTransactionInputPhantomReference(BitcoinTransactionInput referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(BitcoinTransactionInput referent, long nativeHandle) {
        references.add(new BitcoinTransactionInputPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        BitcoinTransactionInputPhantomReference ref = (BitcoinTransactionInputPhantomReference) queue.poll();
        for (; ref != null; ref = (BitcoinTransactionInputPhantomReference) queue.poll()) {
            BitcoinTransactionInput.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
