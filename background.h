#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "mySDL.h"
#include <vector>

class background : TheTexture
{
    position pos;
    double scale;
public:
    bool init();

    void Free();

    void render();

    void update();

};

class leaf : TheTexture
{

    std::vector<position> pos;

public:

    bool init();

    void Free();

    void update();

    void render();
};

#endif 
