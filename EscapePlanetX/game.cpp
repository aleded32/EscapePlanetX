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

	Player = new player(60, 50, 16, 32, renderer);
	enemiesType1 = new enemy(renderer);
	level1 = new tilemaps(w/32, h/32, renderer, 2);
	Background = new background(0, 0, 1080,1920, renderer);
	level1Score = new Score(level1->getLevelPar(), Player->getCurrentPar(), renderer);
	
	
	
	
}

game::~game()
{
	delete Player;
	delete Background;
	delete level1;
	delete enemiesType1;
	delete level1Score;
}

void game::update() 
{

		enemyX.push_back(200);
		enemyY.push_back(230);
		enemyH.push_back(32);
		enemyW.push_back(32);

		enemyX.push_back(850);
		enemyY.push_back(200);
		enemyH.push_back(32);
		enemyW.push_back(32);



	
	
	enemySrc[0].x = 96;
	enemySrc[0].y = 32;
	enemySrc[0].w = 32;
	enemySrc[0].h = 32;

	
		enemiesType1->start(2, enemyX, enemyY, enemyW, enemyH,enemySrc[0]);

		enemiesType1->setType(enemiesType1->strLeft, 0);
		enemiesType1->setType(enemiesType1->waveUp, 1);
	
	
	Player->start();
	Background->start();
	level1->setLevel("assets/level1.txt");

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

		enemiesType1->update(e, dt);
		Player->update(e, dt);
		level1Score->update(e, Player->getCurrentPar(), renderer);
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

	for (auto& e : enemiesType1->getBoundaries())
	{
		if (collision::entityCollision(Player->boundaries, *e) == true)
		{
			Player->boundaries.x = Player->startPos.x;
			Player->boundaries.y = Player->startPos.y;

		}

	}

}

void game::render() 
{

	

	SDL_RenderClear(renderer);

	Background->draw(renderer);
	level1->drawLevel(renderer);
	enemiesType1->draw(renderer);
	Player->draw(renderer, e);
	level1Score->draw(renderer);

	SDL_RenderPresent(renderer);
	
	

}

void game::clean() 
{
	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}