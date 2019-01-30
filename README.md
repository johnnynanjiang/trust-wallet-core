# Trust Wallet Core Library

Trust wallet core is a cross-platform library that implements low-level cryptography for all supported blockchains. Everything is implement in C and exposed as a set of strict exported interfaces. The C header files are parsed by a Ruby code generator that generates idiomatic interfaces for for all supported paltforms (currently Swift for iOS, and Java for Android).

# Usage

If you want to use wallet core in your project follow these instructions.

## Before you start

* Install Xcode
* Install Xcode command line tools: `xcode-select --install`
* Install CMake, boost, protobuf: `brew install cmake ninja boost protobuf swift-protobuf`
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

# Contributing

To add functionality to wallet core follow these instructions.

## Project organization

This project has a number of different pieces. Each piece lives in its own subfolder.
* The `src` folder contains the C++ implementation of the core functionality.
* The `include` folder contains the public C header files used to expose a cross-platform interface.
* The `codegen` folder contains the code and templates used to generate code for different platforms and languages.
* The `jni` folder contains the generated JNI interface and Java classes.
* The `swift` folder contains the generated Swift code.
* The `trezor-crypto` folder contains a fork of https://github.com/trezor/trezor-crypto/ with modifications.
* The `tests` folder contains unit tests.

## Building

Use the `bootstrap.sh` script in the root folder to quickly build and test.

The build pipeline uses CMake. If you add or rename files you need to re-run cmake: `cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Debug -DGIT_SUBMODULE=OFF`. If you only change existing files and want to run the tests you only need to run make: `make -C build tests`.

If you change interface files in the include folder you need to regenerate the interface code: `codegen/bin/codegen`. Run `codegen/bin/codegen -h` to get usage information on the tool.

## C Headers

The wallet core code generator parses C headers for class and struct definitions. Headers need to be in the `include/TrustWalletCode` folder and start with the `TW` prefix followed by the class or sturct name. Inside each header file there needs to be exactly one class or struct defition.

A class definition starts with the `TW_EXPORT_CLASS` macro followed by a forward-declared struct. For example:
```c
TW_EXPORT_CLASS
struct TWPrivateKey;
```

Similarly, a struct definition start with the `TW_EXPORT_STRUCT` macro followed by an inline-declared struct. For example:
```c
TW_EXPORT_STRUCT
struct TWPublicKey {
    uint8_t bytes[TWPublicKeyUncompressedSize];
};
```

After the class or struct definition you can declare as many methods and properties as necessary. There are four types of declarations: static method, static property, method, and property. Each is declared by `TW_EXPORT_STATIC_METHOD`, `TW_EXPORT_STATIC_PROPERTY`, `TW_EXPORT_METHOD`, and `TW_EXPORT_PROPERTY` respectively. Each method or property name needs to start with the type name. For instance `TWPublicKeyIsValid` gets translated to the `isValid` property in the `PublicKey` type.

The types that methods can take and return are restricted to: `bool`, `int`, `size_t`, `uint8_t`, `uint16_t`, `uint32_t`, `uint64_t`, `TWData`, `TWString`, and any defined classses or structs.

Methods always take the type as their first argument. The type needs to be a pointer if the type is a class and a struct if the type is a struct. Properties need to take the type as its only argument.

Static property declarations can take no arguments. Static methods can take any arguments.
