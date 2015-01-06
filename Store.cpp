#include <iostream>
#include <string>
#include "Shop.h"
//#include "Inventory.h"
//#include "Items.h"

using namespace std;

int main()
{
    // vector<string> userInventory; // Not needed for prototype 
    int pmoney = 50; //Temp specified amount 
    int spentGold = 0;
    int choice = 0;
    int usernum;
    
    vector<Item> shopItems(2); // Temp items
    shopItems.at(0).name = "Rusty Shiv";
    shopItems.at(0).value = 10;
    shopItems.at(1).name = "Frayed Leather Armor";
    shopItems.at(1).value = 20;
    shopItems.at(2).name = "Legendary Ghostblade";
    shopItems.at(2).value = 1000;
    
    cout << "Welcome to Chesire's Store, feel free to browse our wares." << endl;
    cout << "You have " << pmoney << " gold remaining." << endl;
    
    cout << "Press v to view the store inventory." << endl;
    cout << "Press p to purchase an item." << endl;
    cout << "Press q to leave the store." << endl;
    cin >> choice;
    
    if(choice == 'v')
    {
        PrintStore(vector<Item> &shopItems);
    }
    if (choice == 'p')
    {
        cout << "Enter the number of the item you would like to purchase." << endl;
        cin >> usernum;
        if(usernum == 0)
        {
            shopItems.erase(0); // .erase is inefficient if store inventory is large. Change after prototype.
            spentGold += shopItems.at(0).value;
            pmoney -= shopItems.at(0).value;
            cout << "You bought one Rusty Shiv!" << endl;
        }
        if(usernum == 1)
        {
            shopItems.erase(1);
            spentGold += shopItems.at(1).value;
            pmoney -= shopItems.at(1).value;
            cout << "You bought one Frayed Leather Armor!" << endl;
        }
        if(usernum == 2)
        {
            cout << "Not enough gold, ya poor bastard." << endl;
        }
    }
    else if(choice == 'q')
    {
        cout << "Thanks for visiting!" << endl; 
        cout << "You spent " << spentGold << " gold." << endl;
        cout << "You have " << pmoney << " gold remaining." << endl;
    }
   
    

    return 0;
}
