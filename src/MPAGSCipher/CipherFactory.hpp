#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP

#include <memory>
#include "Cipher.hpp"
#include "CipherType.hpp"

/**
 * \file VigenereCipher.hpp
 * \brief Contains the declaration of the factory function for ciphers
 */

/**
* \brief Creates a cipher object of the given type
*
* \param type What kind of cipher to make
* \param key The key that the cipher will use to encrypt and decrypt
*/
std::unique_ptr<Cipher> cipherFactory(const CipherType type, const std::string key);

#endif