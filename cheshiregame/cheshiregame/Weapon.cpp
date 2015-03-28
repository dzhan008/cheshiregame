#include "Weapon.h"

#include <iostream>

using namespace std;

bool Weapon::equipWeapon(string item, player p)
{
	for(int i = 0; i < p.getInvSize; i++)
	{
		if(p.inventory_search(item))
		{
			p.equip_slot(6, Item(item));
			return true;
		}
	}
	cout << "Item not found." << endl;
	return false;
}
Weapon::Weapon(const Weapon& origWeapon)
{
	Item::Item(origWeapon);
	this->damageBoost = damageBoost;
}
