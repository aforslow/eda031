#include <iostream>
#include "tagremover.cc"
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
	string indata;
	ifstream inFile("test.html");
	Tagremover tr(inFile); 	//read from cin
	tr.print(cout);		//print on cout
}

