#ifndef MAP_H
#define MAP_H
#include "player.h"
#include <vector>
using namespace std;
class map
{
public:
	map();
	map(int mapsize, string& file);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	bool wallcheck(int i, int j);
	void display();
	//void updateplayer(playerposition.first, playerposition.second);
	private:
	//player player1;
	pair <int, int> playerposition;
	vector <vector<int> > mapitems;
	void updateplayer();
};

#endif