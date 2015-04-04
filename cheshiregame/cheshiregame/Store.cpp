#include "stdafx.h"
#include "Player.h"
#include "Store.h"
#include "Item.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Store::Store()
{}

void Store::run(player p)
{
    int spentGold = 0;
    char choice;
    int usernum;

    cout << "Welcome to Chesire's Store." << endl;
    cout << "Gold remaining: " << p.getmoney() << endl;
    menu();
    cin >> choice;

    if(choice == 'v')
    {
        printStore();
        menu();
        cin >> choice;
    }
    if(choice == 'p')
    {
        cout << "Enter the number of the item to purchase." << endl;
        cin >> usernum;
        if(usernum - 1 > storeInventory.size())
        {
            cout << "Item cannot be accessed." << endl;
            menu();
            cin >> choice;
        }
        if(p.getmoney() < storeInventory.at(usernum)->getValue())
        {
            cout << "You are too poor." << endl;
            menu();
            cin >> choice;
        }
        else
        {
            storeInventory.erase(storeInventory.begin()+usernum - 2);
            spentGold += storeInventory.at(usernum)->getValue();
            int playerMoney = p.getmoney() - storeInventory.at(usernum)->getValue();
			p.setmoney(playerMoney);
            cout << "You bought one " << storeInventory.at(usernum)->getName() << endl;
            menu();
            cin >> choice;
        }
    }
    else if(choice == 'q')
    {
        cout << "Gold spent: " << spentGold << endl;
        cout << "Gold remaining: " << p.getmoney() << endl;
    }
}
void Store::menu() const
{
    cout << "Press v to view the store inventory." << endl;
    cout << "Press p to purchase an item." << endl;
    cout << "Press q to leave the store." << endl;
}
void Store::printStore()
{
    for(int i = 0; i < storeInventory.size(); i++)
    {
	cout << i << ". " << storeInventory.at(i)->getName() << ' ' << storeInventory.at(i)->getValue()
        << " gold" << endl;
    }
}
void Store::fillStore(const string &input_file)
{
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

    while(fin >> type)
    {
		if (type == "Weapon")
		{
			fin >> itemName; fin >> val; fin >> boost;
			Weapon* temp = new Weapon(itemName, val, type, boost);
			storeInventory.push_back(temp);
			delete temp;
		}
		else if (type == "Chest")
		{
			fin >> itemName; fin >> val; fin >> boost;
			Gear* temp = new Gear(itemName, val, type, boost);
			storeInventory.push_back(temp);
			delete temp;
		}
		else if (type == "Helmet")
		{
			fin >> itemName; fin >> val; fin >> boost;
			Gear* temp = new Gear(itemName, val, type, boost);
			storeInventory.push_back(temp);
			delete temp;
		}
		else if (type == "Legs")
		{
			fin >> itemName; fin >> val; fin >> boost;
			Gear* temp = new Gear(itemName, val, type, boost);
			storeInventory.push_back(temp);
			delete temp;
		}
		else if (type == "Arms")
		{
			fin >> itemName; fin >> val; fin >> boost;
			Gear* temp = new Gear(itemName, val, type, boost);
			storeInventory.push_back(temp);
			delete temp;
		}
		else if (type == "Consumable")
		{
			fin >> itemName; fin >> val; fin >> boost;
			Consumable * temp = new Consumable(itemName, val, type, boost);
			storeInventory.push_back(temp);
		}
    }
    fin.close();
}
