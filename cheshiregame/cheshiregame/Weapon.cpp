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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> parent of beb3c92... Weapon Class Bug Fixes and Reorganization
=======
>>>>>>> parent of beb3c92... Weapon Class Bug Fixes and Reorganization
string Weapon::getType() const
{
	return "Weapon";
}

<<<<<<< HEAD
<<<<<<< HEAD
int Weapon::getValue(){
	return damageBoost;
}

=======
>>>>>>> origin/master
=======
=======
>>>>>>> parent of beb3c92... Weapon Class Bug Fixes and Reorganization
int Weapon::getDmg(){
	return damageBoost;
}

<<<<<<< HEAD
>>>>>>> parent of beb3c92... Weapon Class Bug Fixes and Reorganization
=======
>>>>>>> parent of beb3c92... Weapon Class Bug Fixes and Reorganization
void Weapon::add_dmg(int dmg)
{
	damageBoost += dmg;
}

Weapon::Weapon(std::string name, std::string type, int dmg, int val)
{
	this->name = name;
	Item::type = "Weapon";
	this->type = type;
	value = val;
	damageBoost = dmg;
}

Weapon::Weapon(const Weapon& origWeapon)
{
	Item::Item(origWeapon);
	this->damageBoost = origWeapon.damageBoost;
}
Weapon::Weapon(const Weapon*& origWeapon)
{
	this->name = origWeapon->name;
	this->value = origWeapon->value;
	this->damageBoost = origWeapon->damageBoost;
}
void Weapon::printItem() const
{
	Item::printItem();
	cout << "Type: " << type << endl;
}
