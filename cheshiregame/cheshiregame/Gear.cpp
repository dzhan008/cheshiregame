#include "stdafx.h"

#include <iostream>
	
using namespace std;

//Types shall be as follows:
//Helmet, Chest, Legs, Arms, Shoes
Gear::Gear(std::string nam, std::string type, int val)
{
	name = nam;
	value = val;
	this->type = type;
}
Gear::Gear(std::string name, int val, std::string type, int stat)
{
	Item::type = "Gear";
	this->name = name;
	value = val;
	this->type = type;
	statBoost = stat;
}
Gear::~Gear()
{}
Gear::Gear(const Gear*& origGear)
{
	this->name = origGear->name;
	this->value = origGear->value;
	this->statBoost = statBoost;
}
string Gear::getType() const
{
	return type;
}
int Gear::getStats()
{
	return statBoost;
}
void Gear::printItem() const
{
	Item::printItem();
	cout << "Type: " << type << endl;
}
bool Gear::equipGear(Gear* gear, player* p)
{	
	if (gear != NULL)
	{
		if (gear->getType() == "Helmet")
		{
			p->equip_gear(0, gear);
			return true;
		}
		else if (gear->getType() == "Chest")
		{
			p->equip_gear(1, gear);
			return true;
		}
		else if (gear->getType() == "Legs")
		{
			p->equip_gear(2, gear);
			return true;
		}
		else if (gear->getType() == "Arms")
		{
			p->equip_gear(3, gear);
			return true;
		}
		return true;
	}
	cout << "Item not found." << endl;
	return false;
}
