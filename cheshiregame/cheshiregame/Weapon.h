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
		Weapon(std::string name, std::string type, int dmg, int val);
		Weapon(const Weapon&);
		Weapon(const Weapon*&);

		int getValue();
		bool equipWeapon(Weapon* wep, player* p);
		string getType() const;
		void printItem() const;
};

#endif
