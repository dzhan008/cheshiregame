#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "Item.h"

class Player;

class Consumable : public Item
{
	private:
		unsigned boost;
	public:
		Consumable(std::string, std::string, unsigned, int);
		//~Consumable();
		void usePotion(player* p);
		string getType() const;
};

#endif
