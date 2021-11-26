//! Unit Tests for MPAGSCipher Cipher PABC
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include "CipherFactory.hpp"

TEST_CASE("Encrypt", "[cipher]") {
  std::vector<std::unique_ptr<Cipher>> collection;
  collection.push_back(cipherFactory(CipherType::Caesar, "5"));
  collection.push_back(cipherFactory(CipherType::Playfair, "hello"));
  collection.push_back(cipherFactory(CipherType::Vigenere, "abcde"));

  std::vector<std::string> answers;
  answers.push_back("GTGNXXTRJXTWYTKOZSNTWHTRUQJCCJSTUMTSJTSJEJWTYMNSL");
  answers.push_back("FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA");
  answers.push_back("BPDLWSPOHWOSVRJJVPLSRDQPTLFZAINPRKSNFQQIZFTRXHJPJ");
  
  for (size_t i{0}; i<collection.size(); i++) {
  REQUIRE(collection[i]->applyCipher("BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", CipherMode::Encrypt) == answers[i]);
  }
}

TEST_CASE("Decrypt", "[cipher]") {
  std::vector<std::unique_ptr<Cipher>> collection;
  collection.push_back(cipherFactory(CipherType::Caesar, "5"));
  collection.push_back(cipherFactory(CipherType::Playfair, "hello"));
  collection.push_back(cipherFactory(CipherType::Vigenere, "abcde"));

  std::vector<std::string> inputs;
  inputs.push_back("GTGNXXTRJXTWYTKOZSNTWHTRUQJCCJSTUMTSJTSJEJWTYMNSL");
  inputs.push_back("FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA");
  inputs.push_back("BPDLWSPOHWOSVRJJVPLSRDQPTLFZAINPRKSNFQQIZFTRXHJPJ");

  std::vector<std::string> answers;
  answers.push_back("BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING");
  answers.push_back("BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ");
  answers.push_back("BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING");

  for (size_t i{0}; i<collection.size(); i++) {
  REQUIRE(collection[i]->applyCipher(inputs[i], CipherMode::Decrypt) == answers[i]);
  }
}