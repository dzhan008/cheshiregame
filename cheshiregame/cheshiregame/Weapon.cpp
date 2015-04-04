#include "stdafx.h"

#include <iostream>

using namespace std;

//Types shall be as follows:
//Staff, Dagger, Bow, Single, Double
bool Weapon::equipWeapon(Weapon* wep, player* p)
{
	if (wep != NULL)
	{
		if(wep->getType() == "Sword")
		{
			p->equip_wep(0, wep); //TO DO: Make this work for Off-Hand and other weapons
			return true;
		}
		else
		{
			p->equip_wep(0, wep);
			return true;
		}
	}
	cout << "Item not found." << endl;
	return false;
}
string Weapon::getType() const
{
	return "Weapon";
}

int Weapon::getValue(){
	return damageBoost;
}

Weapon::Weapon(std::string nam, std::string type, int val, int dmg)
{
	name = nam;
	Item::type = "Weapon";
	this->type = type;
	value = val;
	damageBoost = dmg;
}

Weapon::Weapon(const Weapon& origWeapon)
{
	Item::Item(origWeapon);
	this->damageBoost = damageBoost;
}
Weapon::Weapon(const Weapon*& origWeapon)
{
	this->name = origWeapon->name;
	this->value = origWeapon->value;
	this->damageBoost = damageBoost;
}
void Weapon::printItem() const
{
	Item::printItem();
	cout << "Type: " << type << endl;
}
