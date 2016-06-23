

int operator=(int nbr) {*curr = nbr;}

b

template<typename T>
class Ptr {
	public:
		Ptr<T>(T* p) : curr(p) {}
		T operator*() const { return *curr; }
		T operator=(T e) { *curr = e; }
		T operator+(int nbr) { curr += nbr; }
		T operator++() { ++curr; }
	private:
		T* curr;
};
