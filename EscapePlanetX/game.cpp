#include "game.h"

game::game(const char title[15], int x, int y, int w, int h, Uint32 flag)
{

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(title, x, y, w, h, flag);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderPresent(renderer);
	gameRunning = true;

	SDL_GetWindowSize(window, &w, &h);

	Player = new player(50, 50, 16, 32, renderer);
	level1 = new tilemaps(w/32, h/32, renderer);
	Background = new background(0, 0, 1080,1920, renderer);


}

game::~game()
{
	delete Player;
	delete Background;
	delete level1;
}

void game::update() 
{

	
	Player->start();
	Background->start();
	level1->setLevel("assets/level1.txt");

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
		collisionUpdate();

		render();

		
		
	}
}

void game::collisionUpdate() 
{
	
	for (int i = 0; i < level1->grid.y; i++) 
	{
		for (int j = 0; j < level1->grid.x; j++)
		{
			Player->tilingCollisionLevel1(level1->getTile(j, i), level1->grid.x, level1->grid.y, level1->dest, j, i);
		}
	}
}

void game::render() 
{

	

	SDL_RenderClear(renderer);

	Background->draw(renderer);
	level1->drawLevel(renderer);
	Player->draw(renderer, e);
	

	SDL_RenderPresent(renderer);
	
	

}

void game::clean() 
{
	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}