#include "stdafx.h"

#include <iostream>
#include <vector>


using namespace std;

/*Get Functions*/

player::player(){
    playername = "Player";
    maxHP = 1;
    currHP = 1;
    plevel = 1;
    pexp = 0;
	maxexp = 100;
	statpoints = 0;
	inv_size = 0;
	min_dmg = 1;
	max_dmg = 10;
	playerstats.resize(5);
	equipment.resize(7);

	none = new Item("None", -1);
	for (unsigned i = 0; i < equipment.size(); ++i)
	{
		equipment.at(i) = none;
	}
}
player::player(string pName, string pJob, int health, int lvl, int amount, int statpts)
{
    playername = pName;
    maxHP = health;
    currHP = health;
    plevel  = lvl;
    pexp = amount;
	maxexp = amount;
	statpoints = statpts;
	inv_size = 20;
	min_dmg = 1 * lvl; //Change later
	max_dmg = 10 * lvl;
	playerstats.resize(5);
	equipment.resize(7);

	none = new Item("None", -1);
	for (unsigned i = 0; i < equipment.size(); ++i)
	{
		equipment.at(i) = none;
	}
}

int player::getMaxHP()
{
    return maxHP;
}
int player::getHP()
{
    return currHP;
}

int player::getlevel()
{
    return plevel;
}

int player::getmoney()
{
    return pmoney;
}

int player::getexp()
{
    return pexp;
}

int player::getInvSize()
{
	return inv_size;
}

string player::getname()
{
    return playername;
}

/*Set Functions*/
void player::setHP(int health)
{
    currHP = health;
}

void player::setlevel(int& level)
{
    plevel = level;
}

void player::setmoney(int& money)
{
    pmoney = money;
}

void player::setexp(int expx)
{
    pexp = expx;
}

void player::setstats(vector<int>& stats)
{
    playerstats.at(0) += stats.at(0);
    playerstats.at(1) += stats.at(1);
    playerstats.at(2) += stats.at(2);
    playerstats.at(3) += stats.at(3);
    playerstats.at(4) += stats.at(4);
}

void player::setname(string name)
{
	playername = name;
}

void player::setjob(string job)
{
	playerjob = job;
}

void player::set_min_dmg(int dmg)
{
	min_dmg = dmg;
}

void player::set_max_dmg(int dmg)
{
	max_dmg = dmg;
}

void player::set_def(int idef)
{
	def = idef;
}

/*Stat Functions*/

void player::displayInfo()
{
    cout << playername << endl;
    cout << "Health: " << currHP << "/" << maxHP << endl;

}

void player::display_stats()
{
	cout << "Stats" << endl;
	cout << "Strength:  " << playerstats.at(0) << endl;
	cout << "Agility:   " << playerstats.at(1) << endl;
	cout << "Vitality:  " << playerstats.at(2) << endl;
	cout << "Dexterity: " << playerstats.at(3) << endl;
	cout << "Luck:      " << playerstats.at(4) << endl;
}

void player::mod_stats()
{
	std::string choice;

	display_stats();

	if (statpoints > 0)
	{
		std::cout << "You have " << statpoints << " remaining." << std::endl;
		std::cout << "Would you like to distribute these points?" << std::endl;
		std::cin >> choice;
		while (choice != "No" || "no" || "N" || "n")
		{
			if (choice == "Yes" || "Y" || "y" || "yes")
			{
				stat_progression();
			}
			else if (choice == "No" || "no" || "N" || "n")
			{ }
			else
			{
				std::cout << "Invalid input. Please enter your choice again." << std::endl;
			}
		}
	}
	else
	{
		std::cout << "You have 0 statpoints remaining." << std::endl;
	}
}

void player::stat_progression()
{
	std::string input;
	bool quit = true;

	while (statpoints > 0)
	{
		display_stats();
		std::cout << "You have " << statpoints << " remaining." << std::endl;
		std::cout << "Type in the stat you want to add in or type 'q' to quit." << std::endl;
		std::cin >> input;

		quit = input_stats();

		if (!quit)
		{
			return;
		}
	}
}

bool player::input_stats()
{
	std::string stat;
	int points;

	std::cin >> stat;

	if (stat == "Str" || stat == "Strength" || stat == "str" || stat == "strength") //Add points to appropriate stat
	{
		add_points(points);
		playerstats.at(0) += points;
	}
	else if (stat == "Agi" || stat == "Agility" || stat == "agi" || stat == "agility")
	{
		add_points(points);
		playerstats.at(1) += points;
	}
	else if (stat == "Vit" || stat == "Vitality" || stat == "vit" || stat == "vitality")
	{
		add_points(points);;
		playerstats.at(2) += points;
	}
	else if (stat == "Dex" || stat == "Dexterity" || stat == "dex" || stat == "dexterity")
	{
		add_points(points);
		playerstats.at(3) += points;
	}
	else if (stat == "Luk" || stat == "Luck" || stat == "luk" || stat == "luck")
	{
		add_points(points);
		playerstats.at(4) += points;
	}
	else if (stat == "q")
	{
		return false;
	}
	else
	{
		cout << "Invalid stat type." << endl;
		input_stats();
	}
	statpoints -= points;
	return true;
}

void player::add_points(int& points)
{
	cout << "How many points?" << endl;
	cin >> points;
	if (points > statpoints)
	{
		cout << "You do not have enough points to do this." << endl;
		add_points(points);
	}
	else if (points < 0)
	{
		cout << "You can't add in negative points, silly." << endl;
		add_points(points);
	}
}

void player::level_up() //TO DO: Change exp scaling per 10 levels
{
	plevel += 1;
	pexp = 0;
	maxexp += 100;
}

/*Scenario to replace instead of this:
You wake up dazed, seeing only blurriness around you.
Your head is throbbing, and your mind is fogged.
You sit up slowly, trying to recollect yourself.
You can't seem to remember much. It is as if your mind
become a blank slate. You try to remember your name:
(after player enters name)
Well at least you did not forget who you were. You turn
around to look at your surroundings. Beside you lies:
1. A rusted sword.
2. A dull dagger.
3. A wooden staff.
(depending on the choice, there will be something said about the player's job)
-You pick up the item and realize you're in the middle of the forest. You then
try to find your way to town.*/

void player::characterCreation() //TO DO: Move the text part into scene.
{
	string input;
	int jobnum;

	std::cout << "Welcome to Cheshire's Game!" << std::endl;
	std::cout << "Before we start, let us create your character." << std::endl;
	std::cout << "What is your name?" << std::endl;
	std::cin >> input;
	setname(input);
	std::cout << "Please select the number that corresponds to your job." << std::endl;
	std::cout << "1. Swordsman" << std::endl;
	std::cout << "2. Magician" << std::endl;
	std::cout << "3. Thief" << std::endl;
	//OUTPUT JOBS HERE

	while (playerjob == "")
	{
		std::cin >> input;
		declare_job(input);
		if (playerjob == "")
		{
			std::cout << "Invalid Job. Please pick again." << std::endl;
		}
	}

	std::cout << "Okay! Let's "; //PUT PLAYER TO TOWN IDUNNO

}

void player::declare_job(string input)
{
	if (input == "1")
	{
		playerjob = "Swordsman";
	}
	else if (input == "2")
	{
		playerjob = "Magician";
	}
	else if (input == "3")
	{
		playerjob = "Thief";
	}
}

/*Inventory Functions*/
bool player::add_inventory(Item* i) 
{
	if (inv_size > inventory.size())
	{
		inventory.push_back(i);
		return true;
	}
	return false;
}

void player::remove_inventory(string item)
{
	for (unsigned i = 0; i < inventory.size(); ++i)
	{
		if (inventory.at(i)->getName() == item)
		{
			delete inventory.at(i); //ISSUE: We need to cater to two instances: When we only want to delete an item OR replace an item
			inventory.erase(inventory.begin() + i);
		}
	}

}

void player::equip_slot(int i, Item* x) //Fix so that you can replace the item if there is something in the slot
{
	Item* temp = equipment.at(i); //Test plox
	equipment.at(i) = x;
	inventory.at(inventory_search(x->getName())) = NULL;
	remove_inventory(x->getName());
	if (temp->getName() != "None")
	add_inventory(temp);
}

void player::remove_slot(int i)
{
	Item empty;

	if (!add_inventory(equipment.at(i)))
	{
		std::cout << "Your inventory is too full." << std::endl;
		return;
	}
	equipment.at(i) = none; //Must fix so that the whole index is cleared
}

int player::inventory_search(string itemName)
{
	for (unsigned i = 0; i < inventory.size(); ++i)
	{
		if (inventory.at(i)->getName() == itemName)
		{
			return i; //Or true.
		}
	}
	return -1; //Or false.
}

void player::display_inventory()
{
	std::string line = "-----------------------------------------------------";
	std::cout << line << std::endl;
	for (unsigned i = 0; i < inventory.size(); ++i)
	{
		std::cout << inventory.at(i)->getName() << "  ";
		if (i % 3 == 0 && i != 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl << line << std::endl;
}

void player::display_equipment()
{
	std::cout << "Head: " << equipment.at(0)->getName() << std::endl;
	std::cout << "Torso: " << equipment.at(1)->getName() << std::endl;
	std::cout << "Leggings: " << equipment.at(2)->getName() << std::endl;
	std::cout << "Shoes: " << equipment.at(3)->getName() << std::endl;
	std::cout << "Gloves: " << equipment.at(4)->getName() << std::endl;
	std::cout << "Main Hand: " << equipment.at(5)->getName() << std::endl;
	std::cout << "Off Hand: " << equipment.at(6)->getName() << std::endl;
}