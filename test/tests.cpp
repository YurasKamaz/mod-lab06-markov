// Copyright 2024 Korshunov Yuriy
#include <gtest/gtest.h>
#include "../include/textgen.h"

TEST(test1, PrefixFormation) {
    Generator generator;
    generator.Train("the quick brown fox jumps over the lazy dog", 2);
    Prefix prefix = {"the", "quick"};
    std::map<Prefix, std::vector<std::string>> ch = generator.getChain();
    EXPECT_EQ(ch.begin()->first, prefix);
}

TEST(test2, CheckSuffix) {
    Generator generator;
    generator.Train("the quick brown fox jumps over the lazy dog", 2);
    Prefix prefix = {"the", "quick"};
    EXPECT_EQ(generator.getChain().at(prefix)[0], "brown");
}

TEST(test3, SingleSuffixSelection) {
    Generator generator;
    generator.Train("the quick brown fox jumps over the lazy dog", 2);
    std::string gen = generator.Generate(100);
    EXPECT_EQ(gen, "brown fox jumps over the lazy dog ");
}

TEST(test4, MultiplySuffixSelection) {
    Generator generator;
    generator.Train("the quick brown fox quick jumps over the lazy dog", 2);
    std::string gen = generator.Generate(100);
    EXPECT_EQ(gen, "brown fox jumps over the lazy dog");
}
