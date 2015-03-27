#ifndef STORE_H
#define STORE_H

#include "stdafx.h"
#include "Player.h"

#include <string>
#include <vector>

class Store
{
    public:
        Store();
        void run(player p);
        void menu() const;
        void printStore(); 
        void fillStore(const string &);
    private:
        vector<Item> storeInventory;
};

#endif
