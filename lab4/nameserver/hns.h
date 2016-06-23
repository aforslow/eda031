#ifndef HNS_H
#define HNS_H

#include <iostream>
#include <string>
#include "nameserverinterface.h"
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>

class HNS : public NameServerInterface{
	private:
        std::vector<std::vector<std::pair<HostName, IPAddress>>> hash_server;
        size_t size;
	public:
        //HNS();
        HNS(const unsigned int size);
		void insert(const HostName& host, const IPAddress& ip);
		bool remove(const HostName& host);
		IPAddress lookup(const HostName& host) const;
};

#endif
