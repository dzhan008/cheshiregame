#include <iostream>
#include <string>
#include <vector>
#include "Shop.h"
//#include "Inventory.h"
//#include "Items.h"

using namespace std;

void PrintShopMenu();
void PrintStore(vector<Item> &v);

int pmoney = 50; //Temp specified amount
int spentGold = 0;
int choice;

void Shop::Store()
{
    // vector<string> userInventory; // Not needed for prototype

    vector<Item> shopItems(3); // Temp items
    shopItems.at(0).name = "Rusty Shiv";
    shopItems.at(0).value = 10;
    shopItems.at(1).name = "Frayed Leather Armor";
    shopItems.at(1).value = 20;
    shopItems.at(2).name = "Legendary Ghostblade";
    shopItems.at(2).value = 1000;

    cout << "Welcome to Chesire's Store, come and browse our wares... if you dare." << endl << endl;
    PrintShopMenu();
    //Generalize this function so it works for any shop. AFTER PROTOTYPE.


    while(choice != 7)
    {
        if(choice == 5)
        {
            PrintStore(shopItems);
            PrintShopMenu();
        }
        if (choice == 6)
        {
            cout << "Enter the number of the item you would like to purchase." << endl;
            cin >> choice;
            if(choice > shopItems.size())
            {
                cout << "Invalid choice." << endl;
                PrintShopMenu();
            }
            else if(pmoney >= shopItems.at(choice - 1).value)
            {
                cout << "You bought one " << shopItems.at(choice - 1).name << "!" << endl;
                spentGold += shopItems.at(choice - 1).value;
                pmoney -= shopItems.at(choice - 1).value;
                shopItems.erase(shopItems.begin()+(choice - 1));
                PrintShopMenu();
            }
            else
            {
                cout << "Not enough gold, ya poor bastard." << endl;
                PrintShopMenu();
            }

        }
        else
        {
            cout << "Invalid selection." << endl;
            cin >> choice;
        }
    }

    cout << "Thanks for visiting!" << endl;
    cout << "You spent " << spentGold << " gold." << endl;
    cout << "You have " << pmoney << " gold remaining." << endl;
}

void Shop::PrintShopMenu()
{
    cout << "You have " << pmoney << " gold remaining." << endl;

    cout << "Press 5 to view the store inventory." << endl;
    cout << "Press 6 to purchase an item." << endl;
    cout << "Press 7 to leave the store." << endl << endl;
    cin >> choice;
    cout << endl;
}

void Shop::PrintStore(vector<Item> &v)
{
    cout << "All Items:" << endl << "----------------------" << endl;
    for(int i = 0; i < v.size(); i++)
    {
        cout << "Item " << i + 1 << ": " << v.at(i).name << ", Value: " << v.at(i).value << endl;
    }
    cout << endl;
    return;
}
