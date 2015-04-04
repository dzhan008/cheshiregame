#include "stdafx.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Town.h"
#include "Store.h"
/*
Town fileformat will be as follows:
   
   <townname>
   <store_filename>
   <# of people>
   <person 1's name>
   <person 1 dialog>
   <person 2's name>
   <person 2's dialog>
   <continued>
*/

/*void Town::fill_town(const std::string &text_file) {
    std::string townname;
    std::string store_filename;
    int people_count;

    std::ifstream inFS;
    inFS.open(text_file.c_str());
    if (!inFS.is_open()) {
        std::cerr << "Error: Cannot open Town file" << std::endl;
        return;
    }
    std::getline(inFS, townname);
    this->townname = townname;
    std::getline(inFS, store_filename);
    Store s;
    // TODO: Make a sample store?
    //s.fillStore(store_filename);
    this->s = s;
    inFS >> people_count;

    std::string name;
    std::string dialog;
    for (int i = 0; i < people_count; ++i) {
        std::getline(inFS, name);
        std::getline(inFS, dialog);
        people.push_back(
            std::make_pair(name, dialog));
    }
    inFS.close();
}*/

Town::Town() {
	dungeon1 = new Dungeon("demo_dun_1.txt");
	dungeon2 = new Dungeon("demo_dun_2.txt");
    //fill_town("sample_town");
}

Town::Town(std::string filename) {
    //fill_town(filename);
}

void Town::run(player* p) {
    // Main function? I guess.
    //std::cout << "Welcome to " << townname << std::endl;
	int choice = -1;

	while (choice != 0)
	{
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "1. Visit Inn" << std::endl
			<< "2. Go shopping" << std::endl
			<< "3. Go to the blacksmith" << std::endl
			<< "4. Go to the tavern" << std::endl
			<< "5. Go talk to the townspeople" << std::endl
			<< "6. Leave the town" << std::endl;

			std::cout << "> ";
			cin >> choice;

			switch (choice) {
			case 1:
				inn(p);
				break;
			case 2:
				store();
				break;
			case 3:
				blacksmith();
				break;
			case 4:
				tavern();
				break;
			case 5:
				talk();
				break;
			case 6:
				dungeon_select();
			case 7:
				return;
			default:
				cout << "Bad input, try again." << std::endl;
				break;
			
		}
	}
}

void Town::inn(player* p) {

	int choice = -1;
	std::string input;
    
   std::cout << ">";
	while (choice != 3)
	{
		std::cout << "Welcome to the inn." << std::endl;
		std::cout << "1. Rest" << std::endl;
		std::cout << "2. Recruit" << std::endl;
		std::cout << "3. Exit" << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1:
			std::cout << "It will cost you 50 gold. Are you sure?" << std::endl;
			std::cout << "1. Yes" << std::endl;
			std::cout << "2. No" << std::endl;
			std::cin >> choice;
			if (choice == 1)
			{
				if (p->getmoney() < 50)
				{
					std::cout << "What do you think this is, a charity house? Get lost!" << std::endl;
					return;
				}
				else
				{
					p->setmoney(p->getmoney() - 50);
					p->setHP(p->getMaxHP());
					std::cout << "Hope you enjoyed your stay!" << std::endl;
					return;
				}
			}
			else if (choice == 2)
			{
				break;
			}
			break;
		case 2:
			// Recruit party members
			std::cout << "Recruiting not implemented." << std::endl;
			break;
		case 3:
			return;
			break;
		default:
			cout << "Bad input, try again." << std::endl;
			break;
		}
	}
}

void Town::blacksmith() {
    // TODO: Impelment blacksmith
    std::cout << "unimplemented blacksmith" << std::endl;
    return;
}

void Town::tavern() {
    // TODO: Implement tavern
    std::cout << "unimplemented tavern" << std::endl;
    return;
}

void Town::store() {
    //s.run();
    return;
}

void Town::talk() {
    srand(time(NULL));
    int random = rand() % this->people.size() + 1;
    std::cout << people.at(random).first << "says: " <<
    people.at(random).second << std::endl;
    return;
}

void Town::dungeon_select()
{
	std::cout << "Which dungeon would you like to go to?" << std::endl;
	//Output dungeons
	std::cout << "";
}
