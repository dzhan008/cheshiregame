#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

using namespace std;

//Forward declarations for circular dependencies
class Entity;
class Item;
class Gear;
class Weapon;
class Entity;
class Consumable;
class Ally;

class player
{
	private:

		int maxHP; //The maximum health points of the player.
		int currHP; //The current health the player has at the moment.
		int baseHP;
		int maxMP;
		int currMP;
		int baseMP;
		int plevel; //The player's current level.
		int pmoney; //The amount of money the player has.
		int pexp; //The amount of exp the player has.
		int statpoints; //The amount of stats points a player has. It will be added as the player levels up.
		int inv_size; //The current inventory size.
		int inv_max_size; //The maximum inventory size.
		int base_min_dmg;
		int base_max_dmg;
		int min_dmg; //The minimum damage the player can do to an enemy.
		int max_dmg; //The maximum damage the player can do to an enemy.
		int def; //The defense of the player.
		int base_def;
		int tRand();
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
		std::vector<Ally*> party; //The player's party.
		//vector<Quest> quest_list; //We might need this to display quests

		Gear* none;
		Weapon* none_wep;
		int randNumber();

    public:

		//Inventories changed from private to public to accomodate store for now.
		std::vector<Gear*> equipment; //0 = Head 1 = Torso 2 = Arms 3 = Legs
		std::vector<Weapon*> weapon; //0 = Right Hand 1 = Off/Left Hand HUEHUE
		std::vector<Item*> inventory; //For displaying items in Store

        //Constructor
        player();
		player(std::string pName, std::string pJob);
        player(std::string pName, std::string pJob, int health, int mana, int lvl, int exp, int statpts, int money);
		~player();

        /*Get Functions: Returns the respective value.*/
        int getMaxHP();
        int getHP();
		int getMaxMP();
		int getMP();
        int getlevel();
        int getmoney();
        int getexp();
		int getDef();
        int getStatPoints();
		int getMinDmg();
		int getMaxDmg();
		vector<int> getStats();
		bool calculateCrit();
		bool calculateAccuracy(Entity* e);

		/*For Inventories*/
		int getItemSize();
		int getGearSize();
		int getWepSize();
		int getInvSize();

		bool isDefending();

        std::string getname();
        std::string getjob();

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
		void display_con();
		void mod_stats();
		void stat_progression();
		void add_points(int& points);
		bool input_stats();

		bool add_exp(int x); //returns true if leveled up

		/*Character Creation*/
		void declare_job(std::string input);

		Item* inventory_search(string itemName);

		bool add_inventory(Item* i);
		void remove_inventory(string item);
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
		void display_party();
		void add_member(Ally* member);
		std::vector<Ally*> get_party();
		int calculateDamage(Entity enemy, bool defend);
};

#endif
