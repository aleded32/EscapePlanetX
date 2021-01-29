#pragma once
#include "SDL.h"
#include <iostream>

class game 
{
public:
	bool gameRunning;
	game(const char title[15], int x, int y, int w, int h, Uint32 flag);
	~game();
	void update();
	void render();
	void clean();


private:
	SDL_Window* window;
	
	SDL_Renderer* renderer;
	SDL_Event e;

};
