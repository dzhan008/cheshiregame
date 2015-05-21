#ifndef _GAME_H_
#define _GAME_H_

#include "stdafx.h"

class Skill;

class Game
{
	public:
		Game();
		Game(std::string file_name);
		void intialize() const; //Initializes anything needed for the game. This is run first in main.
		Skill get_skill(int index);
		void fill_skills(std::string file_name);

	private:
		std::vector<Skill> skills;





};

#endif