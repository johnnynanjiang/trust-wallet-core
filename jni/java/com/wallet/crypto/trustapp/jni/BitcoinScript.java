// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.wallet.crypto.trustapp.jni;

import java.security.InvalidParameterException;
import java.util.HashSet;

public class BitcoinScript {
    private long nativeHandle;

    private BitcoinScript() {
        nativeHandle = 0;
    }

    static BitcoinScript createFromNative(long nativeHandle) {
        BitcoinScript instance = new BitcoinScript();
        instance.nativeHandle = nativeHandle;
        BitcoinScriptPhantomReference.register(instance, nativeHandle);
        return instance;
    }

    static native long nativeCreate(byte[] data);
    static native void nativeDelete(long handle);

    public static native int decodeNumber(char opcode);
    public native int size();
    public native byte[] data();
    public native boolean isPayToScriptHash();
    public native boolean isPayToWitnessScriptHash();
    public native boolean isWitnessProgram();
    public native byte[] matchPayToPubkey();
    public native byte[] matchPayToPubkeyHash();
    public native byte[] matchPayToScriptHash();
    public native byte[] matchPayToWitnessPublicKeyHash();
    public native byte[] matchPayToWitnessScriptHash();
    public native byte[] encode();

    public BitcoinScript(byte[] data) {
        nativeHandle = nativeCreate(data);
        if (nativeHandle == 0) {
            throw new InvalidParameterException();
        }

        BitcoinScriptPhantomReference.register(this, nativeHandle);
    }

}

class BitcoinScriptPhantomReference extends java.lang.ref.PhantomReference<BitcoinScript> {
    private static java.util.Set<BitcoinScriptPhantomReference> references = new HashSet<BitcoinScriptPhantomReference>();
    private static java.lang.ref.ReferenceQueue<BitcoinScript> queue = new java.lang.ref.ReferenceQueue<BitcoinScript>();
    private long nativeHandle;

    private BitcoinScriptPhantomReference(BitcoinScript referent, long nativeHandle) {
        super(referent, queue);
        this.nativeHandle = nativeHandle;
    }

    static void register(BitcoinScript referent, long nativeHandle) {
        references.add(new BitcoinScriptPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        BitcoinScriptPhantomReference ref = (BitcoinScriptPhantomReference) queue.poll();
        for (; ref != null; ref = (BitcoinScriptPhantomReference) queue.poll()) {
            BitcoinScript.nativeDelete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
