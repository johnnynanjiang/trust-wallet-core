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
    http: "https://s3.amazonaws.com/wallet-core/TrustWalletCore-iOS-#{version}.zip"
  }
  s.preserve_paths = 'build/ios/*.a'
  s.vendored_libraries =
    'build/ios/libprotobuf.a',
    'build/ios/libTrezorCrypto.a',
    'build/ios/libTrustWalletCore.a'
  s.source_files =
    'include/**/*.h',
    'swift/Sources/**/*.{swift,h,m,cpp}'
  s.public_header_files =
    'include/**/*.h',
    'swift/Sources/*.h'
  s.libraries = 'c++'
  s.xcconfig = {
    'SYSTEM_HEADER_SEARCH_PATHS' => '$(inherited) ${PODS_ROOT}/TrustWalletCore/include',
    'OTHER_LDFLAGS' => '$(inherited) -fprofile-instr-generate'
  }
  s.dependency 'SwiftProtobuf', '~> 1.3.0'
end
