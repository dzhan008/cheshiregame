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

    public:
        Item();
        Item(const string);
        Item(const string, const int);
        Item(const Item &);
        void printItem() const; //Make virtual
		Item findItem(string itemName);

		string getName() const;
		int getValue() const;
};

#endif
