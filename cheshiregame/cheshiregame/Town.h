#ifndef TOWN_H_
#define TOWN_H_

#include <string>
#include <vector>

class Town {
private:
    std::string name;
    std::vector<std::string> options;
public: 
    std::vector<std::string> get_options();
};

#endif