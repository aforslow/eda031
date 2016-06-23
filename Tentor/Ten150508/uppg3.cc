#include <iostream>

class BI {
	friend std::ostream& operator<<(std::ostream& os, const BI& b);
	public:
		BI(unsigned int nbr = 0);
		BI(const std::string& str);
		BI& operator+=(const BI& rhs);
		//operator+=(BI bi2);
		//operator+(BI bi2);
		//operator<<(ostream& out);
		//operator>>(istream& in);
		//operator=(BI bi2);
	private:
		using digit_type = unsigned char;
		vector<digit_type> num_vec;
};

std::istream& operator>>(std::istream& is, BI& b);
std::ostream& operator<<(std::ostream& os, const BI& b);

BI operator+(const BI& lhs, const BI& rhs);

using namespace std;
BI(unsigned int nbr = 0){
	num_vec.}

BI(string str){

