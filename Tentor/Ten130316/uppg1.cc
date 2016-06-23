

vector<int> vec;

bool isOdd(const vector<int>& vec){
	return is_partitioned(vec.begin(), vec.end(), 
			[] (int i) { return (i % 2) != 0;});
}

	
template <typename InputIt, typename UnaryPredicate>
bool is_partitioned(InputIt first, InputIt last, UnaryPredicate p){
	// Returns true if all elements in the range [first, last) 
	// that satisfy
	// // the predicate p appear before all elements that don’t. 
	// Also returns true
	// if [first, last) is empty. The time complexity is linear.
	
	if (first == last) return true;

	auto *pointer = first;
	bool broken = false;
	while (pointer != last) {
		auto val = *pointer;
		if (!p(val)){
			broken = true;
		} 
		if (p(val) && broken){
			return false;
		}
		++pointer;
	}

	return true;
}
