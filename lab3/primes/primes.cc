#include "primes.h"
#include <iostream>

using namespace std;

Primes::Primes(){
	num_string = "";
}


void Primes::mark_primes(const int& M){
	char c = 'P';
	string str(M+1,c);
	num_string = str;
	
	for (int i=0; i <= M; i++) {
		if (i == 0 || i == 1) {
			num_string[i] = 'C';
		} else if (num_string[i]=='P'){
		       int j = 2*i;
		       while (j <= M) {
			       num_string[j] = 'C';
			       j += i;
		       }
		}
	}
}

void Primes::print_sequence(const int& N){
	if (num_string.size() < N) mark_primes(N);

	cout << "The prime numbers between 0 and " << N << " are: " << endl;
	for (int i=0; i <= N; i++){
		if (num_string[i] == 'P') cout << i << ' ';
	}
	cout << endl;
}

void Primes::print_largest_pnum(const int& L) {
	if (num_string.size() != L + 1) mark_primes(L);
	int last_prime = num_string.rfind('P');
	cout << "The largest prime number smaller than " <<
		L << " is: " << endl;
	cout << last_prime << endl << endl;
}

