#pragma once
#include "Quest.h"
#include <vector>
#include <string>

class QuestManager
{
public:

    QuestManager();
	void Accept(Quest q); //accepts or declines a quest
	void removeQuest(Quest q);//removes q from the questlog
	void QuestMenu();
	void QuestTracking(Quest q);//checks the progress on q
    ~QuestManager();
private:
    // Will hold all quests
    std::vector<Quest> questlog;
};

