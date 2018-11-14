cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(TrustWalletCore)

# Define sources
file(GLOB_RECURSE sources ../Sources/*.c ../Sources/*.h cpp/*.c cpp/*.h)

# Library
add_library(TrustWalletCore SHARED ${sources})

include_directories(../Sources)
