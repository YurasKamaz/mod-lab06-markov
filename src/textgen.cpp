// Copyright 2024 Korshunov Yuriy

#include "../include/textgen.h"

void Generator::Train(const std::string& text, int prefixSize) {
    std::istringstream iss(text);
    Prefix prefix;
    std::string word;
    for (int i = 0; i < prefixSize; i++) {
        iss >> word;
        prefix.push_back(word);
    }
    while (iss >> word) {
        chain[prefix].push_back(word);
        prefix.pop_front();
        prefix.push_back(word);
    }
}

std::string Generator::Generate(int length) {
    srand(time(0));

    int index = rand_r() % chain.size();
    auto it = chain.begin();
    std::advance(it, index);
    Prefix prefix = it->first;

    std::string result;
    for (int i = 0; i < length; i++) {
        std::vector<std::string> suffix = chain[prefix];
        if (suffix.empty()) break;
        int next_index = rand_r() % suffix.size();
        std::string next = suffix[next_index];
        result += next + " ";
        prefix.pop_front();
        prefix.push_back(next);
    }
    return result;
}

std::map<Prefix, std::vector<std::string>> Generator::getChain() {
    return chain;
}
