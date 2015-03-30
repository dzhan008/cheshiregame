#ifndef GEAR_H
#define GEAR_H

#include "Item.h"
#include "Player.h"

class Gear : public Item
{
private:
	string type;
	int statBoost;
public:
	Gear(const Gear&);
	bool equipGear(string itemName, unsigned bodyPart, player p);
	string getType() const;
	void printItem() const;
};

#endif
