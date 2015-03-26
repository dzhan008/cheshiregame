#ifndef TOWN_H_
#define TOWN_H_

#include <string>
#include <vector>
#include <utility>

class Town {
private:
    std::string townname;
    /* Store goes here */
    Store s;
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
    Town();
    Town(std::string filename);
    void run();
    void inn();
    void tavern();
    void blacksmith();
    void store();
    void talk();

};

#endif
