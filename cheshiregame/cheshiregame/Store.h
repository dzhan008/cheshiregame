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
		//Constructors
        Store();
        ~Store();
		void fillStore(const string &);
		//Store mutator functions
		void menu() const;
        void run(player* p);
        void printStore(player*); 
		void purchaseItem(const unsigned, player*);
		void sellItem(const unsigned, player*);
		void storeUpdate();
    private:
		//Inventories
        vector<Item*> storeInventory; 
		vector<Gear*> gearInv; 
		vector<Weapon*> weapInv; 
		vector<Consumable*> potInv; 

		int numHealthPots;
		int numManaPots;

		bool healthPotExists(const vector<Item*>&);
		bool manaPotExists(const vector<Item*>&);
};

#endif
