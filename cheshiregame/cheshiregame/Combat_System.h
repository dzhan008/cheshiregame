#ifndef _COMBAT_SYSTEM_H_
#define _COMBAT_SYSTEM_H_

#include "Player.h"
#include "Entity.h"
#include "Ally.h"

using namespace std;

class Combat_System{
	private:
		//0 For player turn, 1 for enemy turn
		int turn;
		player* play;
		vector<Ally*> allies;
	public:
		Combat_System();
		Combat_System(player* p);
		Combat_System(player* p, vector<Ally*> allies);
		void runBattle(vector<Entity*> enemy);
		void runBattle(Entity* enemy);
		void updatePlayer(player* p);
		void updateAllies(vector<Ally*> ally);
        private:
		int randNumber();
		int promptChoices();
		int promptEnemyChoice(vector<Entity*> enemy);
		double calculateAccuracy();
		int calculateDamage(bool defend);
		int calculateTurn();
		int attackChoice(int size);
		bool calculateEnemyChoice(Entity* enemy);
		bool calculateAllyChoice(Ally* ally);
};

#endif
