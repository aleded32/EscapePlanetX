#include "levelManager.h"


levelManager::levelManager(SDL_Renderer* renderer) 
{

	currentLevel = levels::startMenu;

	textures = new SDL_Texture * [11];
	
	textures[0] = Render::sprite("assets/MainMenuBackGround.png", renderer, textures[0]);
	textures[1] = Render::sprite("assets/gameOverMenu.png", renderer, textures[1]);
	textures[2] = Render::sprite("assets/guideMenu.png", renderer, textures[2]);
	textures[3] = Render::sprite("assets/guide.png", renderer, textures[3]);
	textures[4] = Render::sprite("assets/start.png", renderer, textures[4]);
	textures[5] = Render::sprite("assets/back.png", renderer, textures[5]);
	textures[6] = Render::sprite("assets/quit.png", renderer, textures[6]);
	textures[10] = Render::sprite("assets/pauseMenu.png", renderer, textures[10]);
		

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
		new SDL_Rect,
		new SDL_Rect,
		new SDL_Rect,
		new SDL_Rect
	};

	spriteRects[0]->x = 0; spriteRects[0]->y = 0; spriteRects[0]->h = 704; spriteRects[0]->w = 1280;
	spriteRects[1]->x = 556; spriteRects[1]->y = 510; spriteRects[1]->h = 80; spriteRects[1]->w = 160;
	spriteRects[2]->x = 300; spriteRects[2]->y = 456; spriteRects[2]->h = 80; spriteRects[2]->w = 160;
	spriteRects[3]->x = 812; spriteRects[3]->y = 456; spriteRects[3]->h = 80; spriteRects[3]->w = 160;
	spriteRects[4]->x = 812; spriteRects[4]->y = 456; spriteRects[4]->h = 80; spriteRects[4]->w = 160;
	spriteRects[5]->x = 400; spriteRects[5]->y = 360; spriteRects[5]->h = 32; spriteRects[5]->w = 320;
	spriteRects[6]->x = 400; spriteRects[6]->y = 400; spriteRects[6]->h = 32; spriteRects[6]->w = 320;
	spriteRects[7]->x = 400; spriteRects[7]->y = 440; spriteRects[7]->h = 32; spriteRects[7]->w = 320;

	
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

	
	isPressed = false;
	gameIsPaused = false;
	
	
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
	


	enemySrc[0].x = 96;
	enemySrc[0].y = 32;
	enemySrc[0].w = 32;
	enemySrc[0].h = 32;
	

	


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
	
		
	

	if (currentLevel != levels::startMenu)
	{
		if (e.type == SDL_KEYDOWN && isPressed == false)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				if(gameIsPaused == false)
					gameIsPaused = true;
				else
					gameIsPaused = false;
				break;
			}
			isPressed = true;
		}
		else if (e.type == SDL_KEYUP && isPressed == true)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				isPressed = false;
				break;
			}
		}
		level1Update(e, dt);
	}
	currentLevel = (levels)Goal->update(e, (int)currentLevel, Player->boundaries, Player->currentPar, level1Score->totalPar, Player->level1Start, Player->hasLevelEnded, Player->position);
	

	if(Goal->getIsLevelEnd() == true)
	{
		if (enemyX.empty() != true)
		{

				enemyX.push_back(enemyX[0]);
				enemyX.push_back(enemyX[1]);
				enemyY.push_back(enemyY[0]);
				enemyY.push_back(enemyY[1]);

				enemyX.erase(enemyX.begin());
				enemyX.erase(enemyX.begin(), enemyX.begin() + 1);
				enemyY.erase(enemyY.begin());
				enemyY.erase(enemyY.begin(), enemyY.begin() + 1);

			for (int i = 0; i < enemiesType1->getEnemyAmount(); i++) 
			{
					enemiesType1->setBoundaries(enemyX[i], enemyY[i], i);
					enemiesType1->setPositions(enemyX[i], enemyY[i], i);
					
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
		gameOverMenuUpdate(e, renderer);
		gameOverMenuDraw(renderer);
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

	if (enemyX.empty() == true) 
	{
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

		//level3
		enemyX.push_back(240);
		enemyY.push_back(565);
		enemyH.push_back(32);
		enemyW.push_back(32);

		enemyX.push_back(1060);
		enemyY.push_back(370);
		enemyH.push_back(32);
		enemyW.push_back(32);

		enemyX.push_back(430);
		enemyY.push_back(120);
		enemyH.push_back(32);
		enemyW.push_back(32);

		enemiesType1->start(3, enemyX, enemyY, enemyW, enemyH, enemySrc[0]);

		enemiesType1->setType(3);
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
	if(!gameIsPaused)
		platFormAnimation->updateAnimationTile(2, level1Tiles->srcX, level1Tiles->srcY, dt);

	

	for (int i = 0; i < level1Tiles->grid.y; i++)
	{
		for (int j = 0; j < level1Tiles->grid.x; j++)
		{
			Player->tilingCollision(level1Tiles->getTile(j, i), level1Tiles->grid.x, level1Tiles->grid.y, level1Tiles->dest, j, i);
		}
	}

	if ((int)currentLevel <= 4) 
	{
		for (int i = 0; i < enemiesType1->getBoundaries().size()-1; i++)
		{
			if (collision::entityCollision(Player->boundaries, *enemiesType1->getBoundaries()[i]) == true)
			{
				Player->boundaries.x = Player->position.x;
				Player->boundaries.y = Player->position.y;
				Player->setVelocity(0, 0);
				Player->clickCount = 0;

			}

		}
	}
	else if ((int)currentLevel > 4)
	{
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
	}
	
	enemiesType1->update(e, dt, (int)currentLevel, gameIsPaused);
	Player->update(e, dt, (int)currentLevel, gameIsPaused);
	
}

void levelManager::gameOverMenuUpdate(SDL_Event& e, SDL_Renderer* renderer)
{

	finalPar = "Total Final Par:  " + std::to_string(level1Score->totalPar);
	TotalLevelPar = "Total Level Pars:  " + std::to_string(level1Score->totalLevelPar);


	finalPlayerScore = "Your Total Par: " + std::to_string(level1Score->totalPar - level1Score->totalLevelPar);

	textures[7] = Render::textSprite(finalPar.c_str(), textures[7], {255,255,255,255}, level1Score->getFont(), renderer);
	textures[8] = Render::textSprite(TotalLevelPar.c_str(), textures[8], { 255,255,255,255 }, level1Score->getFont(), renderer);
	textures[9] = Render::textSprite(finalPlayerScore.c_str(), textures[9], { 255,255,255,255 }, level1Score->getFont(), renderer);


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

void levelManager::startMenuDraw(SDL_Renderer* renderer) 
{
	SDL_RenderCopy(renderer, textures[0],0, spriteRects[0]);
	SDL_RenderCopy(renderer, textures[4],spriteSrc[1], spriteRects[1]);
	SDL_RenderCopy(renderer, textures[3], spriteSrc[2], spriteRects[2]);
	SDL_RenderCopy(renderer, textures[6], spriteSrc[4], spriteRects[4]);
}

void levelManager::gameOverMenuDraw(SDL_Renderer* renderer) 
{
	SDL_RenderCopy(renderer, textures[1], 0, spriteRects[0]);
	SDL_RenderCopy(renderer, textures[6], spriteSrc[3], spriteRects[1]);

	
			SDL_RenderCopy(renderer, textures[7], 0, spriteRects[5]);
			SDL_DestroyTexture(textures[7]);

			SDL_RenderCopy(renderer, textures[8], 0, spriteRects[6]);
			SDL_DestroyTexture(textures[8]);

			SDL_RenderCopy(renderer, textures[9], 0, spriteRects[7]);
			SDL_DestroyTexture(textures[9]);
		
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
	enemiesType1->draw(renderer,(int)currentLevel);
	Player->draw(renderer, e , gameIsPaused);
	
	level1Score->draw(renderer);
	PauseDraw(renderer);
	
}

void levelManager::PauseDraw(SDL_Renderer* renderer) 
{
	if (gameIsPaused) 
	{
		SDL_RenderCopy(renderer, textures[10], 0, spriteRects[0]);
	}
}

