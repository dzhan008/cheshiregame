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
    //bool soldOut;
};

class Shop
{
    public:
        void PrintStore(vector<Item> &v); //prints items in shop
        int GoldRemaining(int &goldAmt); //calculates and returns remaining player gold
        void PlayerInventorySize(vector<int> playerInventory); //FIXME function will remove/add items within player inventory
    private:
        int pmoney;
};

#endif
