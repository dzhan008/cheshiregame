#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Town.h"
#include "Store.h"

/* Town fileformat will be as follows:
   
   <townname>
   <store_filename>
   <# of people>
   <person 1's name>
   <person 1 dialog>
   <person 2's name>
   <person 2's dialog>
   <continued>
*/

void Town::fill_town(const std::string &text_file) {
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
}

Town::Town() {
    fill_town("sample_town");
}

Town::Town(std::string filename) {
    fill_town(filename);
}

void Town::run() {
    // Main function? I guess.
    std::cout << "Welcome to " << townname << std::endl;
    std::cout << "1. Visit Inn" << std::endl
        << "2. Go shopping" << std::endl
        << "3. Go to the blacksmith" << std::endl
        << "4. Go to the tavern" << std::endl
        << "5. Go talk to the townspeople" << std::endl
        << "6. Leave the town" << std::endl;

    int choice;
    for (;;) {
        std::cout << "> ";
        cin >> choice;

        switch (choice) {
        case 1:
            inn();
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
            return;
        default:
            cout << "Bad input, try again" << std::endl;
            break;
        }
    }

}

void Town::inn() {
    std::cout << "Welcome to the inn" << std::endl;
    std::cout << "1. Rest" << std::endl;
    std::cout << "2. Recruit" << std::endl;
    std::cout << "3. Exit" << std::endl;
    int choice;
    
    for (;;) {
        std::cout << ">";
        std::cin >> choice;
        switch (choice) {
        case 1:
            // Reset player HP to 100%
            std::cout << "healing not implemented" << std::endl;
            break;
        case 2:
            // Recruit party members
            std::cout << "recruiting not implemented" << std::endl;
            break;
        case 3:
            return;
            break;
        default:
            cout << "Bad input, try again" << std::endl;
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
    s.run();
    return;
}

void Town::talk() {
    srand(time(NULL));
    int random = rand() % this->people.size() + 1;
    std::cout << people.at(random).first << "says: " <<
        people.at(random).second << std::endl;
    return;
}