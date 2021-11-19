#include "VigenereCipher.hpp"


VigenereCipher::VigenereCipher (const std::string& key)
{
// Set the given key
setKey(key);
}

void VigenereCipher::setKey(const std::string& key)
{
    // Store the key
    key_ = key;

    // Make sure the key is uppercase
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                   ::toupper);

    // Remove non-alphabet characters
    key_.erase(std::remove_if(std::begin(key_), std::end(key_),
                              [](char c) { return !std::isalpha(c); }),
               std::end(key_));

    // Check if the key is empty and replace with default if so
    if (key_ == "") {
        key_ = "KEY";
    }

    // loop over the key
    for (const auto& elem : key_) {
        // Find the letter position in the alphabet
        //A=65 in ascii, so we subtract 65 to get a 0-indexed position in the alphabet
        int value{int(elem) - 65};

        // Create a CaesarCipher using this position as a key
        CaesarCipher cc{size_t(value)};

        // Insert a std::pair of the letter and CaesarCipher into the lookup
        charLookup_.insert(std::make_pair(elem, cc));
    }
}

std::string VigenereCipher::applyCipher(const std::string& inputText, \
const CipherMode cipherMode) const
{
    size_t keyLen{key_.length()};
    std::string outputText{""};

    // For each letter in input:
    for (std::size_t i{0}; i < inputText.size(); i++) {
        // Find the corresponding letter in the key, repeating/truncating as required
        size_t pos = i % keyLen;

        // Find the Caesar cipher from the lookup
        auto newCipher = charLookup_.at(key_[pos]);

        // Run the (de)encryption
        //The cipher only takes and returns strings, so we must do some conversions
        std::string input{inputText[i]};
        std::string newChar {newCipher.applyCipher(input, cipherMode)};

        // Add the result to the output
        outputText = outputText + newChar;
    }
    return outputText;
}