


class Tour {
	public:
		Tour(Map map);
		void create_random_tour();
		void draw(Window w);
		double get_length();
	private:
		vector<size_t> visits;
		size_t n;
		Map this_map;
};

Tour::Tour(Map map) {
	n = map.size();
	this_map = map;
}


void Tour::create_random_tour() {
	default_random_engine e;
	vector<size_t> temp;
	for (int i = 0; i != n; ++i) {
		temp.push_back(i);
	}
	for (int i = 0; i != n; ++i) {
		distributed_int_values<unsigned> u(0, n-1-i);
		auto randval = u(e);
		visits.push_back(temp(randval));
		temp.erase(randval, 1);
	}
}


void Tour::draw(Window w) {
	for (int i = 0; i != visits.size() - 1; ++i) {
		auto coord1 = map.get_coords(size_t visits[i]);
		auto coord2 = map.get_coords(size_t visits[i+1]);
		int x1 = coord1.first();
		int y1 = coord1.second();
		int x2 = coord2.first();
		int y2 = coord2.second();
		w.line(x1, y1, x2, y2);
	}
}

void Tour::nearest_neighbour(int start) {
	


}


double Tour::get_length() {
	double total_dist = 0;
	for (size_t i = 0; i < n-1; ++n) {
		total_dist += map.get_dist(visits[i], visits[i+1]);
	}
	return total_dist;
}




