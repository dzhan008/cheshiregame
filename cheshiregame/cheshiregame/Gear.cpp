#include "stdafx.h"

#include <iostream>
	
using namespace std;

//Types shall be as follows:
//Helmet, Chest, Legs, Arms, Shoes
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
			p->equip_gear(3, gear);
			return true;
		}
		else if (gear->getType() == "Arms")
		{
			p->equip_gear(2, gear);
			return true;
		}
		//Check bodyPart is a valid num, where each gear should go
		return true;
	}
	
	cout << "Item not found." << endl;
	return false;
}
string Gear::getType() const 
{
	return type;
}

int Gear::getStats(){
	return statBoost;
}

Gear::Gear(std::string nam,std::string type, int val)
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

Gear::Gear(const Gear*& origGear)
{
	Item::type = "Gear";
	this->name = origGear->name;
	this->value = origGear->value;
	this->statBoost = statBoost;
}

Gear::Gear(Gear* origGear)
{
	Item::type = "Gear";
	this->name = origGear->name;
	this->value = origGear->value;
	this->statBoost = statBoost;
}

/*Gear::~Gear()
{
	delete this;
}*/
void Gear::printItem() const
{
	Item::printItem();
	cout << "Type: " << type << endl;
}
