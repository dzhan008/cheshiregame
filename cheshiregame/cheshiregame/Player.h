#ifndef PLAYER_H
#define PLAYER_H

#include "stdafx.h"
#include <vector>
#include <string>


//Forward declarations for circular dependencies
class Item;
class Gear;
class Weapon;
class Entity;
class Consumable;


class player
{
	private:

		int maxHP; //The maximum health points of the player.
		int currHP; //The current health the player has at the moment.
		int plevel; //The player's current level.
		int pmoney; //The amount of money the player has.
		int pexp; //The amount of exp the player has.
		int statpoints; //The amount of stats points a player has. It will be added as the player levels up.
		int inv_size; //The current inventory size.
		int inv_max_size; //The maximum inventory size.
		int min_dmg; //The minimum damage the player can do to an enemy.
		int max_dmg; //The maximum damage the player can do to an enemy.
		int def; //The defense of the player.
		bool defending;

		/*For the three different inventories*/
		int item_size;
		int gear_size;
		int wep_size;
		int con_size;

		int maxexp; //The maximum amount of exp the player has. May be put into another class.
		std::string playername; //The player's name.
		std::string playerjob; //The player's job.
		std::vector<int> playerstats; //Current stats for the player.
		std::vector<Entity> party; //The player's party.
		//vector<Quest> quest_list; //We might need this to display quests
		std::vector<Gear*> equipment; //0 = Head 1 = Torso 2 = Arms 3 = Legs
		std::vector<Weapon*> weapon; //0 = Main Hand 1 = Off Hand
		std::vector<Item*> inventory; //CHANGE TO ITEMS LATER
		std::vector<Consumable*> con_inv;
		std::vector<Gear*> gear_inv;
		std::vector<Weapon*> wep_inv;

		Gear* none;
		Weapon* none_wep;
		int randNumber();

    public:
    
        //Constructor
        player();
		player(std::string pName, std::string pJob);
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

		/*For Inventories*/
		int getItemSize();
		int getGearSize();
		int getWepSize();

		bool isDefending();

        std::string getname();
    
        /*Set Functions: Sets every value into a certain number.*/
        void setHP(int health); //Changes currHP to the updated hp value after a certain instance.
        void setlevel(int&level);
        void setmoney(int money);
        void setexp(int expx1);
        void setstats(std::vector<int>& stats);
		void set_min_dmg(int dmg);
		void set_max_dmg(int dmg);
		void set_def(int idef);
		void setDefending(bool b);
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

		/*Inventory Functions*/ //TO DO: Templatize the inventory into a new class.
		bool add_inventory(Item* i);
		void remove_inventory(std::string item);
		Item* inventory_search(std::string itemName);

		bool add_con(Consumable* i);
		void remove_con(std::string item);
		Consumable* con_search(std::string itemName);

		bool add_gear(Gear* i);
		void remove_gear(std::string item);
		Gear* gear_search(std::string itemName);

		bool add_wep(Weapon* i);
		void remove_wep(std::string item);
		Weapon* wep_search(std::string itemName);

		void display_inventory();

		/*Equipment Functions*/
		void equip_gear(int i, const Gear* x);
		void remove_gear(int i);

		void equip_wep(int i, const Weapon* x);
		void remove_wep(int i);

		void display_equipment();

		int find_slot(std::string gear);

		void update_player();

		/*Party Functions*/
		int calculateDamage(Entity enemy, bool defend);
};

#endif