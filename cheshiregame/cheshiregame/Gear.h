#ifndef GEAR_H
#define GEAR_H

#include "stdafx.h"
#include "Item.h"

class Gear : public Item
{
private:
	string type;
	unsigned statBoost;
public:
	Gear(std::string name, std::string type, int val);
	Gear(std::string name, int val, std::string type, int stat);
	Gear(const Gear*&);
	//~Gear();
	bool equipGear(Gear* gear, player* p);
	string getType() const;
	void printItem() const;
	int getStats();
};

#endif
