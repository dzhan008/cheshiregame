#include "stdafx.h"

#include <iostream>

using namespace std;

//Types shall be as follows: Staff, Dagger, Bow, Single, Double
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
int Weapon::getDmg() const
{
	return damageBoost;
}
string Weapon::getType() const
{
	return "Weapon";
}
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
string Weapon::getType() const
{
	return "Weapon";
}

int Weapon::getValue(){
	return damageBoost;
}

=======
>>>>>>> origin/master
void Weapon::add_dmg(int dmg)
{
	damageBoost += dmg;
}
