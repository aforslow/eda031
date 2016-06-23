#include <iostream>
#include <fstream>

int main(){
       	ifstream inFile("inFile.txt");
        ofstream outFile("file.enc");
	unsigned char c;
	if (!inFile && !outFile){
		while (inFile.get(c)) {
	            outFile << Coding::encode(c);
		    }
        } else{
	        cerr << "Could not find one or both files";
	}
}
