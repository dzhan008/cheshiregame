#ifndef _Item_H_
#define _Item_H_

#include "stdafx.h"
#include <string>

using namespace std;

class Player;

class Item
{
    public:
        Item();
        Item(const string);
        Item(const string, const int val);
        void printItem() const;
		void set_name(string);
		string get_name() const;
    private:
        string name;
        int value;
};
class Equip:public Item
{
    public:
        bool equipPlayer(string item);
};
class Potion:public Item
{
    public:
        bool usePotion(player p);
};
class Quest:public Item
{
    public:
        void triggerItem();
};

#endif
