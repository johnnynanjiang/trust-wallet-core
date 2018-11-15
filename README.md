# Trust Wallet Core Library

## Before you start

* Install Xcode
* Install Xcode command line tools: `xcode-select --install`
* Install CMake: `brew install cmake ninja`
* Install [Android Studio](https://developer.android.com/studio/index.html)
* Install the [Android NDK](https://developer.android.com/ndk/guides/)

## Android

To include the library in an Android app add these lines to you app module's `build.gradle` file:

```groovy
sourceSets {
    main.java.srcDirs += 'path-to-trust-wallet-core/jni/java'
}
externalNativeBuild {
    cmake {
        path "path-to-trust-wallet-core/CMakeLists.txt"
    }
}
```

## iOS

To include the library in an iOS app add the Xcode project as a dependency of your project or use CocoaPods.
