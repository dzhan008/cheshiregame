#include "Consumable.h"
#include "Player.h"

#include <iostream>

using namespace std;

bool Consumable::usePotion(player p)
{
	for (int i = 0; i < p.getInvSize(); i++)
	{
		if (p.inventory_search("Health"))
		{
			p.remove_inventory("Health");
			if (p.getHP() + 20 > 100) //100 assumed to be max health for now
			{
				p.setHP(100);
			}
			else
			{
				p.setHP(p.getHP() + 20);
			}
			return true;
		}
		if (p.inventory_search("Mana"))
		{
			p.remove_inventory("Mana");
			return true;
		}
	}
	cout << "Potion not found." << endl;
	return false;
}
