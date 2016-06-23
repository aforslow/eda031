


int main(){
	ifstream inFile("dict.txt");
	map<string, int> counts;
	multimap<string, string> words;
	string s;
	while (inFile >> s) {
		string temp = s;
		sort(temp.begin(), temp.end());
		++counts[temp];
		words.insert(make_pair(temp, s));
	}
	
	int max_count = -1;
	vector<string> max_strings;
	for (auto c : counts) {
		if (max_count < c.second){
			max_count = c.second;
			max_strings.clear();
			max_strings.push_back(c.first);
		} else if (max_count == c.second){
			max_strings.push_back(c.first);
		}
	}

	cout << "The largest anagram groups: " << endl;
	for (auto s : max_strings){
		auto range = words.equal_range(s);
		for (auto it = range.first; it != range.second; ++it){
			cout << it->second << ' ';
		}
		cout << endl;
	}
}
