version = '0.3.0'

Pod::Spec.new do |s|
  s.name         = 'TrustWalletCore'
  s.version      = version
  s.summary      = 'Trust Wallet core data structures and algorithms.'
  s.homepage     = 'https://github.com/TrustWallet/trust-wallet-core'
  s.license      = 'MIT'
  s.authors      = { 'Alejandro Isaza' => 'al@isaza.ca' }

  s.ios.deployment_target = '10.0'
  s.osx.deployment_target = '10.12'
  s.swift_version = '4.2'

  s.source = {
    git: 'git@github.com:TrustWallet/trust-wallet-core.git',
    tag: version,
    submodules: true
  }

  s.source_files =
    'src/**/*.{c,cc,cpp,h}',
    'include/**/*.h',
    'swift/Sources/**/*.{swift,h,m}',
    'trezor-crypto/src/**/*.{c,h}',
    'trezor-crypto/include/**/*.{h}',
    'lib/protobuf/src/google/protobuf/stubs/bytestream.cc',
    'lib/protobuf/src/google/protobuf/stubs/callback.cc',
    'lib/protobuf/src/google/protobuf/stubs/common.cc',
    'lib/protobuf/src/google/protobuf/stubs/int128.cc',
    'lib/protobuf/src/google/protobuf/stubs/status.cc',
    'lib/protobuf/src/google/protobuf/stubs/statusor.cc',
    'lib/protobuf/src/google/protobuf/stubs/stringpiece.cc',
    'lib/protobuf/src/google/protobuf/stubs/stringprintf.cc',
    'lib/protobuf/src/google/protobuf/stubs/structurally_valid.cc',
    'lib/protobuf/src/google/protobuf/stubs/strutil.cc',
    'lib/protobuf/src/google/protobuf/stubs/time.cc',
    'lib/protobuf/src/google/protobuf/arena.cc',
    'lib/protobuf/src/google/protobuf/extension_set.cc',
    'lib/protobuf/src/google/protobuf/generated_message_util.cc',
    'lib/protobuf/src/google/protobuf/generated_message_table_driven_lite.cc',
    'lib/protobuf/src/google/protobuf/implicit_weak_message.cc',
    'lib/protobuf/src/google/protobuf/message_lite.cc',
    'lib/protobuf/src/google/protobuf/repeated_field.cc',
    'lib/protobuf/src/google/protobuf/wire_format_lite.cc',
    'lib/protobuf/src/google/protobuf/io/coded_stream.cc',
    'lib/protobuf/src/google/protobuf/io/strtod.cc',
    'lib/protobuf/src/google/protobuf/io/zero_copy_stream.cc',
    'lib/protobuf/src/google/protobuf/io/zero_copy_stream_impl_lite.cc'
  s.exclude_files =
    'trezor-crypto/src/gui/*.{c,h}',
    'trezor-crypto/src/sqlite/*.{c,h}',
    'trezor-crypto/src/rand.c'
  s.public_header_files =
    'include/**/*.h',
    'swift/Sources/*.h'

  s.preserve_paths =
    'trezor-crypto/src/*.{table}',
    'lib/protobuf/src/google/protobuf/**/*.h',
    'lib/json/include/**/*.h'
  s.xcconfig = {
    'HEADER_SEARCH_PATHS' => '$(inherited) ' \
      '${PODS_ROOT}/TrustWalletCore/src ' \
      '${PODS_ROOT}/TrustWalletCore/trezor-crypto/src',
    'SYSTEM_HEADER_SEARCH_PATHS' => '$(inherited) ' \
      '${PODS_ROOT}/TrustWalletCore/include ' \
      '${PODS_ROOT}/TrustWalletCore/trezor-crypto/include ' \
      '${PODS_ROOT}/TrustWalletCore/lib/protobuf/src ' \
      '${PODS_ROOT}/TrustWalletCore/lib/json/include',
    'GCC_WARN_UNUSED_FUNCTION' => 'NO',
    'GCC_WARN_64_TO_32_BIT_CONVERSION' => 'NO',
    'CLANG_CXX_LANGUAGE_STANDARD' => 'gnu++14',
    'OTHER_CFLAGS' => '-DHAVE_PTHREAD=1'
  }

  s.dependency 'SwiftProtobuf', '~> 1.3.0'
end
