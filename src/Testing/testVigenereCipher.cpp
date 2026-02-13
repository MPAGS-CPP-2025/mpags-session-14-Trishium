//! Unit Tests for MPAGSCipher VigenereCipher Class
#include "gtest/gtest.h"

#include "VigenereCipher.hpp"
#include "CaesarCipher.hpp"

TEST(VigenereCipher, Encrypt)
{
    VigenereCipher cc{""};
    EXPECT_EQ(cc.applyCipher("HELLOWORLD", CipherMode::Encrypt), "RIJVSUYVJN");
}

TEST(VigenereCipher, Decrypt)
{
    VigenereCipher cc{""};
    EXPECT_EQ(cc.applyCipher("RIJVSUYVJN", CipherMode::Decrypt), "HELLOWORLD");
}

TEST(VigenereCipher, Identity)
{
    VigenereCipher cc{"a"};
    EXPECT_EQ(cc.applyCipher("HELLOWORLD", CipherMode::Encrypt), "HELLOWORLD");
}

TEST(VigenereCipher, Caesar)
{
    VigenereCipher vc{"f"};
    CaesarCipher cc{5};
    EXPECT_EQ(vc.applyCipher("HELLOWORLD", CipherMode::Encrypt), cc.applyCipher("HELLOWORLD", CipherMode::Encrypt));
}
