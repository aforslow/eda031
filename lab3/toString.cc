#include <iostream>
//#include <string>
#include "date.h"
#include <sstream>
#include <iomanip>
#include <cctype>


using namespace std;

/*
ostream& operator<<(ostream& out, const Date &d) {
    if (!out.good()) {
        return out;
    }
    out << setw(4) << setfill('0') << d.getYear() << '-';
    out << setw(2) << setfill('0') << d.getMonth() << '-';
    out << setw(2) << setfill('0') << d.getDay();
    return out;
}
*/
template <typename T>
string toString(T const& nbr){
	stringstream out;
	out << nbr;
	return out.str();
}


template <typename To> To string_cast(string str){
    To type;
    stringstream convert(str);
    
    if (!(convert >> type)) {
        throw std::invalid_argument("Could not convert string to type!");
    }
    
    return type;
}

int main() {
	double d = 1.234;
	Date today;
	std::string sd = toString(d);
    cout << sd << endl;
	std::string st = toString(today);
    cout << st << endl << endl;
    
    try {
        int i = string_cast<int>("123");
        double d = string_cast<double>("12.34");
        Date date = string_cast<Date>("2015-13-10");
        cout << i + 2 << endl;
        cout << d + 2.32 << endl;
        cout << date << endl;
    } catch (std::invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
}

