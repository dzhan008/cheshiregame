#pragma once
#include <string>
#include <vector>
#include "Entity.h"
// Quests have 3 status
// Not found = 0 
// In Progress = 1 
// Complete = 2
using namespace std;
class Quest
{
public:
    Quest();
    ~Quest();
	Quest(const string name, string type, string target, unsigned amount, unsigned current, string goals, string prize); //kill x monster quest
	void killQuest(Entity target);
    void displayQuest();
    bool KillQuestisComplete();
	string getname();
private:
    std::string info;
    // Use vector when multiple requirements are necessary
    // For now, only assume one requirement
    int st;
    // This only works for SLAY type quests
    std::string questname;
    std::string questtype;
    std::string monstername;
    unsigned monstercount;
    std::string questdescription;
	string reward;
    unsigned curr_monster_count = 0;
    bool completed;
};

