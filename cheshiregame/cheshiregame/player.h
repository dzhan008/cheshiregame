#ifndef PLAYER_H
#define PLAYER_H

#include "stdafx.h"
#include <vector>
#include <string>


//Forward declarations for circular dependencies
class Item;
class entity;

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
		int min_dmg; //The minimum damage the player can do to an enemy.
		int max_dmg; //The maximum damage the player can do to an enemy.
		int def; //The defense of the player. 

		int maxexp; //The maximum amount of exp the player has. May be put into another class.
		std::string playername; //The player's name.
		std::string playerjob; //The player's job.
		std::vector<int> playerstats; //Current stats for the player.
		std::vector<entity> party; //The player's party.
		//vector<Quest> quest_list; //We might need this to display quests
		std::vector<Item*> equipment; //0 = Head 1 = Torso 2 = Leggings 3 = Shoes 4 = Gloves 5 = Main Hand 6 = Off Hand
		std::vector<Item*> inventory; //CHANGE TO ITEMS LATER

		Item* none;
		int randNumber();

    public:
    
        //Constructor
        player();
        player(std::string pName, std::string pJob, int health, int lvl, int amount, int statpts);
		~player();

        /*Get Functions: Returns the respective value.*/
        int getMaxHP();
        int getHP();
        int getlevel();
        int getmoney();
        int getexp();
	int getInvSize();
	int getDef();

        std::string getname();
    
        /*Set Functions: Sets every value into a certain number.*/
        void setHP(int health); //Changes currHP to the updated hp value after a certain instance.
        void setlevel(int&level);
        void setmoney(int& money);
        void setexp(int expx1);
        void setstats(std::vector<int>& stats);
		void set_min_dmg(int dmg);
		void set_max_dmg(int dmg);
		void set_def(int idef);
		void setname(std::string name);
		void setjob(std::string job);

        /*Stat Functions*/
        void displayInfo();
		void display_stats();
		void mod_stats();
		void stat_progression();
		void add_points(int& points);
		bool input_stats();

		void level_up();

		/*Character Creation*/
		void characterCreation();
		void declare_job(std::string input);

		/*Inventory Functions*/
		bool add_inventory(Item* i);
		void remove_inventory(std::string item);
		void equip_slot(int i, const Item* x); //CHANGE x TO ITEM LATER
		void remove_slot(int i);
		void display_inventory();
		void display_equipment();

		int inventory_search(std::string itemName);

		/*Party Functions*/
	int calculateDamage(Entity enemy, bool defend);
};

#endif
