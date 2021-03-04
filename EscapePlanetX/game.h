#pragma once
#include "SDL.h"
#include "Render.h"
#include "Entity.h"
#include "Enemy.h"
#include "Background.h"
#include "time.h"
#include "tilemaps.h"
#include <iostream>

class game 
{
public:
	bool gameRunning;
	game(const char title[15], int x, int y, int w, int h, Uint32 flag);
	~game();

	void update();
	void collisionUpdate();
	void render();
	void clean();


private:
	SDL_Window* window;

	std::vector<int> enemyX;
	std::vector<int> enemyY;
	std::vector<int> enemyH;
	std::vector<int> enemyW;
	
	SDL_Rect enemySrc[2];

	player* Player;
	background* Background;
	tilemaps* level1;
	enemy* enemiesType1;
	int w, h;
	timer Time;
	
	SDL_Renderer* renderer;
	SDL_Event e;

};
