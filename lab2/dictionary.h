#ifndef DICTIONARY_H
#define DICTIONARY_H

//
//  dict.hpp
//  dictionary2
//
//  Created by Andreas Forslöw on 07/02/16.
//  Copyright © 2016 Andreas Forslöw. All rights reserved.
//

#include <string>
#include <vector>
#include "word.cc"
#include <unordered_set>
#include <iostream>


class Dictionary {
public:
    Dictionary();
    int nTrigrams(const std::string& str) const;
    std::vector<std::string> triagram(const std::string& str) const;
    bool contains(const std::string& word) const;
    void add_trigram_suggestions(std::vector<std::string>& suggestions, const std::string& word) const;
    void rank_suggestions(std::vector<std::string>& suggestions,const std::string& word) const;
    std::vector<std::string> get_suggestions(const std::string& word) const;
    void trim_suggestions(std::vector<std::string>& suggestions) const;

private:
    unordered_set<std::string> wordset;
    std::vector<Word> words[26]; // words[i] = the words with i letters,
    // ignore words longer than 25 letters
};

#endif
