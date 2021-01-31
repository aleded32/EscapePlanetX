#include "game.h"

game::game(const char title[15], int x, int y, int w, int h, Uint32 flag)
{

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(title, x, y, w, h, flag);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 135, 55, 243, 255);
	SDL_RenderPresent(renderer);
	gameRunning = true;

	//load textures and set sprites
	playerRender->sprite(playerSurface, "assets/Ball.png", renderer, playerText);


}

game::~game()
{
	delete playerRender;
}

void game::update() 
{
	playerR.h = 64;
	playerR.w = 64;
	playerR.x = 800;
	playerR.y = 400;

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
	SDL_RenderCopy(renderer, playerRender->Sprite, NULL, &playerR);
	SDL_RenderPresent(renderer);
	
	

}

void game::clean() 
{
	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}