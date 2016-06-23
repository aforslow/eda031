


string curses(string str) {
	string letters = "aeriouyåäöAEIOUYÅÄÖ";
	string sym = "@$!*#&%";
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0,sym.size()-1);
	for_each(str.begin(), str.end(), [](char& c) {
			for (char e : letters) {
				if (e == c) {
					c = sym(u(e));
				}
			}
		});
}





	auto it = remove_if(str.begin(), str.end(),
			[](char c) {
			for (auto e : letters) {
				if (c == e) {
					return true;
				}
			}
			return false;
			});
	str.erase(it, str.end());

