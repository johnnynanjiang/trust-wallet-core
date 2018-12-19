// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.wallet.crypto.trustapp.jni;

import java.security.InvalidParameterException;
import java.util.HashSet;

public class BitcoinTransaction {
    private long nativeHandle;

    private BitcoinTransaction() {
        nativeHandle = 0;
    }

    static BitcoinTransaction createFromNative(long nativeHandle) {
        BitcoinTransaction instance = new BitcoinTransaction();
        instance.nativeHandle = nativeHandle;
        BitcoinTransactionPhantomReference.register(instance, nativeHandle);
        return instance;
    }

    static native long nativeCreate(int version, int lockTime);
    static native void nativeDelete(long handle);

    public native int lockTime();
    public native int inputCount();
    public native int outputCount();
    public native byte[] hash();
    public native byte[] witnessHash();
    public native byte[] identifier();
    public native byte[] witnessIdentifier();
    public native BitcoinTransactionInput getInput(int index);
    public native void addInput(BitcoinOutPoint previousOutput, BitcoinScript script, int sequence);
    public native BitcoinTransactionOutput getOutput(int index);
    public native byte[] encode(boolean witness);

    public BitcoinTransaction(int version, int lockTime) {
        nativeHandle = nativeCreate(version, lockTime);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        BitcoinTransactionPhantomReference.register(this, nativeHandle);
    }

}

class BitcoinTransactionPhantomReference extends java.lang.ref.PhantomReference<BitcoinTransaction> {
    private static java.util.Set<BitcoinTransactionPhantomReference> references = new HashSet<BitcoinTransactionPhantomReference>();
    private static java.lang.ref.ReferenceQueue<BitcoinTransaction> queue = new java.lang.ref.ReferenceQueue<BitcoinTransaction>();
    private long nativeHandle;

    private BitcoinTransactionPhantomReference(BitcoinTransaction referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(BitcoinTransaction referent, long nativeHandle) {
        references.add(new BitcoinTransactionPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        BitcoinTransactionPhantomReference ref = (BitcoinTransactionPhantomReference) queue.poll();
        for (; ref != null; ref = (BitcoinTransactionPhantomReference) queue.poll()) {
            BitcoinTransaction.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
