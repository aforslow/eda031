#include <iostream>
#include <iomanip> // for setw and setfill
#include "date.h"
//#include <cctype>
//#include <string>
//#include "date.cc"

using namespace std;

/*
 * Prints the date d in the format yyyy-mm-dd. You shall replace this
 * function with an overloaded operator<<, and add an overloaded operator>>.
 *
 */
void print(const Date& d) {
	cout << setw(4) << setfill('0') << d.getYear() << '-';
	cout << setw(2) << setfill('0') << d.getMonth() << '-';
	cout << setw(2) << setfill('0') << d.getDay();
}

/*
ostream& operator<<(ostream& out, const Date &d) {
    if (!out.good()) {
        return out;
    }
    //out << d.getYear() << d.getMonth() << d.getDay(); //d.getDay() << d.getMonth() << d.getYear();
    out << setw(4) << setfill('0') << d.getYear() << '-';
     out << setw(2) << setfill('0') << d.getMonth() << '-';
     out << setw(2) << setfill('0') << d.getDay();
    return out;
}
*/
/*
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
*/
int main() {
	// Check input and output of dates. Uncomment the following when you
	// have added operator>> and operator<<.
	
	bool cont = true;
	while (cont) {
		cout << "Type a date: ";
		Date aDate;
		cin >> aDate;
		if (cin.eof()) {
			cont = false;
		} else if (!cin.good()) {
			cout << "Wrong input format" << endl;
			// restore stream state and ignore the rest of the line
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else {
			cout << "Output: " << aDate << endl;
		}
	}
	
	
	// Check 'next' by creating an object describing today's date, then
	// printing dates more than a month ahead
	cout << "--- Today and more than a month ahead:" << endl;
	Date d1;
	print(d1);
	cout << endl;
	for (int i = 1; i <= 35 ; ++i) {
		d1.next();
		print(d1);
		cout << endl;
	}
	
	// Check so 'next' functions correctly from one year to the next
	cout << "--- New Year's Eve and the next day:" << endl;
	Date d2(2013, 12, 31);
	print(d2);
	cout << endl;
	d2.next();
	print(d2);
	cout << endl;
}
