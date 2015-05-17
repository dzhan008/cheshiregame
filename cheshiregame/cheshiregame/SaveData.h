#pragma once
#include "Player.h"
#include "Town.h"
struct SaveData
{
    SaveData();
    ~SaveData();
    Town t;
    player p;
};

