#include "Gear.h"

#include <iostream>

using namespace std;

//Types shall be as follows:
//Helmet, Chest, Legs, Arms
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
			if (p.returnItem(i)->getType() == "Helmet")
			{
				p.equip_slot(0, p.returnItem(i));
				return true;
			}
			else if (p.returnItem(i)->getType() == "Chest")
			{
				p.equip_slot(1, p.returnItem(i));
				return true;
			}
			else if (p.returnItem(i)->getType() == "Legs")
			{
				p.equip_slot(2, p.returnItem(i));
				return true;
			}
			else if (p.returnItem(i)->getType() == "Arms")
			{
				p.equip_slot(3, p.returnItem(i));
				return true;
			}
			//Check bodyPart is a valid num, where each gear should go
			p.equip_slot(bodyPart, p.returnItem(i));
			return true;
		}
	}
	cout << "Item not found." << endl;
	return false;
}
string Gear::getType() const 
{
	return type;
}
Gear::Gear(const Gear& origGear)
{
	Item::Item(origGear);
	this->statBoost = statBoost;
}
void Gear::printItem() const
{
	Item::printItem();
	cout << "Type: " << type << endl;
}
