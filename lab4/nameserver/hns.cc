#include "hns.h"


using namespace std;

/*
HNS::HNS(){
    size = 10;
    hash_server.reserve(size);
}
*/
HNS::HNS(const unsigned int s) : size(s){
    hash_server.reserve(size);
}

void HNS::insert(const HostName& host, const IPAddress& ip){
    string::size_type idx = hash<string>{}(host);
    idx = idx % size;
    vector<pair<HostName, IPAddress>> &vect = hash_server[idx];
    vect.push_back(make_pair(host, ip));
}

bool HNS::remove(const HostName& host){
    string::size_type idx = hash<string>{}(host);
    idx = idx % size;
    auto& bahn = hash_server[idx];
    const auto itr = find_if(bahn.begin(),bahn.end(),
                       [host](pair<HostName, IPAddress> s) {return host == s.first;});

    if (itr != bahn.end()) {
        bahn.erase(itr);
        return true;
    }
    return false;
    
}

IPAddress HNS::lookup(const HostName& host) const{
    string::size_type idx = hash<string>{}(host);
    idx = idx % size;
    auto& bahn = hash_server[idx];
    //auto ban = [host](pair<HostName, IPAddress> pa) { return host == pa.first; };
    //const auto& itr = find_if(bahn.begin(), bahn.end(), ban);
    const auto itr = find_if(bahn.begin(), bahn.end(),
                       [host](pair<HostName, IPAddress> s) {return host == s.first;});
    if (itr != bahn.end()) {
	    return itr->second;
    } else {
	    return NON_EXISTING_ADDRESS;
    }
}













