#ifndef MAP_H
#define MAP_H

#include <vector>
#include "player.h"


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
	//bool run(player*& p, Dungeon* d, Combat_System c);
	bool run();
	//removes a wall due to impossible completion
	void wallBreak();
	//void updateplayer(playerposition.first, playerposition.second);
	void runStage();
	map *next;

	private:
	//player player1;
	//coordinates x,y of a players position
	pair <int, int> playerposition;
	//x * x vector of a map
	vector <vector<char> > mapitems;
	//updates player position on mapitems
	void updateplayer();
	// xy of the goal location
	pair <int, int> goal;
	vector <vector<char> > goalmap;

	
};

#endif