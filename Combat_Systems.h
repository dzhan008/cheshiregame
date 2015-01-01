//WIP, Need to finish functions and alter function calls to the same as the other classes

#ifndef _COMBAT_SYSTEM_H_
#define _COMBAT_SYSTEM_H_

using namespace std;

class Combat_System{
    private:
        //0 For player turn, 1 for enemy turn
        int turn;
        vector<Monster> enemies;
        Player player;
    public:
        Combat_System();
        Combat_System(Player p);
        void runBattle(vector<Monster> enemy);
        void updatePlayer(Player p);
    private:
        int randNumber();
        int promptChoices();
        int promptEnemyChoice();
        double calculateAccuracy();
        int calculateDamage(bool defend);
        int calculateTurn();
        int calculateEnemyChoice();
};

#endif
