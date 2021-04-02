#pragma once
#include "Entity.h"
#include "Enemy.h"
#include "Background.h"
#include "time.h"
#include "score.h"
#include "animation.h"
#include "tilemaps.h"
#include "goal.h"
#include "soundManager.h"


class levelManager 
{
public:

	enum class levels
	{
		startMenu,
		guideMenu,
		level1,
		level2,
		level3,
		gameOverMenu,
	};

	levelManager(SDL_Renderer* render);
	~levelManager();

	player* Player;
	background* Background;
	goal* Goal;

	void update(SDL_Event& e, bool& isGameRunning, float dt);
	void start(SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer, SDL_Event& e);

	void garabageCollector();
private:


	void level1Update(SDL_Event& e, float dt);
	void level2Update(SDL_Event& e, float dt);
	void level3Update(SDL_Event& e, float dt);
	void startMenuUpdate(SDL_Event& e, bool& isGameRunning, float dt);
	void gameOverMenuUpdate(SDL_Event& e, SDL_Renderer* renderer);
	void guideMenuUpdate(SDL_Event& e);
	

	void level1Draw(SDL_Renderer* render, SDL_Event& e);
	void level2Draw(SDL_Renderer* render, SDL_Event& e);
	void level3Draw(SDL_Renderer* render, SDL_Event& e);
	void startMenuDraw(SDL_Renderer* render);
	void gameOverMenuDraw(SDL_Renderer* render);
	void guideMenuDraw(SDL_Renderer* render);
	void PauseDraw(SDL_Renderer* render);


	timer time;
	

	levels currentLevel;

	SDL_Texture** textures;
	SDL_Rect** spriteRects;
	SDL_Rect** spriteSrc;
	SDL_Rect mouseRect;

	std::vector<int> enemyX;
	std::vector<int> enemyY;
	std::vector<int> enemyH;
	std::vector<int> enemyW;

	SDL_Rect enemySrc[2];
	
	tilemaps* level1Tiles;
	Score* level1Score;
	animation* platFormAnimation;
	animation* enemyAnimation;

	enemy* enemiesType1;

	int currentLevelPar;

	const char** musicFileNames;

	bool isLevelEnd;

	std::string finalPar;
	std::string TotalLevelPar;

	std::string finalPlayerScore;
	bool isPressed, gameIsPaused;
	bool isCleared, isFull;
	

};
