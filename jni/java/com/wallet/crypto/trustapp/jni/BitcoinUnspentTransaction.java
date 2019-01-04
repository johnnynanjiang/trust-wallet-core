// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.wallet.crypto.trustapp.jni;

import java.security.InvalidParameterException;
import java.util.HashSet;

public class BitcoinUnspentTransaction {
    private long nativeHandle;

    private BitcoinUnspentTransaction() {
        nativeHandle = 0;
    }

    static BitcoinUnspentTransaction createFromNative(long nativeHandle) {
        BitcoinUnspentTransaction instance = new BitcoinUnspentTransaction();
        instance.nativeHandle = nativeHandle;
        BitcoinUnspentTransactionPhantomReference.register(instance, nativeHandle);
        return instance;
    }

    static native long nativeCreateWithOutput(BitcoinOutPoint outpoint, BitcoinTransactionOutput output);
    static native long nativeCreate(byte[] hash, int index, BitcoinScript script, long amount);
    static native void nativeDelete(long handle);

    public native BitcoinOutPoint outPoint();
    public native BitcoinTransactionOutput output();
    public native long amount();

    public BitcoinUnspentTransaction(BitcoinOutPoint outpoint, BitcoinTransactionOutput output) {
        nativeHandle = nativeCreateWithOutput(outpoint, output);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        BitcoinUnspentTransactionPhantomReference.register(this, nativeHandle);
    }

    public BitcoinUnspentTransaction(byte[] hash, int index, BitcoinScript script, long amount) {
        nativeHandle = nativeCreate(hash, index, script, amount);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        BitcoinUnspentTransactionPhantomReference.register(this, nativeHandle);
    }

}

class BitcoinUnspentTransactionPhantomReference extends java.lang.ref.PhantomReference<BitcoinUnspentTransaction> {
    private static java.util.Set<BitcoinUnspentTransactionPhantomReference> references = new HashSet<BitcoinUnspentTransactionPhantomReference>();
    private static java.lang.ref.ReferenceQueue<BitcoinUnspentTransaction> queue = new java.lang.ref.ReferenceQueue<BitcoinUnspentTransaction>();
    private long nativeHandle;

    private BitcoinUnspentTransactionPhantomReference(BitcoinUnspentTransaction referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(BitcoinUnspentTransaction referent, long nativeHandle) {
        references.add(new BitcoinUnspentTransactionPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        BitcoinUnspentTransactionPhantomReference ref = (BitcoinUnspentTransactionPhantomReference) queue.poll();
        for (; ref != null; ref = (BitcoinUnspentTransactionPhantomReference) queue.poll()) {
            BitcoinUnspentTransaction.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
