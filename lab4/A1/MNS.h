#ifndef MNS_H
#define MNS_H

#include <iostream>
#include "nameserverinterface.h"
#include <map>
class MNS {
	private:
		std::map<HostName, IPAddress> map_server;
	public:
		void insert(const HostName& host, const IPAddress& ip);
		bool remove(const HostName& host);
		IPAddress lookup(const HostName& host) const;
};

#endif
