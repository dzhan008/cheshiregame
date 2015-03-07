#include "Item.h"
#include <string>
#include <fstream>

using namespace std;

Item::Item()
    :value(0)
{}
Item::Item(const string name)
    :this->name(name), value(0)
{}
Item::Item(const string name, const int val)
    :this->name(name), value(val)
{}
void Item::printItem()
{
    cout << "Name: " << name << std::endl;
    cout << "Value: " << value << std::endl;
}
bool Equip::equipPlayer(string item)
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
}
bool Potion::usePotion()
{
    for(int i = 0; i < playerInventory.size(); i++)
    {
        if(playerInventory.at(i).name == "Health")
        {
            playerEquipped.push_back(playerInventory.at(i));
            playerInventory.erase(i);
            if(player.health + 20 > 100) //100 assumed to be max health for now
            {
                player.health = 100;
            }
            else
            {
                player.health += 20; 
            }
            return true;
        }
        if(playerInventory.at(i).name == "Mana")
        {
            playerEquipped.push_back(playerInventory.at(i));
            playerInventory.erase(i);
            return true;   
        }
    }
    cout << "Potion not found." << endl;
    return false;
}
//Each quest item is unique. Meaning it will trigger different things to occur.
//Implementation right now is with just one quest item. 
//Add more to quest_item file as storyline progresses.
void Quest::triggerItem()
{
    ifstream fin;
    string line;
    fin.open(quest_item.c_str());
    while(getline(fin, line))
    {
        cout << line << endl;
    }
    player.gold += 500;
}
