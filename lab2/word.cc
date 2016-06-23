//
//  word.cpp
//  dictionary2
//
//  Created by Andreas Forslöw on 07/02/16.
//  Copyright © 2016 Andreas Forslöw. All rights reserved.
//

//#include "word.hpp"
#include <string>
#include <vector>
#include <algorithm>
//#include "word.h"

using namespace std;

class Word {
private:
    string w1;
    vector<string> t1;
public:
    Word(const string& w, const vector<string>& t) : w1(w), t1(t){}
    
    //w1 = w;
    //t1 = t;
    //int strSize = (int) w.size() - 2;
    //for (int i = 0; i < strSize; i++){
    //    string data = w.substr(i, 3);
    //    transform(data.begin(), data.end(), data.begin(), ::tolower);
    //    t1.push_back(data);
    //}
    //sort(t1.begin(), t1.end());
    //w1 << t1.at(0);
    //for (int i = 1; i < t1.size(); i++) {
    //    string ch = t1.at(i);
    //    w1 << ch.at(2);
    //}
    
    string get_word() const {
        return w1;
    }
    
    unsigned int get_matches(const vector<string>& t) const {
        int matches = 0;
        
        for (string s : t1) {
            if (find(t.begin(), t.end(), s) != t.end()){
                matches++;
            }
        }
        return matches;
        
        
        
        //Om jfr >, i++, j=0
        //Om jfr <, j++
        //Om j > t.size, i++, j = 0
        //Om jfr == 0, nTrig++, i++, j=0
        /*
        while (i < t1.size()) {
            string wrd = t1.at(i);
            if (j > t.size()) {
                i++;
                j = 0;
            } else if (wrd.compare(t.at(j)) == 0) {
                nTrig++;
                i++;
                j = 0;
            } else if (wrd.compare(t.at(j)) > 0){
                i++;
                j = 0;
            } else if (wrd.compare(t.at(j)) < 0){
                j++;
            }
        }
        return nTrig;
         */
    }
    
};


















