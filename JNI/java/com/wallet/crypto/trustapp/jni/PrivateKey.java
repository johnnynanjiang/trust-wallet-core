package com.wallet.crypto.trustapp.jni;

import java.security.InvalidParameterException;
import java.security.SecureRandom;
import java.util.HashSet;

public class PrivateKey {
    long nativeHandle;

    static {
        System.loadLibrary("TrustWalletCore");
    }

    static native long nativeCreateWithData(byte[] data);
    static native void delete(long handle);

    private PrivateKey(long nativeHandle) {
        this.nativeHandle = nativeHandle;
    }

    public static PrivateKey createRandom() {
        SecureRandom random = new SecureRandom();
        byte bytes[] = new byte[32];
        random.nextBytes(bytes);

        return createWithData(bytes);
    }

    public static PrivateKey createWithData(byte[] data) {
        long handle = nativeCreateWithData(data);
        if (handle == 0) {
            throw new InvalidParameterException();
        }

        PrivateKey instance = new PrivateKey(handle);
        PrivateKeyPhantomReference.register(instance, handle);
        return instance;
    }
}

class PrivateKeyPhantomReference extends java.lang.ref.PhantomReference<PrivateKey> {
    private static java.util.Set<PrivateKeyPhantomReference> references = new HashSet<PrivateKeyPhantomReference>();
    private static java.lang.ref.ReferenceQueue<PrivateKey> queue = new java.lang.ref.ReferenceQueue<PrivateKey>();
    private long nativeHandle;

    private PrivateKeyPhantomReference(PrivateKey referent, long nativeHandle) {
        super(referent, queue);
        nativeHandle = nativeHandle;
    }

    static void register(PrivateKey referent, long nativeHandle) {
        references.add(new PrivateKeyPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        PrivateKeyPhantomReference ref = (PrivateKeyPhantomReference) queue.poll();
        for (; ref != null; ref = (PrivateKeyPhantomReference) queue.poll()) {
            PrivateKey.delete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
