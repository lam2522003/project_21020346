#ifndef BIRD_H
#define BIRD_H

#include "mySDL.h"
#include "pile.h"

class bird : TheTexture
{
    int angle, time, x0 ;
    position pos;
    const double scale = 1;
    int ahead = 0;
public:
    bool init();

    void render();

    void Free();

    void resetTime() { time = 0;}

    void update(int pileWidth, int pileHeight);

    void updateState();
    
};

#endif 
