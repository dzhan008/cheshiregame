#ifndef WEAPON_H
#define WEAPON_H

#include "stdafx.h"
#include "Item.h"
#include "Player.h"

class Weapon : public Item
{
	private:
		int damageBoost;
		string type;
	public:
		Weapon(std::string nam, std::string type, int val, int dmg);
		Weapon(const Weapon&);
		Weapon(const Weapon*&);

		bool equipWeapon(string itemName, player* p);
		string getType() const;
		void printItem() const;
};

#endif
