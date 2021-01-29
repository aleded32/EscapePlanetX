#include "game.h"

game::game(const char title[15], int x, int y, int w, int h, Uint32 flag)
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(title, x, y, w, h, flag);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderPresent(renderer);
	gameRunning = true;
}

game::~game(){}

void game::update() 
{
	while (gameRunning) 
	{
		SDL_PollEvent(&e);
		switch (e.type)
		{
		case SDL_QUIT:
			gameRunning = false;
			break;
		}
		render();
	}
}

void game::render() 
{
	SDL_RenderClear(renderer);
	//render here
	SDL_RenderPresent(renderer);
}

void game::clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}