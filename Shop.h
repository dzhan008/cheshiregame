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
<<<<<<< HEAD
        void Store(); //displays store and options
        void PrintStore(vector<Item> &v); //prints items in shop
        void PrintShopMenu(); //prints the menu for the shop
=======
        void PrintStore(vector<Item> &v); //prints items in shop
>>>>>>> origin/master
        int GoldRemaining(int &goldAmt); //calculates and returns remaining player gold
        void PlayerInventorySize(vector<int> playerInventory); //FIXME function will remove/add items within player inventory
    private:
        int pmoney = 50;
        int spentGold = 0;
};

#endif
