#ifndef SAVESYSTEM_H_
#define SAVESYSTEM_H_

#include <iostream>
#include <vector>
#include "player.h"
#include "Savedata.h"

class Savesystem {
    public:
    Savesystem();
    Savesystem(Savedata);

    bool writedata(std::string);
    bool loaddata(std::string);
    void encryptdata(Savedata);
    void decryptdata(Savedata);
    void demo();
    void save();
    void load();

    private:
    Savedata sd;
}

#endif //SAVESYSTEM_H_
