
class Iterator {
	public:
		Iterator(const String& s, size_t p);
		bool operator!=(const Iterator& it);
		std::string operator*();
		Iterator& operator++();
	private:
		const String& my_s;
		size_t pos;
		void skip();

class String {
	public:
		typedef Iterator word_iterator;
		Iterator wi_begin() const {return Iterator(*this, 0);}
		Iterator wi_end() const {return Iterator(*this, n);}
	private:
		char* chars;
		size_t n;
};

Iterator::Iterator(const String& s, size_t p) : my_s(s), pos(p) {
	skip();
}

bool Iterator::operator!=(const Iterator& it){
	return ((my_s != it.my_s) || (pos != it.pos));
}

std::string Iterator::operator*(){
	std::string str;
	while (pos < my_s.n && my_s.chars[pos] != ' '){
		str += my_s.chars[pos];
	++pos;
	}
}

Iterator& Iterator::operator++(){
	skip();
	return *this;
}

void Iterator::skip(){
	while (pos < my_s.n && my_s.chars[pos] == ' '){
		++pos;
	}
}



