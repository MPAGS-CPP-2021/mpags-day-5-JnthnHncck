//! Unit Tests for MPAGSCipher VigenereCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"

TEST_CASE("Small Key", "[vigenere]") {
  VigenereCipher vc1{"ijk"};
  REQUIRE(vc1.applyCipher("HELLO", CipherMode::Encrypt) == "PNVTX");
}

TEST_CASE("Big Key", "[vigenere]") {
  VigenereCipher vc2{"ababababababababababababababab"};
  REQUIRE(vc2.applyCipher("HELLOWORLD", CipherMode::Encrypt) == "HFLMOXOSLE");
}

TEST_CASE("No Key", "[vigenere]") {
  VigenereCipher vc3{""};
  REQUIRE(vc3.applyCipher("GOODBYE", CipherMode::Encrypt) == "QSMNFWO");
}

TEST_CASE("Decryption", "[vigenere]") {
  VigenereCipher vc4{"key"};
  REQUIRE(vc4.applyCipher("QSMNFWO", CipherMode::Decrypt) == "GOODBYE");
}