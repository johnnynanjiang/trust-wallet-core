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
  spec.vendored_libraries =
    'lib/ios/libprotobuf.a',
    'lib/ios/libTrezorCrypto.a',
    'lib/ios/libTrustWalletCore.a'
  s.source_files =
    'src/**/*.{c,cc,cpp,h}',
    'include/**/*.h',
    'swift/Sources/**/*.{swift,h,m}'
  s.public_header_files =
    'include/**/*.h',
    'swift/Sources/*.h'

  s.xcconfig = {
    'SYSTEM_HEADER_SEARCH_PATHS' => '$(inherited) ${PODS_ROOT}/TrustWalletCore/include '
  }
  s.dependency 'SwiftProtobuf', '~> 1.3.0'
end
