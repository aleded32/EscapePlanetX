#pragma once
#include "SDL.h"
#include "Render.h"
#include "Entity.h"
#include "Enemy.h"
#include "Background.h"
#include "time.h"
#include "score.h"
#include "animation.h"
#include "tilemaps.h"
#include <iostream>


class levelManager 
{
public:

	enum levels
	{
		startMenu,
		guideMenu,
		gameOverMenu,
		level1,
		level2,
		level3
	};

	levelManager(SDL_Renderer* render);
	~levelManager();

	void update(SDL_Event& e);
	void start();
	void draw(SDL_Renderer* renderer);
private:

	void level1Update(SDL_Event& e);
	void level2Update(SDL_Event& e);
	void level3Update(SDL_Event& e);
	void startMenuUpdate(SDL_Event& e);
	void gameOverMenuUpdate(SDL_Event& e);
	void guideMenuUpdate(SDL_Event& e);

	void level1Draw(SDL_Renderer* render);
	void level2Draw(SDL_Renderer* render);
	void level3Draw(SDL_Renderer* render);
	void startMenuDraw(SDL_Renderer* render);
	void gameOverMenuDraw(SDL_Renderer* render);
	void guideMenuDraw(SDL_Renderer* render);


	levels currentLevel;

	SDL_Texture** textures;
	SDL_Rect** spriteRects;
	SDL_Rect** spriteSrc;
	


	std::vector<int> enemyX;
	std::vector<int> enemyY;
	std::vector<int> enemyH;
	std::vector<int> enemyW;

	SDL_Rect enemySrc[2];

	player* Player;
	background* Background;
	tilemaps* level1Tiles;
	Score* level1Score;
	animation* platFormAnimation;
	animation* enemyAnimation;

	enemy* enemiesType1;
	int w, h;

};
