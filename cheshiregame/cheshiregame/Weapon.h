#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "Player.h"

class Weapon : public Item
{
	private:
		int damageBoost;
	public:
		bool equipWeapon(string itemName, player p);
		Weapon(const Weapon&);
};

#endif
