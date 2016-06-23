#include <iostream>
#include "VNS.h"

using namespace std;


void VNS::insert(const HostName& host, const IPAddress& ip){
    vector_server.push_back(make_pair(host, ip));
}

bool VNS::remove(const HostName& host){
    auto itr = find_if(vector_server.begin(),vector_server.end(),
                       [host](const pair<HostName, IPAddress> &s) {return host == s.first;});

    if (itr != vector_server.end()) {
	vector_server.erase(itr);
	return true;
    } else {
	    return false;
    }
}

IPAddress VNS::lookup(const HostName& host) const{
    auto itr = find_if(vector_server.begin(), vector_server.end(),
                       [host](const pair<HostName, IPAddress> &s) {return host == s.first;});
    if (itr != vector_server.end()) {
	    return itr->second;
    } else {
	    return NON_EXISTING_ADDRESS;
    }
}



/*
using namespace std;
class VNS {
	private:
		vector<pair<string, string>> name_address;
	public:
		string find_host(string name){
            return find_if(name_address.begin(),name_address.end(), [name](pair<string, string> s) {return name == s.first;}) !=name_address.end();
        }
}
*/
