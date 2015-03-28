#ifndef GEAR_H
#define GEAR_H

#include "Item.h"
#include "Player.h"

class Gear : public Item
{
private:
	int statBoost;
public:
	bool equipGear(string itemName, unsigned bodyPart, player p);
	Gear(const Gear&);
};

#endif
