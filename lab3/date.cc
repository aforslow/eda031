#include <ctime>  // time and localtime
#include "date.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
    if(!setDate(y, m, d)){
        throw std::invalid_argument("Invalid date");
    }
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

ostream& operator<<(ostream& out, const Date &d) {
   //if (!out.good()) {
   //     return out;
   // }
    out << setw(4) << setfill('0') << d.getYear() << '-';
    out << setw(2) << setfill('0') << d.getMonth() << '-';
    out << setw(2) << setfill('0') << d.getDay();
    return out;
}

bool InputMatches(string strUserInput, string strTemplate)
{
    if (strTemplate.length() != strUserInput.length())
        return false;
    
    // Step through the user input to see if it matches
    for (unsigned int nIndex=0; nIndex < strTemplate.length(); nIndex++)
    {
        switch (strTemplate[nIndex])
        {
            case '#': // match a digit
                if (!isdigit(strUserInput[nIndex]))
                    return false;
                break;
            case '_': // match a whitespace
                if (!isspace(strUserInput[nIndex]))
                    return false;
                break;
            case '@': // match a letter
                if (!isalpha(strUserInput[nIndex]))
                    return false;
                break;
            case '?': // match anything
                break;
            default: // match the exact character
                if (strUserInput[nIndex] != strTemplate[nIndex])
                    return false;
        }
    }
    
    return true;
}

istream& operator>>(istream& is, Date &date) {
    string year, month, day, input;
    getline(is, input);
    int y, m, d;
    if (InputMatches(input, "####-##-##")) {
        year = input.substr(0, input.find('-'));
        input.erase(0, input.find('-')+1);
        month = input.substr(0, input.find('-'));
        input.erase(0, input.find('-')+1);
        day = input;
        y = stoi(year), m = stoi(month), d = stoi(day);
        if (!date.setDate(y, m, d)){
            is.setstate(ios_base::failbit);
        }
    } else {
        is.setstate(ios_base::failbit);
    }
    return is;
}

/*
istream& operator>>(istream& is, Date &date) {
    char sign1, sign2;
    int year, month, day;
    is >> year >> sign1 >> month >> sign2 >> day;
    if (!date.setDate(year, month, day)) {
        is.setstate(ios_base::failbit);
    }
}
*/

bool Date::setDate(int y, int m, int d){
    if (m < 1 || m > 12 || d > daysPerMonth[m-1] || d < 1){
        return false;
    }
    
    year = y, month = m, day = d;
    return true;
}

void Date::next() {
	if (day + 1 > daysPerMonth[month-1]){
		day = 1;
		year = (month < 12 ? year : year + 1);
		month = (month < 12 ? month + 1 : 1);
	} else {
		day += 1;
	}
}
		





