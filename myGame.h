#ifndef MYGAME_H
#define MYGAME_H

#include "bird.h"
#include "pile.h"
#include "background.h"
#include "Sound.h"
#include <string>

class game : TheTexture
{
public:
    struct input{
        enum type { QUIT, CLICK, NONE };
        type Type;
    };
    input UserInput;
    bird Bird;
    pile Pile;
    sound Sound;
    background Background;
    leaf FallingLeaf;
    
    game();

    ~game();

    void takeInput();

    bool isQuit() {return quit; }

    void openFont( std::string );

    void display();

    bool initGraphic();

    void releaseGraphic();

    int getPileWidth() { return Pile.getWidth();}

    int getPileHeight() {  return Pile.getHeight();}

    int Score(){
        return score ;
    };
    
    void renderScore();

    void renderMaxScore(int maxScore);

    bool isLost() {return lost;}

    void LoadText(std::string t);

    void renderText();

    void Restart();

    int getCountedFrame();

};

#endif // MYGAME_H
