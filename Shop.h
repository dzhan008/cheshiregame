#ifndef Shop_H
#define Shop_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Each object in the store will be of type Item as defined below
struct Item
{
    string name;
    int value;
};

//This function handles the actual printing of each item's name and gold value
void StoreItem(Item object)
{
    cout << int i << object.name << ", Value: " << object.value << endl;
    //ISSUE: does redeclaring i cause a problem?
}

//This function iterates through vector shopItems to print each item of type Item
void PrintStore(vector<Item> &shopItems)
{
    for(int i = 0; i < shopItems.size(); i++)
    {
        StoreItem(shopItems.at(i));
    }
}

class Shop
{
    public:
        void PrintStore(vector<Item> &shopItems) //prints items in shop
        int GoldRemaining(int &goldAmt); //calculates and returns remaining player gold
        void PlayerInventorySize(vector<int> playerInventory) //FIXME function will remove/add items within player inventory
    private:
        int pmoney;
};

#endif
