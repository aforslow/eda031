class IntSet {
	public:
		IntSet(); // create empty set
		bool contains(int nbr) const; // true if nbr is in the set
		void insert(int nbr); // insert a number
	private:
		template<typename T>
		std::set<T> our_set;
};

IntSet::IntSet(){
	std::set<int> int_set;
	our_set& = int_set;
}

bool IntSet::contains(int nbr) const {
	return our_set.contains(nbr);
}

void IntSet::insert(int nbr){
	our_set.insert(nbr);
}

