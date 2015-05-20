#include "stdafx.h"

#include <iostream>
#include <vector>


using namespace std;

/*Constructors*/

player::player(){
    playername = "Player";
	baseHP = 20;
    maxHP = 20;
    currHP = 20;
	baseMP = 10;
	maxMP = 10;
	currMP = 10;
    plevel = 1;
    pexp = 0;
	maxexp = 50;
	statpoints = 0;
	defending = false;

	base_min_dmg = 1;
	base_max_dmg = 10;
	base_def = 0;

	def = 0;
	min_dmg = 1; //Change later
	max_dmg = 10;

	inv_size = 0;
	inv_max_size = 20;
	item_size = 0;
	gear_size = 0;
	wep_size = 0;

	playerstats.resize(5);
	equipment.resize(4);
	weapon.resize(2);

	none = new Gear("None", "None", -1);
	none_wep = new Weapon("None", "None", 0, 0);
	for (unsigned i = 0; i < equipment.size(); ++i)
	{
		equipment.at(i) = none;
	}
	for (unsigned i = 0; i < weapon.size(); ++i)
	{
		weapon.at(i) = none_wep;
	}

	playerstats.at(0) = 1;
	playerstats.at(1) = 1;
	playerstats.at(2) = 1;
	playerstats.at(3) = 1;
	playerstats.at(4) = 1;

	update_player();
}

player::player(std::string pName, std::string pJob)
	:playername(pName), playerjob(pJob)
{
	baseHP = 20;
	maxHP = 20;
	currHP = 20;
	baseMP = 10;
	maxMP = 10;
	currMP = 10;
	plevel = 1;
	pexp = 0;
	maxexp = 50;
	statpoints = 0;
	defending = false;

	base_min_dmg = 1;
	base_max_dmg = 10;
	base_def = 0;

	def = 0;
	min_dmg = 1; //Change later
	max_dmg = 10;

	pmoney = 0;

	playerstats.resize(5);
	equipment.resize(4);
	weapon.resize(2);

	inv_size = 0;
	inv_max_size = 20;
	item_size = 0;
	gear_size = 0;
	wep_size = 0;

	none = new Gear("None", "None", -1); //Default Item named none
	none_wep = new Weapon("None", "None", 0, 0);

	for (unsigned i = 0; i < equipment.size(); ++i)
	{
		equipment.at(i) = none;
	}
	for (unsigned i = 0; i < weapon.size(); ++i)
	{
		weapon.at(i) = none_wep;
	}
	playerstats.at(0) = 1;
	playerstats.at(1) = 1;
	playerstats.at(2) = 1;
	playerstats.at(3) = 1;
	playerstats.at(4) = 1;

	update_player();
}

player::player(string pName, string pJob, int health, int mana, int lvl, int exp, int statpts, int money)
{
    playername = pName;
    baseHP = health;
	maxHP = health;
    currHP = health;
	baseMP = mana;
	maxMP = mana;
	currMP = mana;
    plevel  = lvl;
    pexp = exp;
	maxexp = exp;
	statpoints = statpts;

	defending = false;

	base_min_dmg = 1;
	base_max_dmg = 10;
	base_def = 0;

	def = 0;
	min_dmg = 1; //Change later
	max_dmg = 10;

	pmoney = money;

	playerstats.resize(5);
	equipment.resize(4);
	weapon.resize(2);

	inv_size = 0;
	inv_max_size = 20;
	item_size = 0;
	gear_size = 0;
	wep_size = 0;

	none = new Gear("None", "None", -1); //Default Item named none
	none_wep = new Weapon("None", "None", 0, 0);

	for (unsigned i = 0; i < equipment.size(); ++i)
	{
		equipment.at(i) = none;
	}
	for (unsigned i = 0; i < weapon.size(); ++i)
	{
		weapon.at(i) = none_wep;
	}

	playerstats.at(0) = 1;
	playerstats.at(1) = 1;
	playerstats.at(2) = 1;
	playerstats.at(3) = 1;
	playerstats.at(4) = 1;

	update_player();
}

player::~player()
{
	for (unsigned i = 0; i < inventory.size(); ++i)
	{
		inventory.at(i) = NULL;
	}

	for (unsigned i = 0; i < gear_inv.size(); ++i)
	{
		gear_inv.at(i) = NULL;
	}

	for (unsigned i = 0; i < wep_inv.size(); ++i)
	{
		wep_inv.at(i) = NULL;
	}

	for (unsigned i = 0; i < equipment.size(); ++i)
	{
		equipment.at(i) = NULL;
	}
	for (unsigned i = 0; i < weapon.size(); ++i)
	{
		weapon.at(i) = NULL;
	}

	//	delete none;

}

/*Get Functions*/

int player::getMaxHP()
{
    return maxHP;
}
int player::getHP()
{
    return currHP;
}
int player::getMaxMP()
{
	return maxMP;
}
int player::getMP()
{
	return currMP;
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

int player::getMaxDmg()
{
	return max_dmg;
}

int player::getMinDmg()
{
	return min_dmg;
}

int player::getItemSize()
{
	return item_size;
}

int player::getInvSize()
{
	return inv_size;
}

int player::getGearSize()
{
	return gear_size;
}

int player::getWepSize()
{
	return wep_size;
}

string player::getname()
{
    return playername;
}

string player::getjob()
{
    return playerjob;
}

int player::getDef(){
	return def;
}

int player::getStatPoints() {
    return statpoints;
}

vector<int> player::getStats(){
	return playerstats;
}

bool player::calculateCrit(){
	double temp = 2 + (playerstats.at(4) * .13);
	int x = tRand();
	if (x < temp){
		return true;
	}
	return false;
}

bool player::calculateAccuracy(Entity* e){
	vector<int> eStats = e->getStats();
	double temp = (playerstats.at(3) / eStats.at(1)) * 100;
	int x = tRand();
	if (temp > 100)
	{
		temp = 80;
	}
	if (temp < 30){
		temp = 30;
	}
	if (x < temp){
		return true;
	}
	else{
		return false;
	}
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

void player::setmoney(int money)
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

	update_player();
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

void player::setDefending(bool b){
	defending = b;
}

/*Stat Functions*/

void player::displayInfo()
{
    cout << playername << endl;
	cout << "Level: " << plevel << endl;
	cout << "Health: " << currHP << "/" << maxHP << endl;
	cout << "Exp: " << pexp << "/" << maxexp << endl;

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

void player::update_player(){
	int str_val = playerstats.at(0) / 5; //For every 5 str stat add 1 more damage to the player
	int def_val = playerstats.at(2) / 10; //For every 10 vit add 1 more def
	int hp_val = playerstats.at(2) / 3; //For every 3 vit add 1 more hp	
	int wep_val = 0;
	int gear_val = 0;
	for (int i = 0; i < weapon.size(); ++i)
	{
		wep_val += weapon.at(i)->getValue();
	}
	for (int i = 0; i < equipment.size(); ++i)
	{
		gear_val += equipment.at(i)->getValue();
	}

	min_dmg = base_min_dmg + str_val;
	max_dmg = base_max_dmg + str_val + wep_val;
	def = base_def + def_val;

	if (currHP == maxHP) //In case HP is 
	{
		maxHP = baseHP + hp_val;
		currHP = maxHP;
	}
	else
	{
		maxHP = baseHP + hp_val;
	}
	
}

void player::mod_stats()
{
	std::string choice;

	display_stats();

	if (statpoints > 0)
	{
		std::cout << "You have " << statpoints << " remaining." << std::endl;
		std::cout << "Would you like to distribute these points?" << std::endl;

		while (choice != "No" || choice != "no" || choice != "N" || choice != "n")
		{
			getline(std::cin, choice);
			if (choice == "No" || choice == "no" || choice == "N" || choice == "n")
			{
				return;
			}
			else if (choice == "Yes" || choice == "Y" || choice == "y" || choice == "yes")
			{
				stat_progression();
				update_player();
				return;
			}
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

		quit = input_stats();

		if (!quit)
		{
			return;
		}
	}

	std::cout << "Here are your final stats." << std::endl;
	display_stats();
	std::cout << std::endl;

}

bool player::input_stats()
{
	std::string stat;

	int points = 0;

	getline(std::cin, stat);

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
		add_points(points);
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
	std::cin.ignore(); //Must fix to juggle around the whole menu?
}

bool player::add_exp(int x) //TO DO: Change exp scaling per 10 levels
{
	bool level_up = false;
	pexp += x;

	while (pexp >= maxexp)
	{
		plevel += 1;
		pexp = pexp - maxexp;
		maxexp += 100;
		statpoints += 5;
		level_up = true;
	}

	return level_up;
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

/*Combat Functions*/
int player::tRand(){
	return rand() % 100 + 1;
}
int player::randNumber(){
	return (rand() % (max_dmg - min_dmg)) + min_dmg;
}

int player::calculateDamage(Entity enemy, bool defend){
	int baseDamage = randNumber();
	int trueDamage = baseDamage - enemy.getDef();
	if (defend){
		trueDamage /= 5;
	}
	if (trueDamage <= 0){
		trueDamage = 1;
	}
	return trueDamage;
}

bool player::isDefending(){
	return defending;
}

/*Inventory Functions*/
bool player::add_inventory(Item* i) 
{
	if (inv_max_size > inv_size)
	{
		if (i->getName() != "None")
		{
			inventory.push_back(i);
			++inv_size;
			return true;
		}
	}
	return false;
}

void player::remove_inventory(string item)
{
	for (unsigned i = 0; i < inventory.size(); ++i)
	{
		if (inventory.at(i)->getName() == item)
		{
			delete inventory.at(i); //Err, I think we can just point this to NULL if we have a list of pointer items...
			inventory.erase(inventory.begin() + i);
		}
	}

}


Item* player::inventory_search(string itemName)
{
	for (unsigned i = 0; i < inventory.size(); ++i)
	{
		if (inventory.at(i)->getName() == itemName)
		{
			return inventory.at(i); //Or true.
		}
	}
	return NULL; //Or false.
}

/*Consumable Functions*/

bool player::add_con(Consumable* i)
{
	if (inv_max_size > inv_size)
	{
		if (i->getName() != "None")
		{
			con_inv.push_back(i);
			inv_size++;
			return true;
		}
		add_inventory(i);
	}
	return false;
}

void player::remove_con(string item)
{
	for (unsigned i = 0; i < con_inv.size(); ++i)
	{
		if (con_inv.at(i)->getName() == item)
		{
			delete con_inv.at(i); 
			con_inv.erase(con_inv.begin() + i);
			inv_size--;
		}
	}

}

Consumable* player::con_search(string itemName)
{
	for (unsigned i = 0; i < con_inv.size(); ++i)
	{
		if (con_inv.at(i)->getName() == itemName)
		{
			return con_inv.at(i); //Or true.
		}
	}
	return NULL; //Or false.
}


/*Gear Functions*/

bool player::add_gear(Gear* i)
{
	if (inv_max_size > inv_size)
	{
		if (i->getName() != "None")
		{
			gear_inv.push_back(i);
			inv_size++;
			return true;
		}
		add_inventory(i);
	}
	return false;
}

void player::remove_gear(string item)
{
	for (unsigned i = 0; i < gear_inv.size(); ++i)
	{
		if (gear_inv.at(i)->getName() == item)
		{
			delete gear_inv.at(i); //Err, I think we can just point this to NULL if we have a list of pointer items...
			gear_inv.erase(gear_inv.begin() + i);
			inv_size--;
		}
	}

}

Gear* player::gear_search(string itemName)
{
	for (unsigned i = 0; i < gear_inv.size(); ++i)
	{
		if (gear_inv.at(i)->getName() == itemName)
		{
			return gear_inv.at(i); //Or true.
		}
	}
	return NULL; //Or false.
}

/*Weapon Functions*/

bool player::add_wep(Weapon* i)
{
	if (inv_max_size > inv_size)
	{
		if (i->getName() != "None")
		{
			wep_inv.push_back(i);
			inv_size++;
			return true;
		}
		add_inventory(i);
	}
	return false;
}

void player::remove_wep(string item)
{
	for (unsigned i = 0; i < wep_inv.size(); ++i)
	{
		if (wep_inv.at(i)->getName() == item)
		{
			delete wep_inv.at(i); //Err, I think we can just point this to NULL if we have a list of pointer items...
			wep_inv.erase(wep_inv.begin() + i);
			inv_size--;
		}
	}

}

Weapon* player::wep_search(string itemName)
{
	for (unsigned i = 0; i < wep_inv.size(); ++i)
	{
		if (wep_inv.at(i)->getName() == itemName)
		{
			return wep_inv.at(i); //Or true.
		}
	}
	return NULL; //Or false.
}


//void player::inventory_display_type(std::string type, 

void player::display_inventory()
{
	std::string line = "-----------------------------------------------------";
	std::cout << line << std::endl;
	for (unsigned i = 0; i < inventory.size(); ++i)
	{
		std::cout << i << ". " << inventory.at(i)->getName() << std::endl;
		//if (i % 3 == 0 && i != 0)
		//{
			//std::cout << std::endl;
		//}
	}
	//for (unsigned i = 0; i < gear_inv.size(); ++i)
	//{
		//std::cout << i << ". " << gear_inv.at(i)->getName() << std::endl;
		//if (i % 3 == 0 && i != 0)
		//{
			//std::cout << std::endl;
		//}
	//}
	//for (unsigned i = 0; i < wep_inv.size(); ++i)
	//{
		//std::cout << i << ". " << wep_inv.at(i)->getName() << std::endl;
		//if (i % 3 == 0 && i != 0)
		//{
			//std::cout << std::endl;
		//}
	//}
	//for (unsigned i = 0; i < con_inv.size(); ++i)
	//{
		//std::cout << i << ". " << con_inv.at(i)->getName() << std::endl;
		//if (i % 3 == 0 && i != 0)
		//{
			//std::cout << std::endl;
		//}
	//}
	//std::cout << std::endl << line << std::endl;
}

void player::display_con_inventory()
{
	std::string line = "-----------------------------------------------------";
	std::cout << line << std::endl;
	for (unsigned i = 0; i < con_inv.size(); ++i)
	{
		std::cout << con_inv.at(i)->getName() << "  ";
		if (i % 3 == 0 && i != 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl << line << std::endl;
}

/*Equipment Functions*/

void player::equip_gear(int i, const Gear* x)
{
	Gear* temp = equipment.at(i);
	Gear* slot = new Gear(x);

	remove_gear(x->getName());
	equipment.at(i) = slot;
	if (temp->getName() != "None")
		add_gear(temp);
	else
	{
		gear_size -= 1;
		inv_size -= 1;
	}
	update_player();
}

void player::remove_gear(int i)
{

	if (!add_gear(equipment.at(i)))
	{
		std::cout << "Your inventory is too full." << std::endl;
		return;
	}
	equipment.at(i) = none;
	gear_size += 1;
	inv_size += 1;
	update_player();
}

void player::equip_wep(int i, const Weapon* x)
{
	Weapon* temp = weapon.at(i);
	Weapon* slot = new Weapon(x);

	remove_wep(x->getName());
	weapon.at(i) = slot;
	if (temp->getName() != "None")
	{
		add_wep(temp);
	}
	else
	{
		wep_size -= 1;
		inv_size -= 1;
	}
	update_player();
}

void player::remove_wep(int i)
{

	if (!add_wep(weapon.at(i)))
	{
		std::cout << "Your inventory is too full." << std::endl;
		return;
	}
	weapon.at(i) = none_wep;
	wep_size += 1;
	inv_size += 1;
	update_player();
}

int player::find_slot(std::string gear)
{
	if (gear == "head" || gear == "Head")
	{
		return 0;
	}
	else if (gear == "torso" || gear == "Torso")
	{
		return 1;
	}
	else if (gear == "leggings" || gear == "Leggings")
	{
		return 2;
	}
	else if (gear == "shoes" || gear == "Shoes")
	{
		return 3;
	}
	else if (gear == "gloves" || gear == "Gloves")
	{
		return 4;
	}
	else if (gear == "Main Hand" || gear == "main hand" || gear == "main")
	{
		return 5;
	}
	else if (gear == "Off hand" || gear == "off hand" || gear == "off")
	{
		return 6;
	}
	else
	{
		return -1;
	}
}

void player::display_equipment() //TO DO: What if an equipment points to null?
{
	std::cout << "Head: " << equipment.at(0)->getName() << std::endl;
	std::cout << "Torso: " << equipment.at(1)->getName() << std::endl;
	std::cout << "Gloves: " << equipment.at(2)->getName() << std::endl;
	std::cout << "Pants: " << equipment.at(3)->getName() << std::endl;
	std::cout << "Main Hand: " << weapon.at(0)->getName() << std::endl;
	std::cout << "Off Hand: " << weapon.at(1)->getName() << std::endl;
}

/*Party Functions*/

void player::display_party()
{
	std::cout << "Name: " << this->getname() << std::endl;
	std::cout << "Health: " << this->currHP << "/" << this->maxHP << std::endl;
	std::cout << "Mana: " << this->currMP << "/" << this->maxMP << std::endl;
	for (int i = 0; i < party.size(); ++i)
	{
		std::cout << "Name: " << party.at(i)->getname() << std::endl;
		std::cout << "Health: " << party.at(i)->getMaxHP() << "/" << party.at(i)->getHP() << std::endl;
	}
	std::cout << std::endl;
}

void player::add_member(Ally* member)
{
	party.push_back(member);
}

std::vector<Ally*> player::get_party()
{
	return party;
}