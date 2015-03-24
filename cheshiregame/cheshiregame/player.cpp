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
	statpoints = 0;
	min_dmg = 1;
	max_dmg = 10;
	playerstats.resize(5);
	equipment.resize(6);
	inventory.resize(20);
}
player::player(string pName, string pJob, int health, int lvl, int amount, int statpts)
{
    playername = pName;
    maxHP = health;
    currHP = health;
    plevel  = lvl;
    pexp = amount;
	statpoints = statpts;
	min_dmg = 1 * lvl; //Change later
	max_dmg = 10 * lvl;
	playerstats.resize(5);
	equipment.resize(6);
	inventory.resize(inv_size);
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

/*Misc*/

void player::displayInfo()
{
    cout << playername << endl;
    cout << "Health: " << currHP << "/" << maxHP << endl;
    cout << "Stats" << endl;
    cout << "Strength:  " << playerstats.at(0) << endl;
    cout << "Agility:   " << playerstats.at(1) << endl;
    cout << "Vitality:  " << playerstats.at(2) << endl;
    cout << "Dexterity: " << playerstats.at(3) << endl;
    cout << "Luck:      " << playerstats.at(4) << endl;
}

void player::characterCreation()
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
	std::cout << "2. Thief" << std::endl;
	std::cout << "3. Magician" << std::endl;
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

void player::add_inventory(Item i) //Fix: What if the player's inventory is full?
{
	inventory.push_back(i);
}

void player::remove_inventory(string item)
{
	for (unsigned i = 0; i < inventory.size(); ++i)
	{
		if (inventory.at(i).get_name() == item)
		inventory.erase(inventory.begin() + i);
	}

}

void player::equip_slot(int i, Item x) //Fix so that you can replace the item if there is something in the slot
{
	equipment.at(i) = x;
	remove_inventory(x.get_name());
}

void player::remove_slot(int i)
{
	Item Nothing("Empty", 0);
	add_inventory(equipment.at(i));
	equipment.at(i) = Nothing; //Must fix so that the whole index is cleared
}

bool player::inventory_search(string itemName)
{
	for (unsigned i = 0; i < inventory.size(); ++i)
	{
		if (inventory.at(i).get_name() == itemName)
		{
			return true;
		}
	}
	return false;
}

void player::display_inventory()
{
	for (unsigned i = 0; i < inventory.size(); ++i)
	{
		std::cout << inventory.at(i).get_name() << std::endl;
	}
}

void player::display_equipment()
{
	for (unsigned i = 0; i < equipment.size(); ++i)
	{
		std::cout << equipment.at(i).get_name() << std::endl;
	}
}