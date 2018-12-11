// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.wallet.crypto.trustapp.jni;

import java.security.InvalidParameterException;
import java.util.HashSet;

public class HDWallet {
    private long nativeHandle;

    private HDWallet() {
        nativeHandle = 0;
    }

    static HDWallet createFromNative(long nativeHandle) {
        HDWallet instance = new HDWallet();
        instance.nativeHandle = nativeHandle;
        HDWalletPhantomReference.register(instance, nativeHandle);
        return instance;
    }

    static native long nativeCreateWithMnemonic(String mnemonic, String passphrase);
    static native void nativeDelete(long handle);

    public static native PublicKey getPublicKeyFromExtended(String extended, int versionPublic, int versionPrivate, int change, int address);
    public native byte[] seed();
    public native PrivateKey getKey(int purpose, int coin, int account, int change, int address);
    public native String getExtendedPrivateKey(int purpose, int coin, int version);
    public native String getExtendedPublicKey(int purpose, int coin, int version);

    public HDWallet(String mnemonic, String passphrase) {
        nativeHandle = nativeCreateWithMnemonic(mnemonic, passphrase);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        HDWalletPhantomReference.register(this, nativeHandle);
    }

}

class HDWalletPhantomReference extends java.lang.ref.PhantomReference<HDWallet> {
    private static java.util.Set<HDWalletPhantomReference> references = new HashSet<HDWalletPhantomReference>();
    private static java.lang.ref.ReferenceQueue<HDWallet> queue = new java.lang.ref.ReferenceQueue<HDWallet>();
    private long nativeHandle;

    private HDWalletPhantomReference(HDWallet referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(HDWallet referent, long nativeHandle) {
        references.add(new HDWalletPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        HDWalletPhantomReference ref = (HDWalletPhantomReference) queue.poll();
        for (; ref != null; ref = (HDWalletPhantomReference) queue.poll()) {
            HDWallet.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
