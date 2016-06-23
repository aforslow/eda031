


class Map {
	public:
		Map(size_t n);
		Map(const string& file_name);
		size_t size() const;
		pair<double, double> get_coords(size_t i) const;
		double get_dist(size_t i, size_t j) const;
	private:
		size_t n_cities;
		vector<pair<double, double> > coords;
		vector<vector<double> > dist(n_cities, vector<double>(n_cities));
		void calc_dist();
};

Map::Map(size_t n) {
	n_cities = n;
	uniform_real_distribution<double> u(0,1);
	default_random_engine e;

	for (size_t i = 0; i != n; ++i) {
		coords.push_back(make_pair(u(e), u(e)));
	}
}

Map::Map(const string& file_name) {
	ifstream inFile(file_name);
	char line;
	double c1, c2;

	while (getline(inFile, line)) {
		line >> c1 >> c2;
		coords.push_back(make_pair(c1, c2));
	}
	n_cities = coords.size();
}

size_t Map::size() const {
	return n_cities;
}

pair<double, double> Map::get_coords(size_t i) const {
	return coords[i];
}

double Map::get_dist(size_t i, size_t j) {
	if (dist.isEmpty()) {
		calc_dist();
	}
	return dist[i][j];
}

void Map::calc_dist() {
	for (size_t i = 0; i != n; ++i) {
		for (size_t j = 0; j != n; ++j) {
			double this_dist = &dist[i][j];
			auto coord1 = get_coords(i); //pair 1
			auto coord2 = get_coords(j); //pair 2
			double x1 = coord1.first();
			double y1 = coord1.second();
			double x2 = coord2.first();
			double y2 = coord2.second();
			this_dist = sqrt((x2-x1)^2 + (y2-y1)^2);
		}
	}
}






