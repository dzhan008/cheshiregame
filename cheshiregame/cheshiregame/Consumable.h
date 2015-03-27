#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "Item.h"

class Consumable : public Item
{
	private:
		int boost;
	public:
		bool usePotion(player p);
};

#endif
