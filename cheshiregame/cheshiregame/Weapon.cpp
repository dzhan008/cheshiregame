#include "Weapon.h"

#include <iostream>

using namespace std;

//Types shall be as follows:
//Staff, Dagger, Bow, Single, Double
bool Weapon::equipWeapon(string item, player p)
{
	for(int i = 0; i < p.getInvSize; i++)
	{
		if(p.inventory_search(item))
		{
			p.equip_slot(6, p.returnItem(i));
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
Weapon::Weapon(const Weapon& origWeapon)
{
	Item::Item(origWeapon);
	this->damageBoost = damageBoost;
}
void Weapon::printItem() const
{
	Item::printItem();
	cout << "Type: " << type << endl;
}
