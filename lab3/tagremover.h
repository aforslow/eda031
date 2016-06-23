#ifndef TAGREMOVER_H
#define TAGREMOVER_H

#include <iostream>
#include <fstream>
#include <regex>

class Tagremover {
	public:
		Tagremover(std::istream& stream);
		void print(std::ostream& out);
		
	private:
		std::string str;
};

#endif
