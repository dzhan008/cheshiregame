#ifndef _COMBAT_SYSTEM_H_
#define _COMBAT_SYSTEM_H_
#include "stdafx.h"

using namespace std;

class entity;
class player;

class Combat_System{
    private:
        //0 For player turn, 1 for enemy turn
        int turn;
        player* play;
    public:
        Combat_System();
        Combat_System(player* p);
        void runBattle(vector<entity*> enemy);
        void runBattle(entity* enemy);
        void updatePlayer(player* p);
        void updateAllies(vector<Ally*> ally);
    private:
        int randNumber();
        int promptChoices();
        int promptEnemyChoice(vector<entity*> enemy);
        double calculateAccuracy();
        int calculateDamage(bool defend);
        int calculateTurn();
        int attackChoice(int size);
        bool calculateEnemyChoice(entity* enemy);
};

#endif
