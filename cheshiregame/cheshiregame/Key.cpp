#include "Key.h"

#include <fstream>
#include <iostream>

using namespace std;

//Each quest item is unique. Meaning it will trigger different things to occur.
//Implementation right now is with just one quest item. 
//Add more to quest_item file as storyline progresses.

void Key::triggerItem(player p)
{
	ifstream fin;
	string line;
	string file = "quest_item";

	fin.open(file.c_str());
	if (!fin)
	{
		cout << "Error opening " << file << endl;
		return;
	}
	while(getline(fin, line))
	{
		cout << line << endl;
	}
}
