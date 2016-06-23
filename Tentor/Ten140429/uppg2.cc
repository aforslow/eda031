

void Vector::vector_user(Vector& v) {
	Vector v1(10); //the constructor Vector(size_t n_max)
	Vector v2(v); //the constructor Vector(const Vector&);
	Vector v3(v);
	Vector v4 = v2; //the operator operator=(Vector);
	v4 += v3; //the operator operator+=(Vector);
	v4.size(); //the function size()
	v3[1] = v4[2]; //the operator operator[](size_t i) and operator=
	const size_t a = v4[3]; //the operator operator[](size_t i) const
	Vector v5 = v + v; //The operator operator+
}

b) Delete-funktion/ Dekonstruktor. Annars är det minnesläcka... 

c) Fknen får inte använda icke-konstanta variabler om objektet är konstant. 

	size_t size() const { return n; }

d) 

Vector& Vector::operator+=(Vector v1) {
	for (size_t i = 0; i != size(); ++i) {
		v[i] += v1[i];
	}
	return *this;
}

Vector operator+(Vector v1, Vector v2) {
	v1 += v2;
	return v1;
}

auto a = &v[i];
a = i;

int *b = *a;

