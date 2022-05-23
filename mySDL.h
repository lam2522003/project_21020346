#ifndef MYSDL_H
#define MYSDL_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <stdio.h>


class position
{
public:
    int x, y, state  ;
    double angle ;
    void getPos(const int x,const int y);
    void getAngle(double newAngle);
};


class TheTexture
{
    int ImageWidth;
    int ImageHeight;
public:
    static SDL_Window* gWindow ;
    static SDL_Renderer* gRenderer ;
    static TTF_Font* Font ;
    static bool quit ;
    static bool lost ;
    static SDL_Event event ;
    static int countedFrame ;
    static int score;

    static const int SCREEN_WIDTH = 1200;
    static const int SCREEN_HEIGHT = 720;
    static const int Font_Size = 2 ;

    static const int holeWidth = 150 ;
    static const int TOTAL_PILE = 5 ;
    static const int distance = 280 ;

    TheTexture();

    ~TheTexture() {}

    bool isNULL();

    void free();

    void setColor( Uint8 red, Uint8 green, Uint8 blue );

 
    bool Load_Image(std::string path, double scale = 1);

    void Load_Text(std::string text, int scale = 1);

    void Render(int x, int y, double angle = 0, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void setBlendMode( SDL_BlendMode blending = SDL_BLENDMODE_BLEND);

    void setAlpha( Uint8 alpha );

    int Width();
    int Height();

    void fixWidth(int newWidth);

    void fixHeight(int newHeight);

    SDL_Texture* Texture;
  
};

#endif
