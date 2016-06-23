#include <iostream>
#include "MNS.h"

using namespace std;
void MNS::insert(const HostName& host, const IPAddress& ip){
	map_server[host] = ip;	
}

bool MNS::remove(const HostName& host){
	//auto itr = find_if(map_server.begin(), map_server.end(),
    //                   [host](const map<HostName,IPAddress> &s){return host == s[]});
    auto itr = map_server.find(host);
    if (itr != map_server.end()){
		map_server.erase(itr);
		return true;
	} else {
		return false;
	}
}

IPAddress MNS::lookup(const HostName& host) const{
	auto itr = map_server.find(host);
	if (itr != map_server.end()) {
		return itr->second;
	} else {
		return NON_EXISTING_ADDRESS;
	}
}
