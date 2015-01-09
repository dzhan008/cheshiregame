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
        void Store(); //displays store and options
        void PrintStore(vector<Item> &v); //prints items in shop
        void PrintShopMenu(); //prints the menu for the shop

    private:
        int pmoney = 50;
        int spentGold = 0;
};

#endif
