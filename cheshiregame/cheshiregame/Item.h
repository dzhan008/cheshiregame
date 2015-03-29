#ifndef _Item_H_
#define _Item_H_

#include "stdafx.h"

#include <string>

using namespace std;

class Item
{
	private:
		string name;
		int value;
		int slot_type; //Used for gears to indicate what type of slot it is. See player equipment inv for IDs.
		float rarity; //How rare the drop is; Used for when player receives loot from entity.
		//TO DO: Update constructors for  new variables
    public:
        Item();
        Item(const string);
        Item(const string, const int);
        Item(const Item &);
		Item(const Item* &);
        void printItem() const; //Make virtual
	
		string getName() const;
		int getValue() const;
		int getSlot() const;
};

#endif
