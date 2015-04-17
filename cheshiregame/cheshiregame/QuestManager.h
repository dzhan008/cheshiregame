#pragma once
#include "Quest.h"
#include <vector>
#include <string>

class QuestManager
{
public:

    QuestManager();
    ~QuestManager();
    // Updates quest state 
    // updateQuest(quest id, quest status)
    void updateQuest(unsigned, unsigned, unsigned);
    // deletes quest from quest vector
    // deletequest(quest id)
    void deleteQuest(int);
    // adds quest 
    // addQuest(quest id)
    bool addQuest(int);

    // loads quests from file
    bool loadAllQuests(const std::string&);

    // displays quest from quest vector
    bool displayQuest(int);
    

private:
    // Will hold all quests
    std::vector<Quest> q;
};

