

int main(argc[], argv) {
	ifstream inFile(argv + ".tex");
	string line, text;
	int section = 0;
	vector<string, int> label_list;
	while (getline(inFile, line)) {
		size_t section_pos = line.find("\section");
		size_t label_pos = line.find("\label");
		size_t ref_pos = line.find("\ref");

		if (section_pos != string::npos) {
			section += 1;
			size_t section_end_pos = line.find("{");
			line.replace(section_pos,
					section_end_pos - section_pos + 1, 
					to_string(section) + " ");
			line.erase(line.find("}"));
		} else if (label_pos != string::npos) {
			size_t label_start_pos = line.find("{") + 1;
			size_t label_end_pos = line.find("}");
			label_list.push_back(make_pair(line.substr(label_start_pos,
						label_end_pos - label_start_pos),
						section));
			line.erase(label_pos, label_end_pos - label_pos + 1);
		} else if (ref_pos != string::npos) {
			string ref;
			size_t ref_start_pos = line.find("{") + 1;
			size_t ref_end_pos = line.find("}");
			ref = line.substr(ref_start_pos,
					ref_end_pos - ref_start_pos);
			for (auto it = label_list.begin(), it != label_list.end(),
				       	++it) {
				if (it->first == ref) {
					line.replace(ref_pos,
							ref_end_pos - ref_pos + 1,
							to_string(it->second));
					break;
				}
			}
			if (it == label_list.end()) {
				line.replace(ref_pos, ref_end_pos - ref_pos + 1,
						"??");
			}
		}
		text += line + "\n";
	}
}
