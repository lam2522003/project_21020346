#include "mySDL.h"
#include <iostream>

bool TheTexture::quit = false;
SDL_Window* TheTexture::gWindow = NULL;
SDL_Renderer* TheTexture::gRenderer = NULL;
TTF_Font* TheTexture::Font = NULL;
SDL_Event TheTexture::event;
int TheTexture::countedFrame = -1;
int TheTexture::score = 0;
bool TheTexture::lost = true;
void TheTexture::free()
{
	if( Texture != NULL )
	{
		SDL_DestroyTexture( Texture );
		Texture = NULL;
		ImageWidth = 0;
		ImageHeight = 0;
	}
}

void TheTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( Texture, red, green, blue );
}

void TheTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( Texture, blending );
}

void TheTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( Texture, alpha );
}

int TheTexture::Width()
{
	return ImageWidth;
}

int TheTexture::Height()
{
	return ImageHeight;
}

void TheTexture::Render(int x, int y, double angle, SDL_Rect* clip, SDL_RendererFlip flip)
{
	
	SDL_Rect Rec_Render = { x, y, ImageWidth, ImageHeight };

    if( clip != NULL )
	{
		Rec_Render.w = clip->w ;
		Rec_Render.h = clip->h ;
	}

    SDL_RenderCopyEx( gRenderer, Texture, clip, &Rec_Render, angle, NULL, flip );
}
bool TheTexture::Load_Image( std::string path, double scale )
{
	free();
	bool success = true ;
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
		success = false ;
	}
	else
	{
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0x00, 0xFF, 0xFF ) );

        Texture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( Texture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
			success = false ;
		}
		else
		{
			ImageWidth = (loadedSurface->w) * scale;
			ImageHeight = (loadedSurface->h) * scale;
		}

		SDL_FreeSurface( loadedSurface );
	}
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	return success ;

}

void TheTexture::Load_Text( std::string text, int scale )
{
    free();
    SDL_Color Text_Color = { 255, 255, 255 };
    SDL_Surface* Text_Surface = TTF_RenderText_Solid( Font, text.c_str(), Text_Color );
    ImageWidth = Text_Surface->w * scale;
    ImageHeight = Text_Surface->h * scale;
    Texture = SDL_CreateTextureFromSurface( gRenderer, Text_Surface );
    SDL_FreeSurface( Text_Surface );
}
TheTexture::TheTexture()
{
    Texture = NULL;
}


bool TheTexture::isNULL()
{
    if (Texture == NULL) return true;
    return false;
}

void TheTexture::fixWidth(int newWidth)
{
    ImageWidth = newWidth;
}

void TheTexture::fixHeight(int newHeight)
{
    ImageHeight = newHeight;
}

void position::getPos(const int x,const int y)
{
    this->x = x;
    this->y = y;
}

void position::getAngle(double newAngle)
{
    angle = newAngle;
}
