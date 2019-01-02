cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(TrustWalletCore)

set (CMAKE_CXX_STANDARD 14)
add_subdirectory(trezor-crypto)

if(${ANDROID})
    message("Configuring for JNI")
    file(GLOB_RECURSE sources src/*.c src/*.cpp src/*.h jni/cpp/*.c jni/cpp/*.cpp jni/cpp/*.h)
    add_library(TrustWalletCore SHARED ${sources})
else()
    message("Configuring standalone")
    file(GLOB_RECURSE sources src/*.c src/*.cpp src/*.h)
    add_library(TrustWalletCore ${sources})
endif()

# Dependencies
target_link_libraries(TrustWalletCore TrezorCrypto)

# Define headers for this library. PUBLIC headers are used for compiling the
# library, and will be added to consumers' build paths.
target_include_directories(TrustWalletCore
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/jni/cpp
)

if(NOT ANDROID)
    add_subdirectory(tests)
endif()
