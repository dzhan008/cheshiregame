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
		//Constructors
		Weapon(std::string name, std::string type, int dmg, int val);
		Weapon(const Weapon&);
		Weapon(const Weapon*&);

		//Accessor Functions
		int getDmg() const;
		string getType() const;

		//Mutator Functions
		bool equipWeapon(Weapon* wep, player* p);
		void add_dmg(int dmg);
};

#endif
