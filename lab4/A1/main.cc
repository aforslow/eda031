#include <iostream>
#include "VNS.h"
#include "MNS.h"
#include "HNS.h"
#include "UMNS.h"

using namespace std;

int main() {
    cout << "Testing vns: " << endl;
    VNS vns;
    vns.insert("hej", 3);
    vns.insert("lalala", 4);
    cout << "insert successful!" << endl;
    vns.remove("hej");
    vns.remove("finns inte");
    cout << "Remove successful" << endl;
    cout << "IPAddress: " << vns.lookup("lalala") << endl;
    cout << "lookup successful!" << endl;
    
    cout << endl << "Testing MNS: " << endl;
    MNS mns;
    mns.insert("mns insert", 1);
    mns.insert("mns insert 2", 2);
    cout << "Insert successful!" << endl;
    mns.remove("mns insert");
    mns.remove("finns ej");
    cout << "remove successful!" << endl;
    cout << "IPAddress: " << mns.lookup("mns insert 2") << endl;
    
    cout << endl << "Testing UMNS: " << endl;
    UMNS umns;
    umns.insert("Umns insert", 1);
    umns.insert("Umns insert 2", 2);
    cout << "Insert successful!" << endl;
    umns.remove("Umns insert");
    umns.remove("finns ej");
    cout << "remove successful!" << endl;
    cout << "IPAddress: " << umns.lookup("Umns insert 2") << endl;
    
    cout << endl << "Testing HNS: " << endl;
    HNS hns(3);
    hns.insert("hns insert", 1);
    hns.insert("hns insert 2", 2);
    cout << "Insert successful!" << endl;
    hns.remove("mns insert");
    hns.remove("finns ej");
    cout << "remove successful!" << endl;
    cout << "IPAddress: " << hns.lookup("mns insert 2") << endl;
    
}

