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

public class ZcashTransaction {
    private long nativeHandle;

    static ZcashTransaction createFromNative(long nativeHandle) {
        ZcashTransaction instance = new ZcashTransaction();
        instance.nativeHandle = nativeHandle;
        ZcashTransactionPhantomReference.register(instance, nativeHandle);
        return instance;
    }

    static native long nativeCreate();
    static native void nativeDelete(long handle);

    public native int lockTime();
    public native int inputCount();
    public native int outputCount();
    public native byte[] hash();
    public native String identifier();
    public native byte[] encode();

    public ZcashTransaction() {
        nativeHandle = nativeCreate();
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        ZcashTransactionPhantomReference.register(this, nativeHandle);
    }

}

class ZcashTransactionPhantomReference extends java.lang.ref.PhantomReference<ZcashTransaction> {
    private static java.util.Set<ZcashTransactionPhantomReference> references = new HashSet<ZcashTransactionPhantomReference>();
    private static java.lang.ref.ReferenceQueue<ZcashTransaction> queue = new java.lang.ref.ReferenceQueue<ZcashTransaction>();
    private long nativeHandle;

    private ZcashTransactionPhantomReference(ZcashTransaction referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(ZcashTransaction referent, long nativeHandle) {
        references.add(new ZcashTransactionPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        ZcashTransactionPhantomReference ref = (ZcashTransactionPhantomReference) queue.poll();
        for (; ref != null; ref = (ZcashTransactionPhantomReference) queue.poll()) {
            ZcashTransaction.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
