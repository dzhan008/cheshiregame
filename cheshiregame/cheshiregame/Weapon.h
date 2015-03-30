#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "Player.h"

class Weapon : public Item
{
	private:
		int damageBoost;
		string type;
	public:
		bool equipWeapon(string itemName, player p);
		string getType() const;
		Weapon(const Weapon&);
		void printItem() const;
};

#endif
