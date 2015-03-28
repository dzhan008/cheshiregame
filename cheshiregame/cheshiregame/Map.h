#ifndef MAP_H
#define MAP_H
#include "player.h"
#include <vector>
using namespace std;
class map
{
public:
	//default constructor
	map();
	//file input constructor
	map(int mapsize, string& file);
	//random constructor
	//area = size *size ex: size 10 = 10 * 10 map 
	map(int size);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	bool wallcheck(int i, int j);
	void display();
	void run();
	//removes a wall due to impossible completion
	void wallBreak();
	//void updateplayer(playerposition.first, playerposition.second);
	private:
	//player player1;
	pair <int, int> playerposition;
	vector <vector<int> > mapitems;
	void updateplayer();
	pair <int, int> goal;
	vector <vector<int> > goalmap;
	
};

#endif