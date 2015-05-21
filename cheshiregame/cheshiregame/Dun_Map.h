#ifndef MAP_H
#define MAP_H

#include <vector>
#include <utility>
#include "player.h"


using namespace std;
class dun_map
{
public:
	//default constructor
	dun_map();
	//file input constructor
	dun_map(int sz, const string& file);
	//random constructor
	//area = size *size ex: size 10 = 10 * 10 map 
	dun_map(int size);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void moveLeft(int k);
	void moveRight(int k);
	void moveUp(int k);
	void moveDown(int k);
	bool wallcheck(int i, int j);
	void display();
	//bool run(player*& p, Dungeon* d, Combat_System c);
	bool run();
	//removes a wall due to impossible completion
	void wallBreak();
	//void updateplayer(playerposition.first, playerposition.second);
	void runStage();
	void returnToTown();
	dun_map *next;
	//Get functions so it can be used in Dungeon
	int pf(); //returns player's first position (x)
	int ps(); //returns player's second position
	int gf(); //returns goal's first position
	int gs(); //returns goal's second position
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
	pair <int, int> town;
	vector <vector<char> > goalmap;


};

#endif