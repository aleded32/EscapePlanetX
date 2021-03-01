#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>


class Render 
{
public:

	Render(const Render&) = delete;

	static Render& get() 
	{
		Render instance;
		return instance;
	}

	static SDL_Texture* sprite(const char* file, SDL_Renderer* renderer, SDL_Texture* texture) { return get().Isprite(file, renderer, texture); }
	
	Render();
	~Render();

private:

	SDL_Texture* Isprite(const char* file, SDL_Renderer* renderer, SDL_Texture* texture);
	SDL_Surface* tmpSurface;
	

};
