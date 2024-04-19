// Copyright 2024 Korshunov Yuriy
#include <gtest/gtest.h>
#include "../include/textgen.h"

class MarkovChainTest : public ::testing::Test {
 protected:
    void SetUp() override {
        generator.Train("the quick brown fox jumps over the lazy dog", 2);
    }

    Generator generator;
};

TEST(MarkovChainTest, PrefixFormation) {
    Generator generator;
    Prefix prefix = {"the", "quick"};
    EXPECT_EQ(generator.getChain()->first, prefix);
}

TEST(MarkovChainTest, CheckSuffix) {
    Generator generator;
    Prefix prefix = {"the", "quick"};
    EXPECT_EQ(generator.getChain().at(prefix)[0], "brown");
}

TEST(MarkovChainTest, SingleSuffixSelection) {
    Generator generator;
    std::string gen = generator.Generate(100);
    EXPECT_EQ(gen, "brown fox jumps over the lazy dog");
}

TEST(MarkovChainTest, MultiplySuffixSelection) {
    Generator generator2;
    generator2.Train("the quick brown fox quick jumps over the lazy dog", 2);
    std::string gen = generator2.Generate(100);
    EXPECT_EQ(gen, "brown fox jumps over the lazy dog");
}
