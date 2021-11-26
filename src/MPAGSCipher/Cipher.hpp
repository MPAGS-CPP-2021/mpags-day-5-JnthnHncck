#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

#include <string>
#include "CipherMode.hpp"

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the Cipher PABC
 */

/**
 * \class Cipher
 * \brief A PABC created for the cipher classes to inherit from
 */

class Cipher
{
public:
    Cipher() = default;
    Cipher(const Cipher& rhs) = default;
    Cipher(Cipher&& rhs) = default;
    Cipher& operator=(const Cipher& rhs) = default;
    Cipher& operator=(Cipher&& rhs) = default;
    virtual ~Cipher() = default;

    /**
     * \brief Encrypts or decrypts the supplied text
     *
     * \param input The text which is encrypted for decrypted
     * \param mode An enumeration describing whether to encrypt or decrypt
     */
    virtual std::string applyCipher( const std::string& input,
    const CipherMode mode ) const = 0;
};

#endif