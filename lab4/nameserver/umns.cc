#include "UMNS.h"
#include <iostream>

using namespace std;

void UMNS::insert(const HostName& host, const IPAddress& ip){
	umap.insert(make_pair(host, ip));
}

bool UMNS::remove(const HostName& host){
	auto itr = umap.find(host);

	if (itr != umap.end()){
		umap.erase(itr);
		return true;
	} else {
		return false;
    }
}

IPAddress UMNS::lookup(const HostName& host) const{
	auto itr = umap.find(host);
	
	if (itr != umap.end()) {
		return itr->second;
	} else {
		return NON_EXISTING_ADDRESS;
	}
}
