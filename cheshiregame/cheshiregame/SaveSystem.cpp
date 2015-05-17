#include "stdafx.h"
#include "SaveSystem.h"
#include "Player.h"
#include "Town.h"


SaveSystem::SaveSystem()
{
}


SaveSystem::~SaveSystem()
{
}

void SaveSystem::Save(player player) {
    p = player;
}

bool SaveSystem::WriteToDisk(std::string str) {
    ofstream f;
    f.open(str.c_str());
    if (!(f.is_open())) {
        std::cerr << "could not find/open save data" << std::endl;
        return false;
    }
    // Write player data to save file
    f << "save" << ' ';
    try {
        f << p.getname() << ' ' <<
            p.getjob() << ' ' <<
            p.getMaxHP() << ' ' <<
            p.getHP() << ' ' <<
            p.getlevel() << ' ' <<
            p.getmoney() << ' ' <<
            p.getexp() << ' ' <<
            p.getDef() << ' ' <<
            p.getStatPoints() << ' ';
        for (unsigned i = 0; i < p.getStats().size(); ++i) {
            f << p.getStats().at(i) << ' ';
        }
        f.flush();
        f.close();
    }
    catch (...) {
        std::cerr << "write to disk failed!" << std::endl;
        return false;
    }
    return true;
}


// Currently only loads player, not town
bool SaveSystem::LoadFromDisk(std::string str) {
    ifstream f;
    f.open(str.c_str());
    if (!(f.is_open())) {
        std::cerr << "could not find/open save data" << std::endl;
        return false;
    }
    std::string check;
    f >> check;
    if (check != "save") {
        std::cerr << "bad save data" << std::endl;
        return false;
    }
    std::string name;
    std::string job;
    int maxhp, hp, level, money, exp, def, statpts;
    std::vector<int> stats(5);
    
    try {
        f >> name >> job >> maxhp >> hp >> level >> money >> exp
            >> def >> statpts >> stats.at(0) >> stats.at(1) >> stats.at(2) >> stats.at(3)
            >> stats.at(4);
    }
    catch (...) {
        std::cerr << "load from disk failed!" << std::endl;
        return false;
    }
    player loadedplayer(name, job, maxhp, level, exp, statpts, money);
    loadedplayer.setHP(hp);
    loadedplayer.setstats(stats);
    loadedplayer.set_def(def);
    p = loadedplayer;

    return true;
}

void SaveSystem::loadSave() {
    std::cout << "Type name of save file to LOAD (type \"exit\" or \"back\" to return) " << std::endl;
    std::string savename;
    std::cin >> savename;
    if (savename == "exit" | savename == "back") return;
    if (LoadFromDisk(savename)) {
        std::cout << "load successful!" << std::endl;
    }
}

void SaveSystem::saveSave() {
    std::cout << "Type name of save file to SAVE (type \"exit\" or \"back\" to return) " << std::endl;
    std::string savename;
    std::cin >> savename;
    if (savename == "exit" | savename == "back") return;
    std::cout << "Writing " << savename << "to disk" << std::endl;
    if (WriteToDisk(savename)) {
        std::cout << "save successful!" << std::endl;
    }
}