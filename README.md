# Trust Wallet Core Library

Trust wallet core is a cross-platform library that implements low-level cryptography for all supported blockchains. Everything is implement in C and exposed as a set of strict exported interfaces. The C header files are parsed by a Ruby code generator that generates idiomatic interfaces for for all supported paltforms (currently Swift for iOS, and Java for Android).

# Usage

If you want to use wallet core in your project follow these instructions.

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

# Contributing

To add functionality to wallet core follow these instructions.

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

The types that methods can take are restricted to: `bool`, `int`, `size_t`, `uint32_t`, `uint64_t`, fixed-size `uint8_t` array, fixed-size `char` array, and any defined classses or structs. Methods can only return `bool`, `int`, `size_t`, `uint32_t`, `uint64_t` and any defined classes or structs.

If you want a method to return a memory block the C declaration needs to take a fixed-size `uint8_t` array as its last argument and return a `size_t`. This will get converted to the relevant data type in the host language (e.g. `Data` in Swift and `byte[]` in Java).

Similarly, if you want a method to return a string, the C declaration needs to take a fixed-size `char` array as its last argument and return a `size_t`. This will get converted to the relevant string type in the host language (e.g. `String`).

Methods always take the type as their first argument. The type needs to be a pointer if the type is a class and a struct if the type is a struct. Properties need to take the type as its only argument.

Static property declarations can take no arguments. Static methods can take any arguments.

## Generating code

Every time the C headers are modified the code generator needs to be run to update the Java and Swift interfaces. Run `bin/codegen -h` to get usage information on the tool. Calling it with no arguments from the `codegen` folder should generate everything.
