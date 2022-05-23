#include "background.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

bool background::init()
{
    pos.getPos(0, 0);
    scale = 1;
    std::string path = "img/background.png";
    if (isNULL())
    {
        if ( Load_Image( path.c_str(), scale ) )
        {
            scale = (double)SCREEN_HEIGHT / Height();
            fixWidth(scale * Width()) ;
            fixHeight(scale * Height()) ;
            return true;
        }
        else
        {
            printf("could not load %s\n", &path);
            return false;
        }
    }
    return false;
}

void background::Free()
{
    free();
    std::cout << "Free background!\n";
}

void background::render()
{
    if (pos.x > -Width() + SCREEN_WIDTH)
    {
        Render(pos.x, pos.y);
    }
    else if (pos.x >= -Width() && pos.x <= -Width() + SCREEN_WIDTH)
    {
        Render(pos.x, pos.y);
        Render(pos.x + Width(), pos.y, 0, NULL, SDL_FLIP_HORIZONTAL);
    }
    else if (pos.x > - 2 * Width() + SCREEN_HEIGHT)
    {
        Render(pos.x + Width(), pos.y, 0, NULL, SDL_FLIP_HORIZONTAL);
    }
    else if (pos.x > - 2 * Width() && pos.x <= - 2 * Width() + SCREEN_HEIGHT)
    {
        Render(pos.x + Width(), pos.y, 0, NULL, SDL_FLIP_HORIZONTAL);
        Render(pos.x + 2 * Width(), pos.y);
    }
    else
    {
        pos.getPos(0, 0);
        Render(pos.x, pos.y);
    }
}

void background::update()
{
    --pos.x;
}

bool leaf::init()
{
    std::string path = "img/leaf.png";
    if (isNULL())
    {
        if ( Load_Image( path.c_str() ) )
        {

            return true;
        }
        else
        {
            printf("could not load %s\n", &path);
            return false;
        }
    }
    return false;
}

void leaf::Free()
{
    free();
    std::cout <<"free leaf!\n";
}

void leaf::update()
{

    if ( pos.size() < 10 )
    {
        position tem;
        int x = rand() % (SCREEN_WIDTH) + 200;
        int y;
        if (x > SCREEN_WIDTH) {
            y = rand() % (SCREEN_HEIGHT << 1) + 30;
        }
        else y = -Height();
        tem.getPos( x,y );
        tem.getAngle(0);
        tem.state = 0;
        pos.push_back(tem);
    }
    for (int i = 0; i < pos.size(); ++i)
    {
        if (!lost)
        {
            pos[i].x -= 2;
            pos[i].y += 1;
            if (pos[i].angle > 75)
            {
                pos[i].state = 0;
            }
            if (pos[i].angle < -15)
            {
                pos[i].state = 1;
            }
            switch(pos[i].state)
            {
            case 1:
                pos[i].angle += 1;
                break;
            case 0:
                pos[i].angle -= 1;
                break;
            }
        }
        else
        {
            pos[i].x -= 1;
            pos[i].y += 1;
            if (pos[i].angle > 75)
            {
                pos[i].state = 0;
            }
            if (pos[i].angle < -15)
            {
                pos[i].state = 1;
            }
            switch(pos[i].state)
            {
            case 1:
                pos[i].angle += 1;
                break;
            case 0:
                pos[i].angle -= 1;
                break;
            }
        }
        if (pos[i].y > SCREEN_HEIGHT || pos[i].x < -Width())
        {
            pos.erase(pos.begin() + i);
        }
    }
}

void leaf::render()
{
    for (int i = 0; i < pos.size(); ++i)
    {
        if (pos[i].x < SCREEN_WIDTH)
        {
            if (pos[i].state == 0) {
                Render(pos[i].x, pos[i].y, pos[i].angle );
            }
            else Render(pos[i].x, pos[i].y, pos[i].angle);
        }
    }
}
