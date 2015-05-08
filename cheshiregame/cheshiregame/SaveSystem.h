#pragma once
#include "SaveData.h"
class SaveSystem
{
private:
    bool WriteToDisk(std::string);
    bool LoadFromDisk(std::string);
public:
    SaveSystem();
    ~SaveSystem();
    void Save(player, Town);
    void loadSave();
    void saveSave();

private:
    SaveData s;
};