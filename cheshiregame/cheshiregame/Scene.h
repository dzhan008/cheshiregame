#ifndef SCENE_H_
#define SCENE_H_

#include <iostream>
#include <string>
#include <vector>
#include "Town.h"

class Scene {
private:
    std::string location;
    std::vector<std::string> options;

public:
    void output_options();
    void set_options(Town &);
	void basic_menu(player* p);

	int user_input();

	/*Story Scenes (Should this be moved somewhere else?)*/

	void scene_play(); //Experimental; It only works for making one input at a time.
	void scene_001();
};

#endif