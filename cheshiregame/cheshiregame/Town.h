#ifndef TOWN_H_
#define TOWN_H_

#include <string>
#include <vector>
#include <utility>

#include "Player.h"
#include "Dungeon.h"
#include "SaveSystem.h"

class Dungeon;
class SaveSystem;

class Town {
private:
    std::string townname;
    /* Store goes here */
    Store s;
	Dungeon* dungeon1;
	Dungeon* dungeon2;
    /* Blacksmith goes here */
    // BlackSmith bs;
    /* Tavern goes here */
    // Tavern t;
    /* Townspeoples, may put them in a tavern or something*/
    /* Might want to create a person class to interact with for quests and such*/
    std::vector<std::pair<std::string, std::string> > people;

    /* Loads town from text file*/
    void fill_town(const std::string &text_file);

public:
    Town(player* p);
    Town(std::string filename);
    void run(player* p);
	void inn(player* p);
    void tavern(player* p);
    void blacksmith(player* p);
    void store(player* p);
    void talk();
	void dungeon_select(player* p);
	void display_options();
    SaveSystem savesystem;

private:
	std::vector<Ally*> allies;
	void createAllies(player*);
	void displayAllies();
	void displayTavernMenu();
};

#endif
