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
    int user_input();
};

#endif