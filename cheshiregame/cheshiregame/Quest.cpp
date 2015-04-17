#include "stdafx.h"
#include "Quest.h"

Quest::Quest() {
}

// Constructor for SLAY quest
Quest::Quest(std::string quest_name, std::string quest_type,
    std::string monster_name, unsigned monster_count,
    std::string quest_description) : quest_name(quest_name), 
    quest_type(quest_type), monster_name(monster_name), 
    monster_count(monster_count), 
    quest_description(quest_description)
{}


Quest::~Quest()
{
}

void Quest::displayQuest() {
    std::cout << quest_name << std::endl;
    std::cout << quest_description << std::endl;
    std::cout << monster_name << " slayed: " << 
        curr_monster_count << std::endl;
}

void Quest::setStatus(unsigned s) {
   st = s;
}

bool Quest::isComplete() {
    return completed;
}

void Quest::setComplete(bool b) {
    completed = b;
}