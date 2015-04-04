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
{}

Store::~Store() {
    for (int i = 0; i < storeInventory.size(); ++i) {
        delete storeInventory.at(i);
    }
}

void Store::run(player p)
{
    int spentGold = 0;
    string choice = "a";
    int usernum;

    cout << "Welcome to Cheshire's Store." << endl;
    cout << "Gold remaining: " << p.getmoney() << endl;
    while (choice != "q") {
        menu();
        cin >> choice;
        if (choice == "v")
        {
            printStore();
        }
        else if (choice == "p")
        {
            cout << "Enter the number of the item to purchase." << endl;
            cin >> usernum;
            if (usernum - 1 > storeInventory.size())
            {
                cout << "Item cannot be accessed." << endl;
            }
            if (p.getmoney() < storeInventory.at(usernum)->getValue())
            {
                cout << "You are too poor." << endl;
            }
            else
            {
                storeInventory.erase(storeInventory.begin() + usernum - 2);
                spentGold += storeInventory.at(usernum)->getValue();
                int playerMoney = p.getmoney() - storeInventory.at(usernum)->getValue();
                p.setmoney(playerMoney);
                cout << "You bought one " << storeInventory.at(usernum)->getName() << endl;
            }
        }

    }
    cout << "Gold spent: " << spentGold << endl;
    cout << "Gold remaining: " << p.getmoney() << endl;
    return;
}
void Store::menu() const
{
    cout << "Press v to view the store inventory." << endl;
    cout << "Press p to purchase an item." << endl;
    cout << "Press q to leave the store." << endl;
}
void Store::printStore()
{
    //std::cout << storeInventory.size() << std::endl;
    cout << storeInventory.at(0)->getName() << endl;

    std::cout << "PRINTING STORE" << storeInventory.size() << std::endl;
    for(int i = 0; i < storeInventory.size(); i++)
    {
	cout << i << ". " << storeInventory.at(i)->getName() << ' ' << storeInventory.at(i)->getValue()
        << " gold" << endl;
    }
}
void Store::fillStore(const string &input_file)
{
    //std::cout << "Filling store" << std::endl;
    ifstream fin; 

    string itemName;
    int val;
    string type;
	unsigned boost;

    fin.open(input_file.c_str());
	if (!fin)
	{
		cout << "Error opening file." << endl;
		return;
	}

    while(getline(fin, type))
    {
        //std::cout << type << std::endl;
        string v, b;
        getline(fin, itemName);
        getline(fin, v);
        stringstream ss(v);
        ss >> val;
        getline(fin, b);
        stringstream ss2(b);
        ss2 >> boost;

        //std::cout << type << " " << itemName << " " << val << " " << boost << " " << endl;
		if (type == "Weapon")
		{
		//	fin >> itemName; fin >> val; fin >> boost;
			Weapon* temp = new Weapon(itemName, type, boost, val);
			storeInventory.push_back(temp);
			//delete temp;
		}
		else if (type == "Chest")
		{
		//	fin >> itemName; fin >> val; fin >> boost;
			Gear* temp = new Gear(itemName, val, type, boost);
			storeInventory.push_back(temp);
			//delete temp;
		}
		else if (type == "Helmet")
		{
		//	fin >> itemName; fin >> val; fin >> boost;
			Gear* temp = new Gear(itemName, val, type, boost);
			storeInventory.push_back(temp);
			//delete temp;
		}
		else if (type == "Legs")
		{
		//	fin >> itemName; fin >> val; fin >> boost;
			Gear* temp = new Gear(itemName, val, type, boost);
			storeInventory.push_back(temp);
			//delete temp;
		}
		else if (type == "Arms")
		{
		//	fin >> itemName; fin >> val; fin >> boost;
			Gear* temp = new Gear(itemName, val, type, boost);
			storeInventory.push_back(temp);
			//delete temp;
		}
		else if (type == "Consumable")
		{
		//	fin >> itemName; fin >> val; fin >> boost;
			Consumable * temp = new Consumable(itemName, type, boost, val);
			storeInventory.push_back(temp);
		}
        // Test item existence here, but doesn't work in print store?
        //std::cout << "TYPE: " << storeInventory.at(storeInventory.size() - 1)->getType() << std::endl
        //    << "NAME: " << storeInventory.at(storeInventory.size() - 1)->getName() << std::endl
        //    << "VALUE: " << storeInventory.at(storeInventory.size() - 1)->getValue() << std::endl;
    }
    fin.close();
}
