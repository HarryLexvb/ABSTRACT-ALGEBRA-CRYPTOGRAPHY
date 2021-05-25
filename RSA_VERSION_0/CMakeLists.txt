cmake_minimum_required(VERSION 3.19)
project(RSA_VERSION_0)

set(CMAKE_CXX_STANDARD 20)

add_executable(RSA_VERSION_0 main.cpp Crypto_Math.cpp Crypto_Math.h RSA_Cipher.cpp RSA_Cipher.h)