#include "game.h"

game::game(const char title[15], int x, int y, int w, int h, Uint32 flag)
{

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	window = SDL_CreateWindow(title, x, y, w, h, flag);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderPresent(renderer);
	gameRunning = true;

	SDL_GetWindowSize(window, &w, &h);

	
	LevelManager = new levelManager(renderer);
	LevelManager->start(renderer);
}

game::~game()
{
	delete LevelManager;
}

void game::update() 
{

	
	
	
	while (gameRunning) 
	{
		
		timer::FPSFrameCap60();

		SDL_PollEvent(&e);
		switch (e.type)
		{
		case SDL_QUIT:
			gameRunning = false;
			break;
		}

		float dt = timer::getDeltaTime();
		LevelManager->update(e, gameRunning, dt);
		
		render();

		
		
	}
}


void game::render() 
{

	
	
	SDL_RenderClear(renderer);
	
	

	LevelManager->draw(renderer, e);


	SDL_RenderPresent(renderer);
	
	

}

void game::clean() 
{
	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}