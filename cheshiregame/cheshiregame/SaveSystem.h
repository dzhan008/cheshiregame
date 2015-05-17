#ifndef SAVE_SYSTEM_H
#define SAVE_SYSTEM_H
//#include "Town.h"
//class Town;
class SaveSystem
{
private:
    bool WriteToDisk(std::string);
    bool LoadFromDisk(std::string);
public:
    SaveSystem();
    ~SaveSystem();

    void Save(player p);
    void loadSave();
    void saveSave();
    //Town* t;
    player p;
};

#endif