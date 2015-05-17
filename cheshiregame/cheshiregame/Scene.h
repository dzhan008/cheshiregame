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
	std::string line = "------------------------------------------------------------";

public:
    void output_options();
    void set_options(Town &);
	void basic_menu(player* p);

	bool check_val(std::string);
	bool check_val(int);

	void next_input();

	int user_input();

	/*Story Scenes (Should this be moved somewhere else?)*/

	void scene_play(); //Experimental; It only works for making one input at a time.
	void scene_001(player* p);
	//void scene_002(player* p); Need to rename scenes....

	/*Scene 3*/
	bool astuce_alive = true;

	void scene_003(player* p);
	void scene_003_1(player* p);
	void scene_003_1_1(player* p);
	void scene_003_1_2();
	void scene_003_2(player* p);
	void scene_003_3(player* p);
	void scene_003_4(player* p);
	void scene_003_4_1(player* p);
	void scene_003_4_2();
	void scene_003_4_3();
	void scene_004(bool dead);
	void scene_004_1();
	void scene_004_2();
	void scene_004_3();

	void scene_005(); //Boss fight!
	void scene_006(); //Ending
};

#endif