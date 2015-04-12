#ifndef ALLY_H_
#define ALLY_H_

#include <string>
#include <vector>

using namespace std;

class Item;
class Entity;

class Ally{
	private:
		int maxHP; //The maximum health points of the ally.
		int currHP; //The current health the ally has at the moment.
		int level; //The ally's current level.
		int exp; //The amount of exp the ally has.
		int min_dmg; //The minimum damage the ally can do to an enemy.
		int max_dmg; //The maximum damage the ally can do to an enemy.
		int def; //The defense of the ally. 
		bool defending;

		string allyname; //The ally's name.
		string allyjob; //The ally's job.
		vector<int> allystats; //Current stats for the ally.
		vector<Item> equipment; //0 = Head 1 = Torso 2 = Leggings 3 = Shoes 4 = Gloves 5 = LeftH 6 = RightH

	public:
		//Constructor
		Ally();
		Ally(string aName, string aJob, int health, int lvl, int xp);

		/*Get Functions: Returns the respective value.*/
		int getMaxHP();
		int getHP();
		int getlevel();
		int getexp();
		int getDef();
		int calculateDamage(Entity enemy, bool defend);
		bool isDefending();

		string getname();

		/*Set Functions: Sets every value into a certain number.*/
		void setHP(int health); //Changes currHP to the updated hp value after a certain instance.
		void setlevel(int lvl);
		void setexp(int expx1);
		void setstats(vector<int>& stats);
		void set_min_dmg(int dmg);
		void set_max_dmg(int dmg);
		void set_def(int idef);
		void setDefending(bool b);
		
		void setname(string name);
		void setjob(string job);

		/*Misc*/
		void displayInfo();
		void display_equipment();

	private:
		int randNumber();
};

#endif
