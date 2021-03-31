#include "levelManager.h"


levelManager::levelManager(SDL_Renderer* renderer) 
{

	currentLevel = levels::startMenu;

	textures = new SDL_Texture * [7];
	
	textures[0] = Render::sprite("assets/MainMenuBackGround.png", renderer, textures[0]),
		textures[1] = Render::sprite("assets/gameOverMenu.png", renderer, textures[1]),
		textures[2] = Render::sprite("assets/guideMenu.png", renderer, textures[2]),
		textures[3] = Render::sprite("assets/guide.png", renderer, textures[3]),
		textures[4] = Render::sprite("assets/start.png", renderer, textures[4]),
		textures[5] = Render::sprite("assets/back.png", renderer, textures[5]),
		textures[6] = Render::sprite("assets/quit.png", renderer, textures[6]),

		Player = new player(80, 367, 16, 32, renderer);
		enemiesType1 = new enemy(renderer);
		level1Tiles = new tilemaps(1280 / 32, 704 / 32, renderer, 2);
		Background = new background(0, 0, 1080, 1920, renderer);
		level1Score = new Score(Player->currentPar, renderer);
		platFormAnimation = new animation(0.25, 3, level1Tiles->src, 2, 0, level1Tiles->srcX, level1Tiles->srcY);
		enemyAnimation = new animation(1, 2, enemySrc[0], 8, 6, level1Tiles->srcX, level1Tiles->srcX);
		Goal = new goal;


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

	musicFileNames = new const char* []
	{
		"assets/levelMusic.wav",
		"assets/menu.wav",
		"assets/jump.wav",
	};

	
		
	
	
}

levelManager::~levelManager() 
{
	
}

void levelManager::garabageCollector() 
{
	delete Player;
	delete Background;
	delete level1Tiles;
	delete enemiesType1;
	delete level1Score;
	delete platFormAnimation;
	delete textures;
	delete spriteRects;
	delete soundManager::Instance();
	SDL_DestroyTexture(Player->sprite);
	SDL_DestroyTexture(Background->sprite);
	SDL_DestroyTexture(level1Tiles->tiles);
	for(int i = 0; i < sizeof(textures); i++)
		SDL_DestroyTexture(textures[i]);

	SDL_DestroyTexture(enemiesType1->sprite);
}


void levelManager::start(SDL_Renderer* renderer) 
{
	soundManager::Instance()->loadMusicList(musicFileNames[0]);
	soundManager::Instance()->loadMusicList(musicFileNames[1]);
	soundManager::Instance()->loadMusicList(musicFileNames[2]);

	//level1
	enemyX.push_back(220);
	enemyY.push_back(350);
	enemyH.push_back(32);
	enemyW.push_back(32);

	enemyX.push_back(540);
	enemyY.push_back(220);
	enemyH.push_back(32);
	enemyW.push_back(32);

	//level2
	enemyX.push_back(200);
	enemyY.push_back(150);
	enemyH.push_back(32);
	enemyW.push_back(32);

	enemyX.push_back(1060);
	enemyY.push_back(491);
	enemyH.push_back(32);
	enemyW.push_back(32);


	enemySrc[0].x = 96;
	enemySrc[0].y = 32;
	enemySrc[0].w = 32;
	enemySrc[0].h = 32;
	

	enemiesType1->start(2, enemyX, enemyY, enemyW, enemyH, enemySrc[0]);

	enemiesType1->setType(3);


	Player->start();
	Background->start();
	
	Goal->start(renderer);
	
}

void levelManager::update(SDL_Event& e, bool& isGameRunning, float dt)
{
	
	mouseRect.x = e.motion.x;
	mouseRect.y = e.motion.y;
	mouseRect.w = 0;
	mouseRect.h = 0;
	if (currentLevel == levels::startMenu)
	{
		startMenuUpdate(e, isGameRunning, dt);
	}
	else if (currentLevel == levels::guideMenu)
	{
		guideMenuUpdate(e);
	}
	else if (currentLevel == levels::level1)
	{
		Goal->setIsLevelEnd(false);
		level1Tiles->setLevel("assets/level1.txt");
	}
	else if (currentLevel == levels::level2)
	{
		Goal->setIsLevelEnd(false);
		level1Tiles->setLevel("assets/level2.txt");
	}
	else if (currentLevel == levels::level3)
	{
		Goal->setIsLevelEnd(false);
		level1Tiles->setLevel("assets/level3.txt");
	}
	else if (currentLevel == levels::gameOverMenu)
	{
		//gameOverMenuUpdate(e);
	}

	if (currentLevel != levels::startMenu)
	{
		level1Update(e, dt);
	}
	currentLevel = (levels)Goal->update(e, (int)currentLevel, Player->boundaries, Player->currentPar, level1Score->totalPar, Player->level1Start, Player->hasLevelEnded, Player->position);
	

	if(Goal->getIsLevelEnd() == true)
	{
		if (enemyX.empty() != true)
		{
			enemyX.erase(enemyX.begin());
			enemyX.erase(enemyX.begin(), enemyX.begin() + 1);
			enemyY.erase(enemyY.begin());
			enemyY.erase(enemyY.begin(), enemyY.begin() + 1);

			for (int i = 0; i < enemyX.size(); i++) 
			{
				enemiesType1->setPositions(enemyX[i], enemyY[i], i);
				enemiesType1->setBoundaries(enemyX[i], enemyY[i], i);
				std::cout << enemiesType1->getPositions()[1]->y << std::endl;
			}
		}
		enemiesType1->setType((int)currentLevel);
	}

	soundManager::Instance()->playMusic((int)currentLevel);
		
}

void levelManager::draw(SDL_Renderer* renderer, SDL_Event& e)
{
	
	if (currentLevel == levels::startMenu)
	{
		startMenuDraw(renderer);
	}
	else if (currentLevel == levels::guideMenu)
	{
		guideMenuDraw(renderer);
	}
	else if (currentLevel == levels::level1 || currentLevel == levels::level2 || currentLevel == levels::level3)
	{
		level1Draw(renderer, e);
		
	}
	else if (currentLevel == levels::gameOverMenu)
	{
		//gameOverMenuDraw(renderer);
	}

	
}


void levelManager::startMenuUpdate(SDL_Event& e, bool& isGameRunning, float dt) 
{
	time.startTimer(dt);
	if (collision::entityCollision(mouseRect, *spriteRects[1]) == true) 
	{
		spriteSrc[1]->x = 32;
		
	}
	else 
	{
		spriteSrc[1]->x = 0;
	}

	if (collision::entityCollision(mouseRect, *spriteRects[2]) == true)
	{
		spriteSrc[2]->x = 32;
	}
	else
	{
		spriteSrc[2]->x = 0;
	}

	if (collision::entityCollision(mouseRect, *spriteRects[4]) == true)
	{
		spriteSrc[4]->x = 32;
	}
	else
	{
		spriteSrc[4]->x = 0;
	}
	

	if (time.getElapsedTime() >= 0.25)
	{
		time.pauseTime();
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			switch (e.button.button)
			{
			case SDL_BUTTON_LEFT:

				if (spriteSrc[1]->x >= 32)
				{
					time.stopTimer();
					currentLevel = levels::level1;
				}
				else if (spriteSrc[2]->x >= 32)
				{
					currentLevel = levels::guideMenu;
					
				}
				else if (spriteSrc[4]->x >= 32)
				{
					isGameRunning = false;
				}
				break;
			}

		}
		
	}

}


void levelManager::guideMenuUpdate(SDL_Event& e)
{
	
	if (collision::entityCollision(mouseRect, *spriteRects[1]) == true)
	{
		spriteSrc[3]->x = 32;

	}
	else
	{
		spriteSrc[3]->x = 0;
	}


	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		switch (e.button.button)
		{
		case SDL_BUTTON_LEFT:
			if (spriteSrc[3]->x >= 32)
			{
				time.restartTime();
				time.resumeTime();
				currentLevel = levels::startMenu;
			}
			break;
		}

	}

}


void levelManager::level1Update(SDL_Event& e, float dt) 
{

	platFormAnimation->updateAnimationTile(2, level1Tiles->srcX, level1Tiles->srcY, dt);

	

	for (int i = 0; i < level1Tiles->grid.y; i++)
	{
		for (int j = 0; j < level1Tiles->grid.x; j++)
		{
			Player->tilingCollision(level1Tiles->getTile(j, i), level1Tiles->grid.x, level1Tiles->grid.y, level1Tiles->dest, j, i);
		}
	}

	for (auto& e : enemiesType1->getBoundaries())
	{
		if (collision::entityCollision(Player->boundaries, *e) == true)
		{
			Player->boundaries.x = Player->position.x;
			Player->boundaries.y = Player->position.y;
			Player->setVelocity(0, 0);
			Player->clickCount = 0;

		}

	}
	
	enemiesType1->update(e, dt, (int)currentLevel);
	Player->update(e, dt, (int)currentLevel);
	
}

void levelManager::startMenuDraw(SDL_Renderer* renderer) 
{
	SDL_RenderCopy(renderer, textures[0],0, spriteRects[0]);
	SDL_RenderCopy(renderer, textures[4],spriteSrc[1], spriteRects[1]);
	SDL_RenderCopy(renderer, textures[3], spriteSrc[2], spriteRects[2]);
	SDL_RenderCopy(renderer, textures[6], spriteSrc[4], spriteRects[4]);
}



void levelManager::guideMenuDraw(SDL_Renderer* renderer) 
{
	SDL_RenderCopy(renderer, textures[2], 0, spriteRects[0]);
	SDL_RenderCopy(renderer, textures[5], spriteSrc[3], spriteRects[1]);
}

void levelManager::level1Draw(SDL_Renderer* renderer, SDL_Event& e) 
{
	if (currentLevel == levels::level1)
		currentLevelPar = 0;
	else if (currentLevel == levels::level2)
		currentLevelPar = 1;
	else if (currentLevel == levels::level3)
		currentLevelPar = 2;

	level1Score->update(e, Player->currentPar, renderer, currentLevelPar);
	Background->draw(renderer);
	Goal->draw(renderer);
	level1Tiles->drawLevel(renderer);
	enemiesType1->draw(renderer);
	Player->draw(renderer, e);
	
	level1Score->draw(renderer);
	
}

