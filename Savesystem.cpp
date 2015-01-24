#include "Savesystem.h"
#include <iostream>
#include <fstream>
#include <string>

Savesystem::Savesystem() {
}
Savesystem::Savesystem(Savedata s) {
    sd = s;
}

void Savesystem::demo() {
    while () {
        std::cout << "Save/Load system" << std::endl;
        std::cout << "1. Save" << std::endl;
        std::cout << "2. Load" << std::endl;
        std::cout << "0. Exit" << std::endl;

        int input;
        std::cin >> input;

        switch (input) {
            case 1:
                this->save();
                break;
            case 2:
                this->load();
                break;
            case 0:
                return;
            default:
                break;
        }
    }
}

void Savesystem::save() {
    std::cout << "Input save name to SAVE" << std::endl;
    std::string input;
    std::cin >> input;
    if (writedata(input)) {
        std::cout << "Save successful!" << std::endl;
    } else {
        std::cout << "Save was NOT successful. Please try again." << std::endl;
    }
}

bool Savesystem::writedata(std::string input) {
    input.append(".svdat");
    ofstream f;
    f.open(input);
    if (f.is_open()) {
        // write to file
    } else {
        return false;
    }
    return true;
}

void Savesystem::load() {
    std::cout << "Input save name to LOAD" << std::endl;
    std::string input;
    std::cin >> input;
    if (loaddata(input)) {
        std::cout << "Load successful!" << std::endl;
    } else {
        std::cout << "Load was NOT successful. Please try again." << std::endl;
    }
}


bool Savesystem::loaddata(std::string input) {
    input.append(".svdat");
    ifstream f;
    f.open(input);
    if (f.is_open()) {
        // read from file
    } else {
        return false;
    }
    return true;
}

void Savesystem::encryptdata(Savedata) {

}
void Savesystem::decryptdata(Savedata) {

}
