#include "stdafx.h"
#include "QuestManager.h"
#include <string>
#include <fstream>
#include <vector>


QuestManager::QuestManager()
{
}


QuestManager::~QuestManager()
{
}

/* Quest File format
 * 0: # of quests
 * First Line: Title
 * Requirements:
 * Pick type: (SLAY | DELIVER | ACTIVATE)
 * (only SLAY will be implemented)
 * IF SLAY:
 *      Pick Monster Name
 *      Quantity of Monster
 * End with Single Line Quest Description
 * 
 */

/* EX:
    1
    My First Quest
    SLAY
    Wolf
    3
    Slay 3 "Wolf". 
*/


bool QuestManager::loadAllQuests(const std::string &text_file) {
    ifstream inFS;
    
    inFS.open(text_file.c_str());
    if (!inFS.is_open()) {
        std::cerr << "Cannot open quest file " << std::endl;
        return false;
    }
    unsigned quest_count;
    std::string quest_title;
    std::string quest_type;
    std::string monster_name;
    unsigned monster_count;
    std::string quest_description;
    inFS >> quest_count;
    
    for (unsigned i = 0; i < quest_count; ++i) {
        inFS >> quest_title >> quest_type;
        if (quest_type == "SLAY") {
            inFS >> monster_name >> monster_count;
        }
        else {
            std::cerr << "error: unsupported quest type";
            inFS.close();
            return false;
        }
        inFS >> quest_description;

        this->q.push_back(Quest(quest_title, quest_type, 
            monster_name, monster_count, quest_description));
    }
  
    inFS.close();
    return true;
}


// Currently only applies to SLAY quest type
void QuestManager::updateQuest(unsigned quest_number, unsigned quest_status, 
    unsigned monster_count) {
    q.at(quest_number).setStatus(quest_status);
    q.at(quest_number).setCurrMonsterCount(monster_count);
}