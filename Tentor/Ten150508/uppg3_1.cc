

// Header
//

class BI {
	friend std::ostream& operator<<(std::ostream& os, const BI& b);
	public:
		BI(int i = 0);
		BI(std::string str);
		BI& operator+=(BI b);
		BI& operator+(std::string str);
	private:
		vector<unsigned char> number;
};

std::ostream operator<<(std::ostream& os, const BI& b);
std::istream operator>>(std::istream is, BI& b);
