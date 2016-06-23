//
//  trigram.hpp
//  dictionary2
//
//  Created by Andreas Forslöw on 03/02/16.
//  Copyright © 2016 Andreas Forslöw. All rights reserved.
//

#ifndef trigram_hpp
#define trigram_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

class trigram {
public:
    int nTrigrams(std::string str);
    
    std::vector<std::string> triagram(std::string str);
    //create all the trigrams and put in a list
        //change letter to lower case
        //include letter + next 2 letters in strvar
        //put strvar in list
    //compare first letter in every strvar
    //print each strvar in order in outFile unitl none exists
};

#endif /* trigram_hpp */
