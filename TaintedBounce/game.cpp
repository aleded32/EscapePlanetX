#include "game.h"

game::game(const char title[15], int x, int y, int w, int h, Uint32 flag)
{

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(title, x, y, w, h, flag);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderPresent(renderer);
	gameRunning = true;

	Player = new player(0, 736, 64, 64, renderer);
	Background = new background(0, 0, 800,1600, renderer);


}

game::~game()
{
	delete Player;
	delete Background;
}

void game::update() 
{

	
	Player->start();
	Background->start();

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

	Background->draw(renderer);
	Player->draw(renderer, e);
	

	SDL_RenderPresent(renderer);
	
	

}

void game::clean() 
{
	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}