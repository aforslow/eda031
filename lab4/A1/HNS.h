#ifndef HNS_H
#define HNS_H

#include <iostream>
#include <string>
#include "nameserverinterface.h"
#include <vector>

class HNS {
	private:
        std::vector<std::vector<std::pair<HostName, IPAddress>>> hash_server;
        int size;
	public:
        HNS();
        HNS(int size);
		void insert(const HostName& host, const IPAddress& ip);
		bool remove(const HostName& host);
		IPAddress lookup(const HostName&) const;
};

#endif
