#include "levelManager.h"

levelManager::levelManager(SDL_Renderer* renderer) 
{

	Player = new player(60, 50, 16, 32, renderer);
	enemiesType1 = new enemy(renderer);
	level1Tiles = new tilemaps(w / 32, h / 32, renderer, 2);
	Background = new background(0, 0, 1080, 1920, renderer);
	level1Score = new Score(level1Tiles->getLevelPar(), Player->getCurrentPar(), renderer);
	platFormAnimation = new animation(1, 3, level1Tiles->src, 2, 0, level1Tiles->srcX, level1Tiles->srcY);
	enemyAnimation = new animation(1, 2, enemySrc[0], 8, 6, level1Tiles->srcX, level1Tiles->srcX);


	currentLevel = startMenu;

	textures = new SDL_Texture * [7];
	
		textures[0] = Render::sprite("assets/MainMenuBackGround.png", renderer, textures[0]),
		textures[1] = Render::sprite("assets/gameOverMenu.png", renderer, textures[1]),
		textures[2] = Render::sprite("assets/guideMenu.png", renderer, textures[2]),
		textures[3] = Render::sprite("assets/guide.png", renderer, textures[3]),
		textures[4] = Render::sprite("assets/start.png", renderer, textures[4]),
		textures[5] = Render::sprite("assets/back.png", renderer, textures[5]),
		textures[6] = Render::sprite("assets/quit.png", renderer, textures[6]),


	

	spriteRects = new SDL_Rect*[]
	{
		new SDL_Rect,
		new SDL_Rect,
		new SDL_Rect,
		new SDL_Rect,
		new SDL_Rect

	};

	spriteRects[0]->x = 0; spriteRects[0]->y = 0; spriteRects[0]->h = 720; spriteRects[0]->w = 1280;
	spriteRects[1]->x = 556; spriteRects[1]->y = 456; spriteRects[1]->h = 80; spriteRects[1]->w = 160;
	spriteRects[2]->x = 300; spriteRects[2]->y = 456; spriteRects[2]->h = 80; spriteRects[2]->w = 160;
	spriteRects[3]->x = 812; spriteRects[3]->y = 456; spriteRects[3]->h = 80; spriteRects[3]->w = 160;
	spriteRects[4]->x = 812; spriteRects[4]->y = 456; spriteRects[4]->h = 80; spriteRects[4]->w = 160;

	
	spriteSrc = new SDL_Rect * []
	{
		new SDL_Rect,
		new SDL_Rect,
		new SDL_Rect,
		new SDL_Rect,
		new SDL_Rect
	};

	spriteSrc[0]->x = 0; spriteSrc[0]->y = 0; spriteSrc[0]->h = 16; spriteSrc[0]->w = 32;
	spriteSrc[1]->x = 0; spriteSrc[1]->y = 0; spriteSrc[1]->h = 16; spriteSrc[1]->w = 32;
	spriteSrc[2]->x = 0; spriteSrc[2]->y = 0; spriteSrc[2]->h = 16; spriteSrc[2]->w = 32;
	spriteSrc[3]->x = 0; spriteSrc[3]->y = 0; spriteSrc[3]->h = 16; spriteSrc[3]->w = 32;
	spriteSrc[4]->x = 0; spriteSrc[4]->y = 0; spriteSrc[4]->h = 16; spriteSrc[4]->w = 32;

	
}

levelManager::~levelManager() 
{
	delete Player;
	delete Background;
	delete level1Tiles;
	delete enemiesType1;
	delete level1Score;
	delete platFormAnimation;
	delete textures;
	delete spriteRects;
}


void levelManager::update(SDL_Event& e) 
{

}

void levelManager::draw(SDL_Renderer* renderer) 
{
	if (currentLevel == startMenu) 
	{
		startMenuDraw(renderer);
	}
}


void levelManager::startMenuUpdate(SDL_Event& e) 
{
	
}

void levelManager::startMenuDraw(SDL_Renderer* renderer) 
{
	SDL_RenderCopy(renderer, textures[0],0, spriteRects[0]);
	SDL_RenderCopy(renderer, textures[4],spriteSrc[1], spriteRects[1]);
	SDL_RenderCopy(renderer, textures[3], spriteSrc[2], spriteRects[2]);
	SDL_RenderCopy(renderer, textures[6], spriteSrc[4], spriteRects[4]);
}