#include "stdafx.h"
#include <vector>
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
        // inventory
        // this does not account for rarity
        f << '\n';
        f << p.equipment.size() << ' ';
        for (unsigned i = 0; i < p.equipment.size(); ++i) {
            f << p.equipment.at(i)->getName() << ' '
                << p.equipment.at(i)->getValue() << ' '
                << p.equipment.at(i)->getType() << ' '
                << p.equipment.at(i)->getStats() << ' ';
        }
        f << '\n';
        f << p.weapon.size() << ' ';
        for (unsigned i = 0; i < p.weapon.size(); ++i) {
            f << p.weapon.at(i)->getName() << ' '
                << p.weapon.at(i)->getType() << ' '
                << p.weapon.at(i)->getValue() << ' '
                << p.weapon.at(i)->getDmg() << ' ';
        }
        f << '\n';
        f << p.inventory.size() << ' ';
        for (unsigned i = 0; i < p.inventory.size(); ++i) {
            f << p.inventory.at(i)->getName() << ' '
                << p.inventory.at(i)->getType() << ' '
                << p.inventory.at(i)->getValue() << ' ';
        }
        f << '\n';
        f << p.con_inv.size() << ' ';
        for (unsigned i = 0; i < p.con_inv.size(); ++i) {
            f << p.con_inv.at(i)->getName() << ' '
                << p.con_inv.at(i)->getType() << ' '
                << p.con_inv.at(i)->getValue() << ' ';
        }
        
        f << '\n';
        f << p.gear_inv.size() << ' ';
        for (unsigned i = 0; i < p.con_inv.size(); ++i) {
            f << p.gear_inv.at(i)->getName() << ' '
                << p.gear_inv.at(i)->getType() << ' '
                << p.gear_inv.at(i)->getValue() << ' '
                << p.gear_inv.at(i)->getStats() << ' ';
        }
        f << '\n';
        f << p.wep_inv.size() << ' ';
        for (unsigned i = 0; i < p.wep_inv.size(); ++i) {
            for (unsigned i = 0; i < p.wep_inv.size(); ++i) {
                f << p.wep_inv.at(i)->getName() << ' '
                    << p.wep_inv.at(i)->getType() << ' '
                    << p.wep_inv.at(i)->getValue() << ' '
                    << p.wep_inv.at(i)->getDmg() << ' ';
            }
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

    std::vector<Gear*> equipment; //0 = Head 1 = Torso 2 = Arms 3 = Legs
    std::vector<Weapon*> weapon; //0 = Right Hand 1 = Off/Left Hand HUEHUE
    std::vector<Item*> inventory; //For displaying items in Store
    std::vector<Consumable*> con_inv;
    std::vector<Gear*> gear_inv;
    std::vector<Weapon*> wep_inv;

    //std::string name;
    int val;
    std::string type;
    int stat, dmg;
    // equipment
    unsigned sz = 0;
    // i don't know if these will exist after function will end
    // may need to overhaul pointers
    // or even start dynamic allocation..
    try {
        f >> sz;
        for (unsigned i = 0; i < sz; ++i) {
            f >> name >> val >> type >> stat;
            equipment.push_back(&Gear(name, val, type, stat));
        }
        f >> sz;
        for (unsigned i = 0; i < sz; ++i) {
            f >> name >> type >> val >> dmg;
            weapon.push_back(&Weapon(name, type, val, stat));
        }
        f >> sz;
        for (unsigned i = 0; i < sz; ++i) {
            f >> name >> type >> val;
            inventory.push_back(&Item(name, val, type));
        }
        f >> sz;
        for (unsigned i = 0; i < sz; ++i) {
            f >> name >> type >> val;
            // assume rarity 0.
            con_inv.push_back(&Consumable(name, type, val, 0));
        }
        f >> sz;
        for (unsigned i = 0; i < sz; ++i) {
            f >> name >> type >> val >> stat;
            gear_inv.push_back(&Gear(name, val, type, stat));
        }
        f >> sz;
        for (unsigned i = 0; i < sz; ++i) {
            f >> name >> type >> val >> dmg;
            wep_inv.push_back(&Weapon(name, type, dmg, val));
        }
    }
    catch (...) {
        std::cerr << "load from disk failed!" << std::endl;
        return false;
    }

    loadedplayer.equipment = equipment;
    loadedplayer.weapon = weapon;
    loadedplayer.inventory = inventory;
    loadedplayer.con_inv = con_inv;
    loadedplayer.gear_inv = gear_inv;
    loadedplayer.wep_inv = wep_inv;

    p = loadedplayer;

    return true;
}

void SaveSystem::loadSave() {
    std::cout << "Type name of save file to LOAD (type \"exit\" or \"back\" to return) " << std::endl;
    std::string savename;
    std::cin >> savename;
    if (savename == "exit" | savename == "back") return;
    if (LoadFromDisk(savename)) {
        std::cout << "loading " << savename << " successful!" << std::endl;
    }
}

void SaveSystem::saveSave() {
    std::cout << "Type name of save file to SAVE (type \"exit\" or \"back\" to return) " << std::endl;
    std::string savename;
    std::cin >> savename;

    if (savename == "exit" | savename == "back") return;
    std::cout << "Writing " << savename << " to disk" << std::endl;
    if (WriteToDisk(savename)) {
        std::cout << "save successful!" << std::endl;
    }
    return;
}