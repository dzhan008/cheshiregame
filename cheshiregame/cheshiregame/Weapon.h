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
		Weapon(std::string name, int val, std::string type, int dmg);
		~Weapon();
		Weapon(const Weapon&);
		Weapon(const Weapon*&);
		bool Weapon::equipWeapon(Weapon* wep, player* p);
		string getType() const;
		void printItem() const;
};

#endif
