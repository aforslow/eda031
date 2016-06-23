class IntSet {
	friend std::ostream& IntSet(std::ostream& os, const IntSet is);
	public:
		IntSet(); // create empty set
		bool contains(int nbr) const; // true if nbr is in the set
		void insert(int nbr); // insert a number
	private:
		class Element(int minval, int maxval){
			int min = minval;
			int max = maxval;
		}
		std::list<Element> int_set;
		std::list<Elemennt>::iterator it, it2;
};

IntSet::IntSet(){
	Element first(numeric_limits<int>::min(),
			numeric_limits<int>::min());
	Element last(numeric_limits<int>::max(), 
			numeric_limits<int>::max());
	int_set.push_back(first);
	int_set.push_back(last);
}

bool IntSet::contains(int nbr) const {
	for (it = int_set.begin(); it != int_set.end(); ++it){
		if (nbr >= it->min && nbr <= it->max){
			return true;
		}
	}
	return false;
}

void IntSet::insert(int nbr){
	if (contains(nbr)) {
		//Do nothing
	} else {
		for (it = int_set.begin(); it!= int_set.end(); ++it){
			//Unite elements
			if (it < int_set.end() - 1){
				it2 = it + 1;
			}
			if ((it->max + 1 == nbr) && (it2->min - 1 == nbr)){
				it->max = it2->max;
				int_set.erase(it2);
			} else if(it->max + 1 == nbr){
				it->max = nbr;
			} else if(it2->min - 1 == nbr) {
				it2->min = nbr;
			} else if(it->min > nbr) {
				Element e(nbr, nbr);
				int_set.insert(it, e);
			}
		}
	}
}

ostream& IntSet::operator<<(ostream& os, const IntSet is){
	for_each(is.int_set.begin(), is.int_set.end(), [](Element e){
			if (e->min != numeric_limits<int>::min() &&
				e->max != numeric_limits<int>::max()){
				int val = e->min;
				while (val <= e->max) {
					os << val << ' ';
					++val;
				}
			}
	})
	return os;
}



