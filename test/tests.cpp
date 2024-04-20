// Copyright 2024 Korshunov Yuriy
#include <gtest/gtest.h>
#include "../include/textgen.h"

TEST(test1, PrefixFormation) {
    Generator generator;
    generator.Train("the quick brown", 2);
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
    std::string gen = generator.Generate(100, 10);
    EXPECT_EQ(gen, "brown fox jumps over the lazy dog ");
}

TEST(test4, MultiplySuffixSelection) {
    Generator generator;
    generator.Train("the quick brown fox quick jumps over the lazy dog", 2);
    Prefix prefix = {"quick"};
    std::vector<std::string> suffix = { "brown", "jumps" };
    EXPECT_EQ(suffix, genreator.getChain().at(prefix));
}


TEST(test5, TextFormation) {
    Generator generator;
    std::map<prefix, std::vector<std::string> > map = {
        { { "the" }, { "quick", "brown" } },
        { { "fox" }, { "quick" } }
    };
    generator.setChain(map);
    std::string res = generator.Generate(10, 20);
    EXPECT_EQ("fox quick ", res);
}
