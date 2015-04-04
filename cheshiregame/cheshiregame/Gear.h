#ifndef GEAR_H
#define GEAR_H

#include "stdafx.h"

class Gear : public Item
{
private:
	string type;
	int statBoost;
public:
	Gear(std::string nam, std::string type, int val);
	Gear(const Gear*&);	
	bool equipGear(Gear* gear, player* p);
	int getStats();
	string getType() const;
	void printItem() const;
};

#endif
