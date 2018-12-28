cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(TrustWalletCore)

set (CMAKE_CXX_STANDARD 14)
add_subdirectory(trezor-crypto)

# Protobuf
find_library(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Generate Protobuf C++ files
execute_process(COMMAND protoc -I=src --cpp_out=src --javalite_out=jni/java src/TrustWalletCore.proto
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
if(result)
  message(FATAL_ERROR "protobuf generation failed: ${result}")
endif()

# Generate Proto interface file
execute_process(
    COMMAND mkdir -p build
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/protobuf-plugin"
)
execute_process(
    COMMAND ${CMAKE_COMMAND} ..
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/protobuf-plugin/build"
)
execute_process(
    COMMAND make
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/protobuf-plugin/build"
)
execute_process(
    COMMAND protoc -I=../../src --plugin=protoc-gen-int=protoc-gen-int --int_out ../../include/TrustWalletCore ../../src/TrustWalletCore.proto
    RESULT_VARIABLE result
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/protobuf-plugin/build"
)
if(result)
  message(FATAL_ERROR "protobuf generation failed: ${result}")
endif()

# Source files
if(${ANDROID})
    message("Configuring for JNI")
    file(GLOB_RECURSE sources src/*.c src/*.cc src/*.cpp src/*.h jni/cpp/*.c jni/cpp/*.cpp jni/cpp/*.h)
    add_library(TrustWalletCore SHARED ${sources} ${PROTO_SRCS} ${PROTO_HDRS})
else()
    message("Configuring standalone")
    file(GLOB_RECURSE sources src/*.c src/*.cc src/*.cpp src/*.h)
    add_library(TrustWalletCore ${sources} ${PROTO_SRCS} ${PROTO_HDRS})
endif()

# Dependencies
target_link_libraries(TrustWalletCore TrezorCrypto protobuf-lite)

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
    add_subdirectory(protobuf-plugin)
    add_subdirectory(tests)
endif()
