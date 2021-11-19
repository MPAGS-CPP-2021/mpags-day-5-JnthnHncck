#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

/**
 * \file VigenereCipher.hpp
 * \brief Contains the declaration of the VigenereCipher class
 */

/**
 * \class VigenereCipher
 * \brief Encrypt or decrypt text using the Vigenere cipher with the given key
 */

class VigenereCipher
{
private:
    std::string key_{""};                       //Cipher Key
    std::map<char,CaesarCipher> charLookup_;    //Lookup table

public:
    /**
     * \brief Create a new PlayfairCipher with the given key
     *
     * \param key the key to use in the cipher
     */
    explicit VigenereCipher (const std::string& key);

    /**
     * \brief Saves the key provided by the user, and generates a map of characters to ciphers
     *
     * \param key the key to use in the cipher
     */
    void setKey(const std::string& key);

    /**
     * \brief Encrypts or decrypts the given text, using the Vigenere cipher
     *
     * \param inputText the string to apply the cipher to
     * \param cipherMode this tells us whether to encrypt or decrypt
     */
    std::string applyCipher(const std::string& inputText, \
    const CipherMode /*cipherMode*/ ) const;
};




#endif