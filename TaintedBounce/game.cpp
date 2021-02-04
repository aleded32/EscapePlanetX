#include "game.h"

game::game(const char title[15], int x, int y, int w, int h, Uint32 flag)
{

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(title, x, y, w, h, flag);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 135, 55, 243, 255);
	SDL_RenderPresent(renderer);
	gameRunning = true;

	Player = new player(50, 150, 64, 64, renderer);



}

game::~game()
{
	delete Player;
}

void game::update() 
{


	Player->start();

	while (gameRunning) 
	{

		Time.FPSFrameCap60();

		SDL_PollEvent(&e);
		switch (e.type)
		{
		case SDL_QUIT:
			gameRunning = false;
			break;
		}

		Player->update(e);

		render();

		
		
	}
}

void game::render() 
{

	

	SDL_RenderClear(renderer);

	Player->draw(renderer);

	SDL_RenderPresent(renderer);
	
	

}

void game::clean() 
{
	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}