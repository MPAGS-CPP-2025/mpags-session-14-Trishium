#include "VigenereCipher.hpp"
#include "Alphabet.hpp"

#include <iostream>
#include <string>
#include <algorithm>

/**
 * \file VigenereCipher.cpp
 * \brief Contains the implementation of the VigenereCipher class
 */

VigenereCipher::VigenereCipher(const std::string& key)
{
    // We have the key as a string, but the Vigenere cipher needs an unsigned long, so we first need to convert it
    // We default to having a key of 0, i.e. no encryption, if no (valid) key was provided on the command line
    this->setKey(key);
}

void VigenereCipher::setKey(const std::string& key){
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
    if (key_ == ""){
        key_ = "KEY";
    }
    // loop over the key
    for ( auto &k : key_){
        for (std::size_t i{0}; i < Alphabet::size; ++i) {
            if (k == Alphabet::alphabet[i]){
                CaesarCipher cipher{i};
                charLookup_.insert(std::make_pair(k, cipher));
            }
        }
     }
    // Find the letter position in the alphabet
    // Create a CaesarCipher using this position as a key
    // Insert a std::pair of the letter and CaesarCipher into the lookup
}

std::string VigenereCipher::applyCipher(const std::string& inputText,
                                      const CipherMode cipherMode) const
{   std::string outputText{""};
    // For each letter in input:
    for (uint i{0}; i < inputText.size(); i++){
        char key_letter{key_[i%key_.size()]};
        CaesarCipher cipher{charLookup_.at(key_letter)};
        std::string output_letter = cipher.applyCipher(std::string{inputText[i]}, cipherMode);
        outputText += output_letter;
    }
    // Find the corresponding letter in the key,
    // repeating/truncating as required
    // Find the Caesar cipher from the lookup
    // Run the (de)encryption
    // Add the result to the output
    return outputText;
}
