//
//  dict.cpp
//  dictionary2
//
//  Created by Andreas Forslöw on 07/02/16.
//  Copyright © 2016 Andreas Forslöw. All rights reserved.
//

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
//#include "trigram.cpp"
//#include "word.h"
#include "dictionary.h"
#include <unordered_set>
#include <utility>

using namespace std;

unordered_set<string> wordset;
//vector<Word> words; // words[i] = the words with i letters,
// ignore words longer than 25 letters
//public:
Dictionary::Dictionary() {
    char word[256];
    ifstream inFile("words");
    if (!inFile) {
        cout << "Couldn't find file \n";
        exit(1);
    } else{
        while(inFile.getline(word, 256)){
            vector<string> t;
            string str = (string) word;
            Word new_word = Word(word, triagram(str));
            int wordLength = (int) str.size();
            
            wordset.insert(word);
            words[wordLength].push_back(new_word);
        }
    }
}

int Dictionary::nTrigrams(const std::string& str) const{
    if (str.size() < 3) {
        return 0;
    } else{
        return (int) str.size() - 2;
    }
}

vector<string> Dictionary::triagram(const std::string& str) const{
    vector<string> trigList;
    if (nTrigrams(str) > 0) {
        for (int i = 0; i < nTrigrams(str); i++){
            string data = str.substr(i, 3);
            transform(data.begin(), data.end(), data.begin(), ::tolower);
            trigList.push_back(data);
        }
        sort(trigList.begin(), trigList.end());
        return trigList;
    } else {
        trigList.push_back(str);
        return trigList;
    }
}

bool Dictionary::contains(const string& word) const {
    unordered_set<string>::const_iterator itr = wordset.find(word);
    
    if (itr == wordset.end()) {
        return false;
    } else {
        return true;
    }
}

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& word) const{
    int wordLength = (int) word.size();
    int leftBound = wordLength - 1;
    int rightBound = wordLength + 1;
    if (wordLength < 1) {
        leftBound = 0;
        rightBound = 1;
    } else if (wordLength > 24) {
        leftBound = 24;
        rightBound = 25;
    }
    
    for (int i = leftBound; i <= rightBound; i++) {
        vector<Word> thisWordCollection = words[i];
        for (Word w : words[i]){
            vector<string> t = triagram(word);
            unsigned int nTrig = w.get_matches(t);
            if (nTrig >= nTrigrams(word)/2) {
                suggestions.push_back(w.get_word());
            }
        }
    }
}

void Dictionary::rank_suggestions(vector<string>& suggestions, const string& word) const{
    int d[25][25];
    const size_t word_size =  word.size();
    vector<pair<int, string> > ranked_suggestions;
    
    for (int suggested_place = 0; suggested_place < suggestions.size();
		   suggested_place++) {
        const string& p = suggestions[suggested_place];
        const size_t p_size = p.size();
        d[0][0] = 0;

        for (unsigned int i = 1 ; i < word_size; i++) d[i][0] = i;
        for (unsigned int j = 1; j < p_size; j++) d[0][j] = j;
        
        for (unsigned int i = 1; i <= word_size; ++i) {
            for (unsigned int j = 1; j <= p_size; ++j) {
                d[i][j] = min({d[i-1][j] + 1, d[i][j-1] + 1,
                    d[i-1][j-1] + (p[i] == word[j] ? 0 : 1) });
            }
        }
        int dist = (int) d[word_size][p_size];
        ranked_suggestions.push_back(make_pair(dist, p));
    }
    
    using P = pair<int, string>;
    auto compare = [](P p1, P p2){return p1.first < p2.first; };
    sort(ranked_suggestions.begin(), ranked_suggestions.end(),
         compare);
    suggestions.clear();

    auto give_second = [](const pair<int, string>& p){ return p.second; };
    transform(ranked_suggestions.begin(),
              ranked_suggestions.end(),
              back_inserter(suggestions),
              give_second);
}

void Dictionary::trim_suggestions(vector<string>& suggestions) const{
    suggestions.resize(5);
}

vector<string> Dictionary::get_suggestions(const string& word) const {
    vector<string> suggestions;
    add_trigram_suggestions(suggestions, word);
    rank_suggestions(suggestions, word);
    trim_suggestions(suggestions);
    return suggestions;
}








