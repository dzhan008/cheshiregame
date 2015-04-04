#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>



using namespace std;
/*----------Private Helper Functions----------*/
void Dungeon::fill_dungeon(const string &text_file)
{
	ifstream inFS;

	//Fill up the vector of dungoen loot first

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
	int hp, level, experience, defend, gold;
	int s, a, v, d, l; //str, agil, vit, dex, luck

	string input;
	string item_name;
	int item_val;
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
			inFS >> hp >> level >> experience >> defend >> gold;
			inFS >> s >> a >> v >> d >> l;
			Entity temp_entity(entity_name, hp, level, experience, defend, gold);
			temp_entity.setEntityStats(s, a, v, d, l);
			inFS >> input; //reads in if its :loot: or <end>
			if (input == ":loot:")
			{
				inFS.ignore();
				getline(inFS, item_name);
				while (item_name != "<end>")
				{
					inFS >> item_val;
					Item temp_item(item_name, item_val);
					temp_entity.add_loot(temp_item);
					inFS.ignore();
					getline(inFS, item_name);
				}
			}

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
		entity_group.at(i).print_loot();
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