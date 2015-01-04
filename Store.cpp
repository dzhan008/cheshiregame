#include <iostream>
#include <string>
#include "shop.h"
#include "inventory.h"
#include "items.h"

using namespace std;

//Will call upon other classes and include more items later

int main()
{
    vector<string> userInventory(5); //Temp inventory space
    int playerGold = 50; //Temp specified amount 
    int spentGold = 0;
    int choice = 0;
    int usernum;
    
    vector<Item> shopItems(2); // Temp items
    shopItems.at(0).name = "Rusty Shiv";
    shopItems.at(0).value = 10;
    shopItems.at(1).name = "Frayed Leather Armor";
    shopItems.at(1).value = 20;
    
    cout << "Welcome to Chesire's Store, feel free to browse our wares." << endl;
    cout << "You have " << playerGold << " gold remaining." << endl;
    
    cout << "Press v to view the store inventory." << endl;
    cout << "Press p to purchase an item." << endl;
    cout << "Press q to leave the store." << endl;
    cin >> choice;
    
    //Later will develop simpler way of removing and adding items to and from inventory
    while(choice != 'q')
    {
        if(choice == 'v')
        {
            PrintStore(vector<Item> &shopItems);
        }
        else if (choice == 'p')
        {
            cout << "Enter the number of the item you would like to purchase." << endl;
            cin >> usernum;
            if(usernum == 0)
            {
                shopItems.erase(0);
                spentGold += shopItems.at(0).value;
                playerGold -= shopItems.at(0).value;
            }
            else if(usernum == 1)
            {
                shopItems.erase(1);
                spentGold += shopItems.at(1).value;
                playerGold -= shopItems.at(1).value;
            }
        }
    }
    else if(choice == 'q')
    {
        cout << "Thanks for visiting!" << endl; 
        cout << "You spent " << spentGold << " gold." << endl;
        cout << "You have " << playerGold << " gold remaining." << endl;
    }
   
    

    return 0;
}
