#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
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
	static SDL_Texture* textSprite(const char* text, SDL_Texture* texture, SDL_Color colour, TTF_Font* _font, SDL_Renderer* renderer) { return get().ItextSprite(text, texture, colour, _font, renderer); }
	Render();
	~Render();

private:

	SDL_Texture* Isprite(const char* file, SDL_Renderer* renderer, SDL_Texture* texture);
	SDL_Surface* tmpSurface;
	SDL_Texture* ItextSprite(const char* text, SDL_Texture* texture, SDL_Color colour, TTF_Font* _font, SDL_Renderer* renderer);
	

};
