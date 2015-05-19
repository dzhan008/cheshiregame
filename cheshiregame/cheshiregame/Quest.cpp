#include "stdafx.h"
#include "Quest.h"
using namespace std;
Quest::Quest() 
{
	questname = "Let's start an adventure";
	questtype = "Basic";
	monstername = " ";
	monstercount = 0;
	curr_monster_count = 0;
	questdescription = "Let's do a quest.";
	reward = "Friendship";
	completed = false;
}

// Constructor for SLAY quest

Quest::Quest(const string name, string type, string target, unsigned amount, unsigned current, string goals, string prize)
{
	questname = name;
	questtype = type;
	monstername = target;
	monstercount = amount;
	curr_monster_count = current;
	questdescription = goals;
	reward = prize;
	
}

Quest::~Quest()
{
	if (completed == true)
	{
		delete this;
	}
}

void Quest::displayQuest() 
{
	cout << questname << endl;
	cout << "Type:  " << questtype << endl;
	cout << "About: " << questdescription << endl;
	cout << "Reward: " << reward << endl;
	cout << "Killed: " << curr_monster_count << endl;
}

void Quest::killQuest(Entity target)
{
	if (target.getName() == monstername)
	{
		monstercount--;
		curr_monster_count++;
	}
}

bool Quest::KillQuestisComplete() 
{
	if (monstercount == 0)
	{
		completed = true;
		return completed;
	}
	return false;
}

string Quest::getname()
{
	return questname;
}