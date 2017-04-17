#pragma once

#include <list>
#include <exception>

#include "Honeypot.h"
#include "RegistryIO.h"

using std::list;
using std::exception;

#define DEFAULT_HONEYPOTS_LIMIT 10

class HoneypotsManager
{
private:
	RegistryIO registryIO;
	list<Honeypot> honeypots;
	
	void addHoneypot(Honeypot& honeypot);
	void removeOneHoneypot();
	void addHoneypots(unsigned int num);
	void removeHoneypots(unsigned int num);
	void changeHoneypotsAmountInFileSystem(unsigned int newSize);
	void loadHoneypotsFromRegistry();

public:
	HoneypotsManager();
	HoneypotsManager(unsigned int limit);
	void setLimitToHoneypots(unsigned int newLimit);
	void monitorHoneypots();
	void removeAllHoneypots();
	~HoneypotsManager();
};

class HoneypotsManagerExceptoins : public exception{};
class CantRemoveHoneypot : public HoneypotsManagerExceptoins {};

