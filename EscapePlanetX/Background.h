#pragma once
#include "Entity.h"

class background : public entity 
{
public:

	background(int _x, int _y, int _h, int _w, SDL_Renderer* render);
	~background();

	void update(SDL_Event& e);
	void start();
	void draw(SDL_Renderer* renderer);

};