#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

Dungeon::Dungeon(const string &text_file)
{
	ifstream inFS;
	//open entity file
	string dunFile = "Assets/Dungeons/" + text_file;
	inFS.open(dunFile.c_str());
	if (!inFS.is_open())
	{
		cout << "Error: cannot open all entity txt file." << endl;
		return;
	}

	string entity_name;
	int hp, mana, level, experience, defend, gold;
	int s, a, v, d, l; //str, agil, vit, dex, luck

	string input;
	string item_name;
	int item_val;

	string spell_name;
	string spell_type;
	int spell_damage;
	int spell_cost;


	//Inserts entity into map until reaches end of file
	while (inFS.good())
	{
		getline(inFS, entity_name);
		if (entity_name == "end")
		{
			inFS.close();
		}
		else
		{
			inFS >> hp >> mana >> level >> experience >> defend >> gold;
			inFS >> s >> a >> v >> d >> l;
			Entity* temp_entity = new Entity(entity_name, hp, mana, level, experience, defend, gold);
			temp_entity->setEntityStats(s, a, v, d, l);
			inFS >> input; //reads in if its :loot: or <end>
			inFS.ignore();
			if (input == ":loot:")
			{
				getline(inFS, item_name);
				while (item_name != "<end_item>")
				{
					inFS >> item_val;
					Item* temp_item = new Item(item_name, item_val);
					temp_entity->add_loot(temp_item);
					inFS.ignore();
					getline(inFS, item_name);
				}
				inFS >> input;
				inFS.ignore();
			}
			if (input == ":spells:")
			{
				getline(inFS, spell_name);
				while (spell_name != "<end>")
				{
					inFS >> spell_damage;
					inFS >> spell_cost;
					inFS >> spell_type;
					Spells* temp_s = new Spells(spell_name, spell_type, spell_damage, spell_cost);
					temp_entity->add_spells(temp_s);
					inFS.ignore();
					getline(inFS, spell_name);
				}
			}

			all_entity.insert(pair<string, Entity*>(entity_name, temp_entity));
		}
	}
}
void Dungeon::fill_dungeon(const string &text_file, const string &map_file)
{
	ifstream inFS;

	//open entity file
	string dunFile = "Assets/Dungeons/" + text_file;
	inFS.open(dunFile.c_str());

	if (!inFS.is_open())
	{
		cout << "Error: cannot open entity_name txt file" << endl;
		return;
	}

	string dun_name; //dungeon name
	string diff; //difficulty

	string entity_name;

	//Stores dungeon name
	getline(inFS, dun_name);
	dungeon_name = dun_name;

	//Stores difficulty
	inFS >> diff;
	dungeon_difficulty = diff;
	inFS.ignore();

	//Push backs entity* into vector until reaches end of file
	while (inFS.good())
	{
		getline(inFS, entity_name);
		if (entity_name == "end")
		{
			inFS.close();
			break;
		}
		map<string, Entity*>::iterator it;
		it = all_entity.find(entity_name);
		Entity* temp = it->second;
		entity_group.push_back(temp);
	}
	dungeon_map = new dun_map(10, map_file);
}

void Dungeon::clear_dun()
{
	entity_group.clear();
	delete dungeon_map;
	dungeon_map = 0;
}

Dungeon::~Dungeon()
{
	entity_group.clear();
	delete dungeon_map;
	dungeon_map = 0;
}

void Dungeon::change_dungeon(const string &text_file, const string &map_file)
{
	clear_dun();
	fill_dungeon(text_file, map_file);
}
const void Dungeon::display_dungeon()
{
	cout << "Dungeon name: " << dungeon_name << endl;
	cout << "Dungeon difficulty: " << dungeon_difficulty << endl;
	cout << "Monsters: " << endl;
	for (int i = 0; i < entity_group.size(); i++)
	{
		entity_group.at(i)->Print();
		//entity_group.at(i)->print_loot();
		cout << endl;
	}
}

int Dungeon::size()
{
	return entity_group.size();
}

const string Dungeon::get_dun_name()
{
	return dungeon_name;
}
Entity* Dungeon::rand_monster()
{
	int index = rand() % (entity_group.size() - 1); // -1 because boss is in last index
	return entity_group.at(index);
}

Entity* Dungeon::get_boss()
{
	return entity_group.at(entity_group.size() - 1);
}

bool Dungeon::run_dungeon(player*& p, Combat_System c)
{
	string input;

	while (true)
	{
		//cout << dun_map->gf() << " " << dun_map->gs() << endl;
		//cout << dun_map->pf() << " " << dun_map->ps() << endl;
		bool menu = false;
		cout << endl;
		system("cls"); //NEW ADDITION
		dungeon_map->display();
		cout << "Enter direction (up, down, left, right). " << endl;
		cout << "Type 'menu' to access the player menu." << endl;
		cin >> input;
		if (input == "menu")
		{
			Scene s;
			s.basic_menu(p);
		}
		if (input == "up" || input == "u")
		{
			dungeon_map->moveUp();
			//dungeon_map->display();
		}
		else if (input == "down" || input == "d")
		{
			dungeon_map->moveDown();
			//dungeon_map->display();
		}
		else if (input == "left" || input == "l")
		{
			dungeon_map->moveLeft();
			//dungeon_map->display();
		}
		else if (input == "right" || input == "r")
		{
			dungeon_map->moveRight();
			//dungeon_map->display();
		}
		if ((dungeon_map->pf() == dungeon_map->gf()) && (dungeon_map->ps() == dungeon_map->gs()))
		{
			//cout << "GOOOOOAAAAAAAALLLLLLLLLLL!" << endl;
			return false;
		}
		else if (input != "menu" && ((rand() % 4 + 1) == 1)) //Fix instance where the player encounters an enemy even when standing still.
		{
			system("cls");
			c.runBattle(rand_monster());
		}
		if (p->getHP() <= 0)
		{
			return false;
		}
	}

	return false;
}

void Dungeon::display_all()
{
	for (map<string, Entity*>::iterator it = all_entity.begin(); it != all_entity.end(); it++)
	{
		it->second->Print();
		cout << "Loot: " << endl;
		it->second->print_loot();
		cout << endl;
	}
}