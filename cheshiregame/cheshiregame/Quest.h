#pragma once
#include <string>
#include <vector>

// Quests have 3 status
// Not found = 0 
// In Progress = 1 
// Complete = 2
class Quest
{
public:
    Quest();
    Quest(std::string, std::string, std::string, unsigned, std::string);
    ~Quest();

    void setStatus(unsigned);
    void setCurrMonsterCount(unsigned);
    void displayQuest();
    bool isComplete();
    void setComplete(bool);
private:
    std::string info;
    // Use vector when multiple requirements are necessary
    // For now, only assume one requirement
    int st;
    // This only works for SLAY type quests
    std::string quest_name;
    std::string quest_type;
    std::string monster_name;
    unsigned monster_count;
    std::string quest_description;

    unsigned curr_monster_count = 0;
    bool completed;
};

