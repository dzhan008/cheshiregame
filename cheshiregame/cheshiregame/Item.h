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
		string type;
		float rarity; //How rare the drop is; Used for when player receives loot from entity.

    public:
        Item();
        Item(const string);
        Item(const string, const int);
		Item(const string, const int, const string);
		Item(const string, const int, const string, const float);
        Item(const Item &);
		Item(const Item* &);
        virtual void printItem() const;
		
		string getType() const;
		string getName() const;
		int getValue() const;
};

#endif
