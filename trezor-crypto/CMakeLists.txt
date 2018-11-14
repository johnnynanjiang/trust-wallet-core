add_library(TrezorCrypto
    bignum.c ecdsa.c curves.c secp256k1.c nist256p1.c rand.c hmac.c bip32.c bip39.c pbkdf2.c base58.c base32.c
    address.c
    script.c
    ripemd160.c
    sha2.c
    sha3.c
    hasher.c
    aes/aescrypt.c aes/aeskey.c aes/aestab.c aes/aes_modes.c
    ed25519-donna/curve25519-donna-32bit.c ed25519-donna/curve25519-donna-helpers.c ed25519-donna/modm-donna-32bit.c
    ed25519-donna/ed25519-donna-basepoint-table.c ed25519-donna/ed25519-donna-32bit-tables.c ed25519-donna/ed25519-donna-impl-base.c
    ed25519-donna/ed25519.c ed25519-donna/curve25519-donna-scalarmult-base.c ed25519-donna/ed25519-sha3.c ed25519-donna/ed25519-keccak.c
    monero/base58.c
    monero/serialize.c
    monero/xmr.c
    monero/range_proof.c
    blake256.c
    blake2b.c blake2s.c
    groestl.c
    chacha20poly1305/chacha20poly1305.c chacha20poly1305/chacha_merged.c chacha20poly1305/poly1305-donna.c chacha20poly1305/rfc7539.c
    rc4.c
    nem.c
    segwit_addr.c cash_addr.c
    memzero.c
)

target_compile_options(TrezorCrypto
    PUBLIC
        -DRAND_PLATFORM_INDEPENDENT=1
        -DUSE_ETHEREUM=1
        -DUSE_GRAPHENE=1
        -DUSE_KECCAK=1
        -DUSE_MONERO=1
        -DUSE_NEM=1
        -DUSE_CARDANO=1
    PRIVATE
        -W
        -Wall
        -Wextra
        -Wimplicit-function-declaration
        -Wredundant-decls
        -Wstrict-prototypes
        -Wundef
        -Wshadow
        -Wpointer-arith
        -Wformat
        -Wreturn-type
        -Wsign-compare
        -Wmultichar
        -Wformat-nonliteral
        -Winit-self
        -Wuninitialized
        -Wformat-security
        -Werror
)

target_include_directories(TrezorCrypto
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:>
)
