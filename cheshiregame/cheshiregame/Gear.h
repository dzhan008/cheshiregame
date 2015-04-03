#ifndef GEAR_H
#define GEAR_H

#include "stdafx.h"
#include "Item.h"

class Gear : public Item
{
private:
	string type;
	int statBoost;
public:
	Gear(std::string name, int val, std::string type);
	Gear(std::string name, int val, std::string type, int stat);
	Gear(const Gear*&);
	~Gear();
	bool equipGear(string itemName, unsigned bodyPart, player* p);
	string getType() const;
	void printItem() const;
};

#endif
