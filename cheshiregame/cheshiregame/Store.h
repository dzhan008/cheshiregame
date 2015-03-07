#ifndef STORE_H
#define STORE_H
#include "Items.h"
#include <string>
#include <vector>

class Store
{
    public:
        Store();
        void run();
        void menu() const;
        void printStore(); //prints items in shop
        void fillStore(const string &); 
    private:
        vector<Item> list;
};

#endif
