#include "stdafx.h"

#include <iostream>
#include <string>
#include "Store.h"
#include "Items.h"
#include <fstream>

using namespace std;

Store::Store()
{
    vector<Item> list;
}
void Store::run()
{
    int spentGold = 0;
    char choice;
    int usernum;
    cout << "Welcome to Chesire's Store." << endl;
    cout << "Gold remaining: " << player.gold << endl;
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
        if(usernum - 1 > list.size())
        {
            cout << "Item cannot be accessed." << endl;
            menu();
            cin >> choice;
        }
        if(player.gold < list.at(i).value)
        {
            cout << "You are too poor." << endl;
            menu();
            cin >> choice;
        }
        else
        {
            list.erase(i);
            spentGold += list.at(i).value;
            player.gold -= list.at(i).value;
            cout << "You bought one " << list.at(i).name << endl;
            menu();
            cin >> choice;
        }
    }
    else if(choice == 'q')
    {
        cout << "Gold spent: " << spentGold << endl;
        cout << "Gold remaining: " << player.gold << endl;
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
    for(int i = 0; i < list.size(); i++)
    {
        cout << i << ". " << list.at(i).name << ' ' << lists.at(i).value 
        << " gold" << endl;
    }
}
void Store::fillStore(const string &input_file)
{
    ifstream fin;               
    string itemName;
    int val;
    fin.open(input_file.c_str());
    while(fin >> item && fin >> val)
    {
        list.push_back(Item(itemName, val));
    }
    fin.close();
}
