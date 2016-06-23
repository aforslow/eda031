#include <iostream>
#include <string>

/* MorseCode.cc */

using namespace std;

class MorseCode {
	public:
		MorseCode();
		decode(const string& str);
	private:
		map<string, char> table;
};

MorseCode::MorseCode() {
	istream inFile("morse.def");
	char sym;
	string code;
	while (inFile >> sym >> code){
		table.insert(make_pair(sym, code));
	}
}

string MorseCode::decode(const string& code){
	istringstream iss(code);
	string s;
	string result;
	while (iss >> s) {
		auto it = table.find(s);
		result += (it != table.end()) it->second : '?';
	}
	return result;
}




