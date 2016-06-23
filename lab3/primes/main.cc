#include <iostream>
#include "primes.cc"
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
	Primes primes;
	primes.print_largest_pnum(100000);
	primes.print_sequence(200);
}
