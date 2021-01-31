#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>


class Render 
{
public:

	SDL_Texture* Sprite;
	void sprite(SDL_Surface* _surface, const char* file, SDL_Renderer* renderer, SDL_Texture* texture);
	Render();
	~Render();

private:


	SDL_Surface* tmpSurface;
	

};
