#ifndef STORE_H
#define STORE_H

#include "Player.h"
#include "Item.h"
#include "Gear.h"
#include "Weapon.h"
#include "Consumable.h"

#include <string>
#include <vector>

class Store
{
    public:
        Store();
        ~Store();
        void run(player* p);
        void menu() const;
        void printStore(); 
        void fillStore(const string &);
		void purchaseItem(const unsigned, player*);
		void sellItem(const unsigned, player*);
		void storeUpdate();
    private:
        vector<Item*> storeInventory; //For printing out all contents of store
		vector<Gear*> gearInv; //Stores all gear
		vector<Weapon*> weapInv; //Stores all weapons
		vector<Consumable*> potInv; //Stores all consumables
		int numHealthPots;
		int numManaPots;

		bool healthPotExists(const vector<Item*>&);
		bool manaPotExists(const vector<Item*>&);
};

#endif
