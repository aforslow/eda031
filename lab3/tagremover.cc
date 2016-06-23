
#include <iostream>
#include "tagremover.h"
#include <string>
#include <regex>

using namespace std;

Tagremover::Tagremover(istream& stream) {
    
    string line, temporary;
        while (getline(stream, line)) {
            str += line + "\n";
        }
    
    size_t lt, rt, nl;
    while (str.find("<") != string::npos) {
        lt = str.find("<");
        rt = str.find(">");
        temporary = str.substr(lt, rt-lt+2);
        nl = temporary.find("\n");
        if (nl != string::npos) {
            str.replace(lt, rt-lt+2, "\n");
        } else {
            str.erase(lt, rt-lt + 2);
        }
    }
    while (str.find("&lt;") != string::npos) {
        str.replace(str.find("&lt;"), 4, "<");
    }
    while (str.find("&gt;") != string::npos) {
        str.replace(str.find("&gt;"), 4, ">");
    }
    while (str.find("&nbsp;") != string::npos) {
        str.replace(str.find("&nbsp;"), 6, " ");
    }
    while (str.find("&amp;") != string::npos) {
        str.replace(str.find("&amp;"), 5, "&");
    }
    /*
        bool inTag = false;
        string line;
		while (getline(stream, line)){
            size_t lt = line.find("<");
            size_t rt = line.find(">");
            string new_line = "\n";
            
            if (lt == string::npos && rt == string::npos && inTag == true) {
                line.erase(0, line.size());
                new_line = "";
            } else {
                while (lt != string::npos || rt != string::npos) {
                    if (lt!= string::npos && rt != string::npos) {
                        if (lt < rt){
                            line.erase(lt, rt-lt + 2);
                        } else{
                            line.erase(0, rt + 1);
                            inTag = false;
                        }
                    } else if (lt != string::npos && rt == string::npos) {
                        inTag = true;
                        line.erase(lt, line.size());
                    } else if (lt == string::npos && rt != string::npos) {
                        line.erase(0,rt+1);
                        inTag = false;
                    }
                    lt = line.find("<");
                    rt = line.find(">");
                }
            }

            
            if (line.find("&lt") != string::npos) line.replace(line.find("&lt"), 3, "<");
            if (line.find("&gt") != string::npos) line.replace(line.find("&gt"), 3, ">");
            if (line.find("&nbsp") != string::npos) line.replace(line.find("&nbsp"), 5, " ");
            if (line.find("&amp") != string::npos) line.replace(line.find("&amp"), 4, "&");
            str.append(line + new_line);
            
            
		}
         */
    //}
}
void Tagremover::print(ostream& out) {
	out << str << endl;
}
