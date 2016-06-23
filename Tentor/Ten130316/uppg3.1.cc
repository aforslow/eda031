class Iterator {
	public:
		Iterator(const String& s, size_t p);
		bool operator!=(const Iterator& it);
		Iterator& operator++();
		std::string operator*();
	private:
		void skip();
		const String& my_s;
		size_t pos;
}

class String {
	public:
		typename Iterator word_iterator;
		Iterator wi_begin() const { return Iterator(*this, 0);}
		Iterator wi_end() const { return Iterator(*this, n);}
	private:
		char* chars;
		size_t n;
}

Iterator::Iterator(const String& s, size_t p) : my_s(s), pos(p){
	skip();
}

bool operator!=(const Iterator& it){
	return (pos != it.pos || my_s != it.my_s);
}

Iterator& operator++(){
	skip();
	return *this;
}

std::string Iterator::operator*(){
	std::string str;
	while (pos < my_s.n && my_s.chars[pos] != ' '){
		str += my_s.chars[pos];
		++pos;
	}
	return str;
}

void Iterator::skip(){
	while (pos < my_s.n && my_s.chars[pos] == ' '){
		++pos;
	}
}
