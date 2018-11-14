package com.wallet.crypto.trustapp.jni;

import java.util.HashSet;

public class PrivateKey {
    long nativeHandle;

    static native long create();
    static native long createWithData(byte[] data);
    static native void delete(long handle);

    private PrivateKey(long nativeHandle) {
        this.nativeHandle = nativeHandle;
    }

    public static PrivateKey getInstance() {
        long handle = create();
        PrivateKey instance = new PrivateKey(handle);
        PKPhantomReference.register(instance, handle);
        return instance;
    }
}

class PKPhantomReference extends java.lang.ref.PhantomReference<PrivateKey> {
    private static java.util.Set<PKPhantomReference> references = new HashSet<PKPhantomReference>();
    private static java.lang.ref.ReferenceQueue<PrivateKey> queue = new java.lang.ref.ReferenceQueue<PrivateKey>();
    private long nativeHandle;

    private PKPhantomReference(PrivateKey referent, long nativeHandle) {
        super(referent, queue);
        nativeHandle = nativeHandle;
    }

    static void register(PrivateKey referent, long nativeHandle) {
        references.add(new PKPhantomReference(referent, nativeHandle));
    }

    public static void doDeletes() {
        PKPhantomReference ref = (PKPhantomReference) queue.poll();
        for (; ref != null; ref = (PKPhantomReference) queue.poll()) {
            PrivateKey.delete(ref.nativeHandle);
            references.remove(ref);
        }
    }
}
