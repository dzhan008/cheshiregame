#include "stdafx.h"

#include <iostream>

using namespace std;

//Types shall be as follows:
//Staff, Dagger, Bow, Single, Double
bool Weapon::equipWeapon(string item, player* p)
{
	for(int i = 0; i < p->getWepSize(); i++)
	{
		if(p->wep_search(item) != NULL)
		{
			p->equip_wep(0, p->wep_search(item)); //TO DO: Make this work for Off-Hand and other weapons
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
