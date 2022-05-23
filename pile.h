#ifndef PILE_H
#define PILE_H

#include <vector>
#include "mySDL.h"
#include <iostream>

extern std::vector<position> posPile;

class pile : TheTexture
{
public:
    void PilePosition();
    
    bool init();

    void Free();

    void render();

    void update();

    int getHeight();

    int getWidth();
};

#endif 
