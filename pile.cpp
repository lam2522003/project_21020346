#include "pile.h"
#include "stdio.h"

std::vector<position> posPile ;
void pile::PilePosition()
{
    posPile.clear();
    for (int i = 0; i < TOTAL_PILE; ++i)
    {
        position anyOnePile;
        anyOnePile.getPos( SCREEN_WIDTH + i * distance + 300, -(rand() % (2 * getHeight() + holeWidth - SCREEN_HEIGHT)));

        posPile.push_back(anyOnePile);
    }
}
bool pile::init()
{   
    double scale = 4;
    if (isNULL())
    {
        if (Load_Image( "img/pile.png", scale ))
        {
            return true;
        }
        printf("could not open pile.img");
    }
    return false;
}

void pile::Free()
{
    free();
    std::cout << "pile free!\n" ;
}

void pile::render()
{
    for (int i = 0; i < TOTAL_PILE; ++i)
    {
        if (posPile[i].x <= SCREEN_WIDTH && posPile[i].x > -getWidth())
        Render(posPile[i].x, posPile[i].y);
        Render(posPile[i].x, posPile[i].y + getHeight() + holeWidth, 180);
    }
}
void pile::update()
{
    if (!lost)
    {
        for (int j = 0; j < TOTAL_PILE; ++j)
        {
            if (posPile[j].x < - getWidth())
            {
                posPile[j].y = -(rand() % (2 * getHeight() + holeWidth - SCREEN_HEIGHT ));
                posPile[j].x = posPile[(j + TOTAL_PILE - 1) % TOTAL_PILE].x + distance;
            }
            else
               posPile[j].x -= 3;
        }
    }
}
int pile::getHeight()
{ 
    return Height();
}

int pile::getWidth(){
     return Width();
}