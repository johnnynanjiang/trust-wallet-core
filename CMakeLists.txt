cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(TrustWalletCore)

add_subdirectory(trezor-crypto)

# Define sources
file(GLOB_RECURSE sources src/*.c src/*.h jni/cpp/*.c jni/cpp/*.h)

# Library
add_library(TrustWalletCore SHARED ${sources})

# Dependenies
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
