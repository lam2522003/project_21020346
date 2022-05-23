#include "bird.h"
#include <stdio.h>
#include <iostream>

bool bird::init()
{
    pos.getPos(50, SCREEN_HEIGHT / 2);
    ahead = 0;
    if (isNULL())
    {
        if ( Load_Image( "img/bird.png", scale ) )
        {
            angle = 0;
            time = -1;
            return true;
        }
        else
        {
            printf("could not load bird.img\n");
            return false;
        }
    }
    return false;
}

void bird::Free()
{
    free();
    std::cout << "bird free!\n";
}

void bird::render()
{
    Render(pos.x, pos.y, angle);
}

void bird::updateState()
{
    if (!lost)
    {
        if (time == 0)
        {
            x0 = pos.y ;
            angle = -20;
        }
        if (angle < 70 && time > 30)
        {
            angle += 3;
        }
        if (time >= 0)
        {
            pos.y = x0 + time * time * 0.19 - 8 * time;
            ++time;
        }
    }
}
void bird::update(int pileWidth, int pileHeight){
        if ((pos.x + Width() > posPile[ahead].x + 3) &&
            (pos.x + 3 < posPile[ahead].x + pileWidth) &&
            (pos.y + 5 < posPile[ahead].y + pileHeight ||
              pos.y  + Height() - 5 > posPile[ahead].y + pileHeight + holeWidth ))
        {
            lost = true;
        }
        if ( pos.y - 10 > SCREEN_HEIGHT ||
                pos.y < - 10 )
        {
            lost = true;
        }
        if ( pos.x > posPile[ahead].x + pileWidth )
        {
            ahead = ( ahead + 1 ) % TOTAL_PILE;
            ++score;
        }
    }

