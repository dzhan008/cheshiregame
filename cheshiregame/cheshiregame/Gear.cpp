#include "Gear.h"

#include <iostream>

using namespace std;

bool Gear::equipGear(string item, unsigned bodyPart, player p)
{
	if (bodyPart > 6)
	{
		cout << "Invalid location." << endl;
		return false;
	}
	for (int i = 0; i < p.getInvSize; i++)
	{
		if (p.inventory_search(item))
		{
			//Check bodyPart is a valid num, where each gear should go
			p.equip_slot(bodyPart, Item(item));
			return true;
		}
	}
	cout << "Item not found." << endl;
	return false;
}
Gear::Gear(const Gear& origGear)
{
	Item::Item(origGear);
	this->statBoost = statBoost;
}
