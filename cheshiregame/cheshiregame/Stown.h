/* Sample town Stown*/
#ifndef STOWN_H_
#define STOWN_H_

#include <string>
#include <vector>
#include "Shop.h"
#include "Town.h"

class Stown : public Town {
private: 
    Shop s;
    

public: 
    Stown();
    bool interpret_input(int n);
};
#endif