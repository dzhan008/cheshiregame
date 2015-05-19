#include "stdafx.h"
#include "QuestManager.h"
#include <string>
#include <fstream>
#include <vector>
using namespace std;

QuestManager::QuestManager()
{
	//empty quest log is empty
}


QuestManager::~QuestManager()
{

}

void QuestManager::Accept(Quest q)
{
	string input;

	cout << "Do you accept this quest? (Y/N)\n";
	cin >> input;
	if (input == "Y" || input == "y")
	{
		questlog.push_back(q);
		cout << "Quest added to questlog.\n";
		return;
	}
	cout << "Maybe next time.\n";
}
void QuestManager::removeQuest(Quest q)//Removes quest based on their name
{
	for (int i = 0; i < questlog.size(); i++)
	{
		if (questlog.at(i).getname() == q.getname())
		{
			questlog.erase(questlog.begin() + i);
			return;
		}
	}
}
void QuestManager::QuestMenu()
{
	for (int i = 0; i < questlog.size(); i++)
	{
		cout << (i + 1) << questlog.at(i).getname() << endl;
	}
	while (true) //menu will be implemented when there are actually quests.
	{
		return;
	}

}
void QuestManager::QuestTracking(Quest q)
{
	//for killing quests I can't track it from the quest manager without testing it in battle.
	//basically it runs the battle
	//when a monster dies, it should call q.killQuest(monster) which will increment the counter
	//Then call q.killquestiscomplete which will set the bool to true if the monster count is 0
}