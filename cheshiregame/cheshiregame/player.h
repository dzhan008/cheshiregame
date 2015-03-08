#ifndef PLAYER_H
#define PLAYER_H

#include "stdafx.h"
#include <vector>
#include <string>

using namespace std;

class Item;

class player
{
	private:

		int maxHP; //The maximum health points of the player.
		int currHP; //The current health the player has at the moment.
		int plevel; //The player's current level.
		int pmoney; //The amount of money the player has.
		int pexp; //The amount of exp the player has.
		int statpoints; //The amount of stats points a player has. It will be added as the player levels up.
		int inv_size; //The maximum inventory size.
		//int maxexp; //The maximum amount of exp the player has. May be put into another class.
		string playername; //The player's name.
		string playerjob; //The player's job.
		vector<int> playerstats; //Current stats for the player.
		vector<Item> equipment; //0 = Head 1 = Torso 2 = Leggings 3 = Shoes 4 = Gloves 5 = LeftH 6 = RightH
		vector<Item> inventory; //CHANGE TO ITEMS LATER

    public:
    
        //Constructor
        player();
        player(string pName, string pJob, int health, int lvl, int amount, int statpts);

        /*Get Functions: Returns the respective value.*/
        int getMaxHP();
        int getHP();
        int getlevel();
        int getmoney();
        int getexp();
		int getInvSize();

        string getname();
    
        /*Set Functions: Sets every value into a certain number.*/
        void setHP(int health); //Changes currHP to the updated hp value after a certain instance.
        void setlevel(int&level);
        void setmoney(int& money);
        void setexp(int expx1);
        void setstats(vector<int>& stats);
		
		void setname(string name);
		void setjob(string job);
        /*Misc*/
        void displayInfo();
		void characterCreation();
		void declare_job(string input);

		/*Inventory Functions that need to be put into a new class*/
		void add_inventory(Item i);
		void remove_inventory(string item);
		void equip_slot(int i, Item x); //CHANGE x TO ITEM LATER
		void remove_slot(int i);
		
		bool inventory_search(string itemName);

		void display_inventory();
		void display_equipment();
};

#endif
