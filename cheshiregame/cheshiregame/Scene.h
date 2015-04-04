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
	void scene_001(player*& p);
	void scene_002(player*& p);

	/*Scene 3*/
	void scene_003(player*& p);
	void scene_003_1(player*& p);
	void scene_003_1_1(player*& p);
	void scene_003_1_2();
	void scene_003_2();
	void scene_003_3(player*& p);
	void scene_003_4();
	void scene_003_4_1();
	void scene_003_4_2();
	void scene_003_4_3();
	void scene_004(bool dead);
	void scene_004_1();
	void scene_004_2();
	void scene_004_3();
};

#endif