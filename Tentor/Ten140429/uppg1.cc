

int main() {
	map<string, set<size_t>, string::compare > regist;
	string word, line, text;
	size_t row = 0;
	while (getline(cin, line)) {
		++row;
		istringstream ben(line);
		while (ben >> word) {
			auto it = remove_if(word.begin(), word.end(),
					[](char x) {
					return !isalnum(word);
					});
			word.erase(it, word.end());
			regist.insert(word, row);			
		}	
	}
	for (auto key : regist) {
		cout << key.first << ' ';
		for (auto val : key.second) {
			cout << val << ' ';
		}
		cout << endl;
	}
}

