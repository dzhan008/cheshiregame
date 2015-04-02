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
	bool equipGear(string itemName, unsigned bodyPart, player* p);
	string getType() const;
	void printItem() const;
};

#endif
