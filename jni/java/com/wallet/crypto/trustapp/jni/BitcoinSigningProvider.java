// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.wallet.crypto.trustapp.jni;

import java.security.InvalidParameterException;
import java.util.HashSet;

public class BitcoinSigningProvider {
    private long nativeHandle;

    static BitcoinSigningProvider createFromNative(long nativeHandle) {
        BitcoinSigningProvider instance = new BitcoinSigningProvider();
        instance.nativeHandle = nativeHandle;
        BitcoinSigningProviderPhantomReference.register(instance, nativeHandle);
        return instance;
    }

    static native long nativeCreate();
    static native void nativeDelete(long handle);

    public native void addKey(PrivateKey key);
    public native void addRedeemScript(byte[] hash, BitcoinScript script);

    public BitcoinSigningProvider() {
        nativeHandle = nativeCreate();
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        BitcoinSigningProviderPhantomReference.register( this, nativeHandle);
    }

}

class BitcoinSigningProviderPhantomReference extends java.lang.ref.PhantomReference<BitcoinSigningProvider> {
    private static java.util.Set<BitcoinSigningProviderPhantomReference> references = new HashSet<BitcoinSigningProviderPhantomReference>();
    private static java.lang.ref.ReferenceQueue<BitcoinSigningProvider> queue = new java.lang.ref.ReferenceQueue<BitcoinSigningProvider>();
    private long nativeHandle;

    private BitcoinSigningProviderPhantomReference(BitcoinSigningProvider referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(BitcoinSigningProvider referent, long nativeHandle) {
        references.add(new BitcoinSigningProviderPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        BitcoinSigningProviderPhantomReference ref = (BitcoinSigningProviderPhantomReference) queue.poll();
        for (; ref != null; ref = (BitcoinSigningProviderPhantomReference) queue.poll()) {
            BitcoinSigningProvider.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
