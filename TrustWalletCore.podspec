version = `git describe --long --tags | cut -f 1 -d '-'`.chomp

Pod::Spec.new do |s|
  s.name         = 'TrustWalletCore'
  s.version      = version
  s.summary      = 'Trust Wallet core data structures and algorithms.'
  s.homepage     = 'https://github.com/TrustWallet/trust-wallet-core'
  s.license      = 'MIT'
  s.authors      = { 'Alejandro Isaza' => 'al@isaza.ca' }

  s.ios.deployment_target = '10.0'
  s.osx.deployment_target = '10.12'
  s.swift_version = '4.0'

  s.source = {
    git: 'git@github.com:TrustWallet/trust-wallet-core.git',
    tag: version
  }

  s.source_files =
    'src/**/*.{c,h}',
    'include/**/*.h',
    'swift/Sources/**/*.{swift,m}',
    'trezor-crypto/src/**/*.{c,h}',
    'trezor-crypto/include/**/*.{h}'
  s.exclude_files =
    'trezor-crypto/src/gui/*.{c,h}',
    'trezor-crypto/src/sqlite/*.{c,h}'
  s.public_header_files =
    'include/**/*.h'

  s.preserve_path = 'trezor-crypto/src/*.{table}'
  s.xcconfig = {
    'OTHER_CFLAGS' => '$(inherited) -DRAND_PLATFORM_INDEPENDENT=1 -DUSE_ETHEREUM=1 -DUSE_GRAPHENE=1 -DUSE_KECCAK=1 -DUSE_MONERO=1 -DUSE_NEM=1 -DUSE_CARDANO=1',
    'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/TrustWalletCore/src ${PODS_ROOT}/TrustWalletCore/trezor-crypto/src',
    'SYSTEM_HEADER_SEARCH_PATHS' => '${PODS_ROOT}/TrustWalletCore/include ${PODS_ROOT}/TrustWalletCore/trezor-crypto/include',
    'GCC_WARN_64_TO_32_BIT_CONVERSION' => 'NO'
  }
end
