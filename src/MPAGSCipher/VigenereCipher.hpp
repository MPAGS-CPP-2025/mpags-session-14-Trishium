#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

#include "CipherMode.hpp"
#include "CaesarCipher.hpp"

#include <cstddef>
#include <string>
#include <vector>
#include <map>

/**
 * \file VigenereCipher.hpp
 * \brief Contains the declaration of the VigenereCipher class
 */

/**
 * \class VigenereCipher
 * \brief Encrypt or decrypt text using the Vigenere cipher with the given key
 */
class VigenereCipher {
  public:
    

    /**
     * \brief Create a new VigenereCipher, 
     *
     * \param key The string to use as the key to be used in the cipher
     */
    explicit VigenereCipher(const std::string& key);

    /**
     * \brief Set the key to be used for the encryption/decryption
     *
     * \param key the key to use in the cipher
     */
    void setKey(const std::string& key);

    /**
     * \brief Apply the cipher to the provided text
     *
     * \param inputText The text to encrypt or decrypt
     * \param cipherMode Whether to encrypt or decrypt the input text
     * \return The result of applying the cipher to the input text
     */
    std::string applyCipher(const std::string& inputText,
                            const CipherMode cipherMode) const;

  private:
    /// The cipher key, essentially a constant shift to be applied
    std::string key_{""};

    /// Lookup table
    std::map<char,CaesarCipher> charLookup_;
};

#endif
