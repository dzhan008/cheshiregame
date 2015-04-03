#include "stdafx.h"
#include "Gear.h"

#include <iostream>
	
using namespace std;

//Types shall be as follows:
//Helmet, Chest, Legs, Arms, Shoes
Gear::~Gear()
{
	delete this;
}
bool Gear::equipGear(string item, unsigned bodyPart, player* p)
{
	if (bodyPart > 4)
	{
		cout << "Invalid location." << endl;
		return false;
	}
	for (int i = 0; i < p->getGearSize(); i++)
	{
		if (p->gear_search(item) != NULL)
		{
			if (p->gear_search(item)->getType() == "Helmet")
			{
				p->equip_gear(0, p->gear_search(item));
				return true;
			}
			else if (p->gear_search(item)->getType() == "Chest")
			{
				p->equip_gear(1, p->gear_search(item));
				return true;
			}
			else if (p->gear_search(item)->getType() == "Legs")
			{
				p->equip_gear(2, p->gear_search(item));
				return true;
			}
			else if (p->gear_search(item)->getType() == "Arms")
			{
				p->equip_gear(3, p->gear_search(item));
				return true;
			}
			//Check bodyPart is a valid num, where each gear should go
			//p.equip_slot(bodyPart, p.returnItem(i));
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

Gear::Gear(std::string name, int val, string type, int stat)
{
	this->name = name;
	this->value = val;
	this->type = type;
}

Gear::Gear(const Gear*& origGear)
{
	this->name = origGear->name;
	this->value = origGear->value;
	this->statBoost = origGear->statBoost;
}
void Gear::printItem() const
{
	Item::printItem();
	cout << "Type: " << type << endl;
	cout << "Defense Boost: +" << statBoost << endl;
}
