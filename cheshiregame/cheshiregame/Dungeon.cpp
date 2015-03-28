#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>



using namespace std;

/*----------Private Helper Functions----------*/
const Item Dungeon::rand_loot()
{
	int index = rand() % dungeon_loot.size();
	return dungeon_loot.at(index);
}
void Dungeon::fill_dungeon(const string &text_file, const string &dun_loot)
{
	ifstream inFS;

	//Fill up the vector of dungoen loot first
	inFS.open(dun_loot.c_str());
	if (!inFS.is_open())
	{
		cout << "Error: cannot open dungeon loot txt file." << endl;
		return;
	}

	string item_name;
	int item_val;
	while (inFS.good())
	{
		getline(inFS, item_name);
		inFS >> item_val;
		inFS.ignore();
		Item temp_item(item_name, item_val);
		dungeon_loot.push_back(temp_item);
	}
	//close dungeon loot file
	inFS.close();


	//open entity file
	inFS.open(text_file.c_str());

	if (!inFS.is_open())
	{
		cout << "Error: cannot open entity txt file" << endl;
		return;
	}

	string dun_name; //dungeon name
	string diff; //difficulty

	string entity_name;
	int hp, level, experience;
	int s, a, v, d, l; //str, agil, vit, dex, luck

	//Stores dungeon name
	getline(inFS, dun_name);
	dungeon_name = dun_name;

	//Stores difficulty
	inFS >> diff;
	dungeon_difficulty = diff;

	//Push backs entity into vector until reaches end of file
	while (inFS.good())
	{
		inFS >> entity_name;
		if (entity_name == "end")
		{
			inFS.close();
		}
		else
		{
			inFS >> hp >> level >> experience;
			inFS >> s >> a >> v >> d >> l;
			Entity temp_entity(entity_name, hp, level, experience);
			temp_entity.setEntityStats(s, a, v, d, l);
			temp_entity.add_loot(rand_loot());
			entity_group.push_back(temp_entity);
		}
	}

}

Dungeon::Dungeon(const string &text_file)
{
	fill_dungeon(text_file);
}

void Dungeon::change_dungeon(const string &text_file)
{
	entity_group.clear();
	fill_dungeon(text_file);
}

const void Dungeon::display_dungeon()
{
	cout << "Dungeon name: " << dungeon_name << endl;
	cout << "Dungeon difficulty: " << dungeon_difficulty << endl;
	cout << "Monsters: " << endl;
	for (int i = 0; i < entity_group.size(); i++)
	{
		entity_group.at(i).Print();
		cout << endl;
	}
}

int Dungeon::size()
{
	return entity_group.size();
}

const Entity Dungeon::rand_monster()
{
	int index = rand() % entity_group.size();
	return entity_group.at(index);
}