#ifndef UMNS_H
#define UMNS_H

#include <iostream>
#include "nameserverinterface.h"
#include <unordered_map>

class UMNS : public NameServerInterface{
	private:
		std::unordered_map<HostName, IPAddress> umap;
	public:
		void insert(const HostName& host, const IPAddress& ip);
		bool remove(const HostName& host);
		IPAddress lookup(const HostName&) const;
};

#endif