//
//  trigram.cpp
//  dictionary2
//
//  Created by Andreas Forslöw on 03/02/16.
//  Copyright © 2016 Andreas Forslöw. All rights reserved.
//

#include "trigram.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int trigram::nTrigrams(std::string str){
    if (str.size() < 3) {
        return 0;
    } else{
        return (int) str.size() - 2;
    }
}
    
    vector<string> trigram::triagram(std::string str){
    //create all the trigrams and put in a list
    vector<string> trigList;
    for (int i = 0; i < nTrigrams(str); i++){
        string data = str.substr(i, 3);
        transform(data.begin(), data.end(), data.begin(), ::tolower);
        trigList.push_back(data);
    }
    sort(trigList.begin(), trigList.end());
    return trigList;
}


