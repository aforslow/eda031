#ifndef VNS_H
#define VNS_H

#include <iostream>
#include <string>
#include <vector>
#include "nameserverinterface.h"


class VNS : public NameServerInterface{
	private:
        std::vector<std::pair<HostName, IPAddress>> vector_server;
	public:
		void insert(const HostName& host, const IPAddress& ip);
		bool remove(const HostName& host);
		IPAddress lookup(const HostName&) const;
};

#endif
