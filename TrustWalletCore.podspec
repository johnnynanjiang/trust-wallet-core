version = '0.0.4'

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
    tag: version
  }

  s.source_files =
    'src/**/*.{c,cpp,h}',
    'include/**/*.h',
    'swift/Sources/**/*.{swift,h,m}',
    'trezor-crypto/src/**/*.{c,h}',
    'trezor-crypto/include/**/*.{h}'
  s.exclude_files =
    'trezor-crypto/src/gui/*.{c,h}',
    'trezor-crypto/src/sqlite/*.{c,h}',
    'trezor-crypto/src/rand.c'
  s.public_header_files =
    'include/**/*.h',
    'swift/Sources/*.h'

  s.preserve_path = 'trezor-crypto/src/*.{table}'
  s.xcconfig = {
    'HEADER_SEARCH_PATHS' => '$(inherited) ${PODS_ROOT}/TrustWalletCore/src ${PODS_ROOT}/TrustWalletCore/trezor-crypto/src',
    'SYSTEM_HEADER_SEARCH_PATHS' => '$(inherited) ${PODS_ROOT}/TrustWalletCore/include ${PODS_ROOT}/TrustWalletCore/trezor-crypto/include',
    'GCC_WARN_UNUSED_FUNCTION' => 'NO',
    'GCC_WARN_64_TO_32_BIT_CONVERSION' => 'NO'
  }
end
