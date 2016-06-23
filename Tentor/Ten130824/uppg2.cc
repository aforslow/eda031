

class Accumulator {
	public:
		Accumulator();
		void undo();
		void commit();
		void rollback();
		void operator+=(Accumulator accum);
		int get_sum();	
	private:
		int sum;
		vector<int> changes;
};

Accumulator::Accumulator(){ sum = 0; }

void Accumulator::undo(){
	auto it = changes.end();
	auto it2 = changes.begin();
	if (it != it2){
		--it;
		sum -= *it;
	}
}

void Accumulator::commit(){
	changes.clear();
}

void Accumulator::rollback(){
	int rollback_sum = 0;
	for (auto it = changes.begin(); it != changes.end(); ++it){
		rollback_sum += *it;
	}
	sum -= rollback_sum;
	changes.clear();
}

void Accumulator::operator+=(int nbr){
	sum += nbr;
	changes.push_back(nbr);
}

int Accumulator::get_sum(){ return sum; }

ostream& operator<<(ostream& os, const Accumulator& accum) {
	os << accum.get_sum();
	return os;
}
