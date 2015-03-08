#include "stdafx.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Item::Item()
    :value(0)
{}
Item::Item(const string name)
    :name(name), value(0)
{}
Item::Item(const string name, const int val)
    :name(name), value(val)
{}
void Item::printItem() const
{
    cout << "Name: " << name << std::endl;
    cout << "Value: " << value << std::endl;
}

string Item::get_name() const
{
	return name;
}

void Item::set_name(string n)
{
	name = n;
}
/*bool Equip::equipPlayer(string item)
{
    for(int i = 0; i < playerInventory.size(); i++)
    {
        if(playerInventory.at(i).name == item)
        {
            playerEquipped.push_back(playerInventory.at(i));
            return true;
        }
    }
    cout << "Item not found." << endl;
    return false;
}*/
bool Potion::usePotion(player p)
{
    for(int i = 0; i < p.getInvSize(); i++)
    {
        if(p.inventory_search("Health"))
        {
			p.remove_inventory("Health");
            if(p.getHP() + 20 > 100) //100 assumed to be max health for now
            {
                p.setHP(100);
            }
            else
            {
                p.setHP(p.getHP() + 20); 
            }
            return true;
        }
        if(p.inventory_search("Mana"))
        {
			p.remove_inventory("Mana");
            return true;   
        }
    }
    cout << "Potion not found." << endl;
    return false;
}
//Each quest item is unique. Meaning it will trigger different things to occur.
//Implementation right now is with just one quest item. 
//Add more to quest_item file as storyline progresses.
/*void Quest::triggerItem()
{
    ifstream fin;
    string line;
    fin.open(quest_item.c_str());
    while(getline(fin, line))
    {
        cout << line << endl;
    }
    player.gold += 500;
}*/
