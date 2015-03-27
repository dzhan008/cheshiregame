#ifndef KEY_H
#define KEY_H

#include "Item.h"
#include "Player.h"

class Key : public Item
{
	public:
		void triggerItem(player p);
};

#endif
