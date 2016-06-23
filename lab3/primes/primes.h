#ifndef PRIMES_H
#define PRIMES_H

#include <iostream>
#include <string>

class Primes {
	public:
		Primes(); //init string
		void mark_primes(const int& M); //marks pnums
		void print_sequence(const int& N); //print pnum sequence 
		void print_largest_pnum(const int& L); //print largest pnum
	private:
		std::string num_string;
};

#endif 
