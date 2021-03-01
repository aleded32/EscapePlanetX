#include "Background.h"


background::background(int _x, int _y, int _h, int _w, SDL_Renderer* render)
{
	position.x = _x;
	position.y = _y;

	h = _h;
	w = _w;

	sprite = Render::sprite("assets/Background.png", render, sprite);

	
}

background::~background() {}

void background::start() 
{
	boundaries.x = position.x;
	boundaries.y = position.y;
	boundaries.h = h;
	boundaries.w = w;
}


void background::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, sprite, 0, &boundaries);
}