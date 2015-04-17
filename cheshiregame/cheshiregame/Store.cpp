#include "stdafx.h"
#include "Player.h"
#include "Store.h"
#include "Item.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Store::Store()
	: numHealthPots(0), numManaPots(0)
{}

Store::~Store() {
    //for (int i = 0; i < storeInventory.size(); ++i) {
        //delete storeInventory.at(i);
    //}
	//for (int i = 0; i < gearInv.size(); ++i) {
		//delete gearInv.at(i);
	//}
	//for (int i = 0; i < weapInv.size(); ++i) {
		//delete weapInv.at(i);
	//}
	//for (int i = 0; i < potInv.size(); ++i) {
		//delete potInv.at(i);
	//}
}

void Store::run(player* p)
{
    int spentGold = 0;
    string choice = "a";
    int usernum;

    std::cout << "Welcome to Cheshire's Store." << std::endl;
    std::cout << "Gold remaining: " << p->getmoney() << std::endl;
    while (choice != "q") 
	{
        menu();
        std::cin >> choice;
        if (choice == "v")
        {
            printStore();
        }
        else if (choice == "p")
        {
            std::cout << "Enter the number of the item to purchase." << std::endl;
            std::cin >> usernum;
            if (usernum > storeInventory.size() || usernum < 1)
            {
                std::cout << "Item cannot be accessed." << std::endl;
            }
            else if (p->getmoney() < storeInventory.at(usernum - 1)->getValue())
            {
                std::cout << "You are too poor." << std::endl;
            }
            else
            {
				if (storeInventory.at(usernum - 1)->getType() == "Weapon")
				{
					for (int i = 0; i < weapInv.size(); ++i)
					{
						if (storeInventory.at(usernum - 1)->getName() == weapInv.at(i)->getName())
						{
							p->add_wep(weapInv.at(i));
							weapInv.erase(weapInv.begin() + i);
						}
					}
					std::cout << "You bought one " << storeInventory.at(usernum - 1)->getName() << "." << std::endl;
					spentGold += storeInventory.at(usernum - 1)->getValue();
					int playerMoney = p->getmoney() - storeInventory.at(usernum - 1)->getValue();
					p->setmoney(playerMoney);
					storeInventory.erase(storeInventory.begin() + usernum - 1);
				}
				else if (storeInventory.at(usernum - 1)->getType() == "Gear")
				{
					for (int i = 0; i < gearInv.size(); ++i)
					{
						if (storeInventory.at(usernum - 1)->getName() == gearInv.at(i)->getName())
						{
							p->add_gear(gearInv.at(i));
							gearInv.erase(gearInv.begin() + i);
						}
					}
					std::cout << "You bought one " << storeInventory.at(usernum - 1)->getName() << "." << std::endl;
					spentGold += storeInventory.at(usernum - 1)->getValue();
					int playerMoney = p->getmoney() - storeInventory.at(usernum - 1)->getValue();
					p->setmoney(playerMoney);
					storeInventory.erase(storeInventory.begin() + usernum - 1);
				}
				else if (storeInventory.at(usernum - 1)->getType() == "Consumable")
				{
					if (storeInventory.at(usernum - 1)->getName() == "Health Potion")
					{
						for (int i = 0; i < potInv.size(); ++i)
						{
							if (storeInventory.at(usernum - 1)->getName() == potInv.at(i)->getName())
							{
								p->add_con(potInv.at(i));
								potInv.erase(potInv.begin() + i);
							}
						}
						--numHealthPots;
						std::cout << "You bought one " << storeInventory.at(usernum - 1)->getName() << "." << std::endl;
						spentGold += storeInventory.at(usernum - 1)->getValue();
						int playerMoney = p->getmoney() - storeInventory.at(usernum - 1)->getValue();
						p->setmoney(playerMoney);
						if (numHealthPots == 0)
						{
							storeInventory.erase(storeInventory.begin() + usernum - 1);
						}
					}
					else //Mana pot
					{
						for (int i = 0; i < potInv.size(); ++i)
						{
							if (storeInventory.at(usernum - 1)->getName() == potInv.at(i)->getName())
							{
								p->add_con(potInv.at(i));
								potInv.erase(potInv.begin() + i);
							}
						}
						--numManaPots;
						std::cout << "You bought one " << storeInventory.at(usernum - 1)->getName() << "." << std::endl;
						spentGold += storeInventory.at(usernum - 1)->getValue();
						int playerMoney = p->getmoney() - storeInventory.at(usernum - 1)->getValue();
						p->setmoney(playerMoney);
						if (numManaPots == 0)
						{
							storeInventory.erase(storeInventory.begin() + usernum - 1);
						}
					}
				}
            }
        }
    }
    std::cout << "Gold spent: " << spentGold << std::endl;
    std::cout << "Gold remaining: " << p->getmoney() << std::endl;
    return;
}
void Store::menu() const
{
    std::cout << "Press v to view the store inventory." << std::endl;
    std::cout << "Press p to purchase an item." << std::endl;
    std::cout << "Press q to leave the store." << std::endl;
}
void Store::printStore()
{
	//std::cout << "SIZE: " << storeInventory.size() << std::endl;
    for(int i = 0; i < storeInventory.size(); ++i) 
    {
		std::cout << i + 1 << ": " << storeInventory.at(i)->getName() << std::endl;
		std::cout << storeInventory.at(i)->getValue() << " gold" << std::endl;

		if (storeInventory.at(i)->getName() == "Health Potion")
		{
			std::cout << "Amount: " << numHealthPots << std::endl;
		}
		else if (storeInventory.at(i)->getName() == "Mana Potion")
		{
			std::cout << "Amount: " << numManaPots << std::endl;
		}
    }
}
void Store::fillStore(const string &input_file)
{
    ifstream fin; 

    string itemName;
    int val;
    string type;
	unsigned boost = 4;
	int num_potions = 0;

    fin.open(input_file.c_str());
	if (!fin)
	{
		std::cout << "Error opening file." << std::endl;
		return;
	}

    while(fin >> type)
    {
		if (type == "Weapon")
		{
			fin.ignore(); getline(fin, itemName); fin >> val; fin >> boost;
			Weapon* temp = new Weapon(itemName, type, boost, val);
			storeInventory.push_back(temp);
			weapInv.push_back(temp);
		}
		else if (type == "Gear")
		{
			fin >> type; fin.ignore(); getline(fin, itemName); fin >> val; fin >> boost;
			Gear* temp = new Gear(itemName, val, type, boost);
			storeInventory.push_back(temp);
			gearInv.push_back(temp);
		}
		else if (type == "Consumable")
		{
			fin.ignore(); getline(fin, itemName); fin >> val; fin >> boost; fin >> num_potions;
			for (int i = 0; i < num_potions; ++i)
			{
				Consumable* temp = new Consumable(itemName, type, boost, val);
				//If the print store doesnt have a pot, pushes one and only one into it.
				if (!healthPotExists(storeInventory) && itemName == "Health Potion")
				{
					storeInventory.push_back(temp);
					//std::cout << "HEALTH POT PUSHED INTO PRINT_STORE" << std::endl;
				}
				else if (!manaPotExists(storeInventory) && itemName == "Mana Potion")
				{
					storeInventory.push_back(temp);
					//std::cout << "MANA POT PUSHED INTO PRINT_STORE" << std::endl;
				}
				if (itemName == "Health Potion")
				{
					++numHealthPots;
				}
				else if (itemName == "Mana Potion")
				{
					++numManaPots;
				}
				potInv.push_back(temp);
			}
		}
		//std::cout << "SIZE: " << storeInventory.size() << std::endl;
		//std::cout << "Name: " << storeInventory.at(storeInventory.size() - 1)->getName() << std::endl;
		//std::cout << "Value: " << storeInventory.at(storeInventory.size() - 1)->getType() << std::endl;
    }
    fin.close();
	//std::cout << "fillStore ended." << endl;
}
void Store::storeUpdate()
{
	std::cout << "Our shipments are still on their way! The items you see are what you get." << std::endl;
	return;
}
bool Store::healthPotExists(const vector<Item*>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i)->getName() == "Health Potion")
		{
			return true;
		}
	}
	return false;
}
bool Store::manaPotExists(const vector<Item*>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i)->getName() == "Mana Potion")
		{
			return true;
		}
	}
	return false;
}