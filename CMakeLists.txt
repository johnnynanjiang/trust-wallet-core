cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(TrustWalletCore)

set (CMAKE_CXX_STANDARD 14)
add_subdirectory(trezor-crypto)

find_package(Boost)

# Submodules
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/lib/googletest/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

# JSON
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(lib/json)

# Protobuf
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib/protobuf/src")
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_library(protobuf
    lib/protobuf/src/google/protobuf/stubs/bytestream.cc
    lib/protobuf/src/google/protobuf/stubs/bytestream.h
    lib/protobuf/src/google/protobuf/stubs/common.cc
    lib/protobuf/src/google/protobuf/stubs/hash.h
    lib/protobuf/src/google/protobuf/stubs/int128.cc
    lib/protobuf/src/google/protobuf/stubs/int128.h
    lib/protobuf/src/google/protobuf/stubs/map_util.h
    lib/protobuf/src/google/protobuf/stubs/mathutil.h
    lib/protobuf/src/google/protobuf/stubs/status.cc
    lib/protobuf/src/google/protobuf/stubs/status.h
    lib/protobuf/src/google/protobuf/stubs/status_macros.h
    lib/protobuf/src/google/protobuf/stubs/statusor.cc
    lib/protobuf/src/google/protobuf/stubs/statusor.h
    lib/protobuf/src/google/protobuf/stubs/stringpiece.cc
    lib/protobuf/src/google/protobuf/stubs/stringpiece.h
    lib/protobuf/src/google/protobuf/stubs/stringprintf.cc
    lib/protobuf/src/google/protobuf/stubs/stringprintf.h
    lib/protobuf/src/google/protobuf/stubs/structurally_valid.cc
    lib/protobuf/src/google/protobuf/stubs/strutil.cc
    lib/protobuf/src/google/protobuf/stubs/time.cc
    lib/protobuf/src/google/protobuf/stubs/time.h
    lib/protobuf/src/google/protobuf/arena.cc
    lib/protobuf/src/google/protobuf/extension_set.cc
    lib/protobuf/src/google/protobuf/generated_message_util.cc
    lib/protobuf/src/google/protobuf/generated_message_table_driven_lite.h
    lib/protobuf/src/google/protobuf/generated_message_table_driven_lite.cc
    lib/protobuf/src/google/protobuf/implicit_weak_message.cc
    lib/protobuf/src/google/protobuf/message_lite.cc
    lib/protobuf/src/google/protobuf/repeated_field.cc
    lib/protobuf/src/google/protobuf/wire_format_lite.cc
    lib/protobuf/src/google/protobuf/io/coded_stream.cc
    lib/protobuf/src/google/protobuf/io/coded_stream_inl.h
    lib/protobuf/src/google/protobuf/io/strtod.cc
    lib/protobuf/src/google/protobuf/io/zero_copy_stream.cc
    lib/protobuf/src/google/protobuf/io/zero_copy_stream_impl_lite.cc
    lib/protobuf/src/google/protobuf/any.pb.cc
    lib/protobuf/src/google/protobuf/api.pb.cc
    lib/protobuf/src/google/protobuf/stubs/mathlimits.cc
    lib/protobuf/src/google/protobuf/stubs/mathlimits.h
    lib/protobuf/src/google/protobuf/any.cc
    lib/protobuf/src/google/protobuf/descriptor.cc
    lib/protobuf/src/google/protobuf/descriptor_database.cc
    lib/protobuf/src/google/protobuf/descriptor.pb.cc
    lib/protobuf/src/google/protobuf/duration.pb.cc
    lib/protobuf/src/google/protobuf/dynamic_message.cc
    lib/protobuf/src/google/protobuf/empty.pb.cc
    lib/protobuf/src/google/protobuf/extension_set_heavy.cc
    lib/protobuf/src/google/protobuf/field_mask.pb.cc
    lib/protobuf/src/google/protobuf/generated_message_reflection.cc
    lib/protobuf/src/google/protobuf/generated_message_table_driven_lite.h
    lib/protobuf/src/google/protobuf/generated_message_table_driven.cc
    lib/protobuf/src/google/protobuf/map_field.cc
    lib/protobuf/src/google/protobuf/message.cc
    lib/protobuf/src/google/protobuf/reflection_internal.h
    lib/protobuf/src/google/protobuf/reflection_ops.cc
    lib/protobuf/src/google/protobuf/service.cc
    lib/protobuf/src/google/protobuf/source_context.pb.cc
    lib/protobuf/src/google/protobuf/struct.pb.cc
    lib/protobuf/src/google/protobuf/stubs/substitute.cc
    lib/protobuf/src/google/protobuf/stubs/substitute.h
    lib/protobuf/src/google/protobuf/text_format.cc
    lib/protobuf/src/google/protobuf/timestamp.pb.cc
    lib/protobuf/src/google/protobuf/type.pb.cc
    lib/protobuf/src/google/protobuf/unknown_field_set.cc
    lib/protobuf/src/google/protobuf/wire_format.cc
    lib/protobuf/src/google/protobuf/wrappers.pb.cc
    lib/protobuf/src/google/protobuf/io/gzip_stream.cc
    lib/protobuf/src/google/protobuf/io/printer.cc
    lib/protobuf/src/google/protobuf/io/strtod.cc
    lib/protobuf/src/google/protobuf/io/tokenizer.cc
    lib/protobuf/src/google/protobuf/io/zero_copy_stream_impl.cc
    lib/protobuf/src/google/protobuf/compiler/importer.cc
    lib/protobuf/src/google/protobuf/compiler/parser.cc
    lib/protobuf/src/google/protobuf/util/delimited_message_util.cc
    lib/protobuf/src/google/protobuf/util/field_comparator.cc
    lib/protobuf/src/google/protobuf/util/field_mask_util.cc
    lib/protobuf/src/google/protobuf/util/internal/constants.h
    lib/protobuf/src/google/protobuf/util/internal/datapiece.cc
    lib/protobuf/src/google/protobuf/util/internal/datapiece.h
    lib/protobuf/src/google/protobuf/util/internal/default_value_objectwriter.cc
    lib/protobuf/src/google/protobuf/util/internal/default_value_objectwriter.h
    lib/protobuf/src/google/protobuf/util/internal/error_listener.cc
    lib/protobuf/src/google/protobuf/util/internal/error_listener.h
    lib/protobuf/src/google/protobuf/util/internal/expecting_objectwriter.h
    lib/protobuf/src/google/protobuf/util/internal/field_mask_utility.cc
    lib/protobuf/src/google/protobuf/util/internal/field_mask_utility.h
    lib/protobuf/src/google/protobuf/util/internal/json_escaping.cc
    lib/protobuf/src/google/protobuf/util/internal/json_escaping.h
    lib/protobuf/src/google/protobuf/util/internal/json_objectwriter.cc
    lib/protobuf/src/google/protobuf/util/internal/json_objectwriter.h
    lib/protobuf/src/google/protobuf/util/internal/json_stream_parser.cc
    lib/protobuf/src/google/protobuf/util/internal/json_stream_parser.h
    lib/protobuf/src/google/protobuf/util/internal/location_tracker.h
    lib/protobuf/src/google/protobuf/util/internal/mock_error_listener.h
    lib/protobuf/src/google/protobuf/util/internal/object_location_tracker.h
    lib/protobuf/src/google/protobuf/util/internal/object_source.h
    lib/protobuf/src/google/protobuf/util/internal/object_writer.cc
    lib/protobuf/src/google/protobuf/util/internal/object_writer.h
    lib/protobuf/src/google/protobuf/util/internal/protostream_objectsource.cc
    lib/protobuf/src/google/protobuf/util/internal/protostream_objectsource.h
    lib/protobuf/src/google/protobuf/util/internal/protostream_objectwriter.cc
    lib/protobuf/src/google/protobuf/util/internal/protostream_objectwriter.h
    lib/protobuf/src/google/protobuf/util/internal/proto_writer.cc
    lib/protobuf/src/google/protobuf/util/internal/proto_writer.h
    lib/protobuf/src/google/protobuf/util/internal/structured_objectwriter.h
    lib/protobuf/src/google/protobuf/util/internal/type_info.cc
    lib/protobuf/src/google/protobuf/util/internal/type_info.h
    lib/protobuf/src/google/protobuf/util/internal/type_info_test_helper.cc
    lib/protobuf/src/google/protobuf/util/internal/type_info_test_helper.h
    lib/protobuf/src/google/protobuf/util/internal/utility.cc
    lib/protobuf/src/google/protobuf/util/internal/utility.h
    lib/protobuf/src/google/protobuf/util/json_util.cc
    lib/protobuf/src/google/protobuf/util/message_differencer.cc
    lib/protobuf/src/google/protobuf/util/time_util.cc
    lib/protobuf/src/google/protobuf/util/type_resolver_util.cc
)
target_compile_options(protobuf PRIVATE -DHAVE_PTHREAD=1)
set_target_properties(protobuf PROPERTIES LINK_FLAGS -no-undefined)

# Source files
if(${ANDROID})
    message("Configuring for JNI")
    file(GLOB_RECURSE sources src/*.c src/*.cc src/*.cpp src/*.h jni/cpp/*.c jni/cpp/*.cpp jni/cpp/*.h)
    add_library(TrustWalletCore SHARED ${sources} ${PROTO_SRCS} ${PROTO_HDRS})

    find_library(log-lib log)
    target_link_libraries(TrustWalletCore PRIVATE TrezorCrypto protobuf ${log-lib} Boost::boost nlohmann_json::nlohmann_json)
else()
    message("Configuring standalone")
    file(GLOB_RECURSE sources src/*.c src/*.cc src/*.cpp src/*.h)
    add_library(TrustWalletCore ${sources} ${PROTO_SRCS} ${PROTO_HDRS})

    target_link_libraries(TrustWalletCore PRIVATE TrezorCrypto protobuf Boost::boost nlohmann_json::nlohmann_json)
endif()

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

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/swift/cpp.xcconfig.in ${CMAKE_CURRENT_SOURCE_DIR}/swift/cpp.xcconfig @ONLY)
