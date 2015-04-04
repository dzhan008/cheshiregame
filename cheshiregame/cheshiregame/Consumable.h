#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "Item.h"

class Consumable : public Item
{
	private:
		unsigned boost;
	public:
		Consumable(std::string, int, std::string, unsigned);
		~Consumable();
		bool usePotion(player p);
		string getType() const;
};

#endif
