#pragma once

#include "Entity.h"
#include <vector>


class enemy
{

public:

	enemy(SDL_Renderer* render);
	~enemy();
	
	SDL_Rect src;
	enum moveType
	{
		strLeft,
		strRight,
		strDown,
		strUp,
		waveLeft,
		waveRight,
		waveUp,
		waveDown,
		none
	};

	void move(moveType _type, int enemy, float dt);

	void update(SDL_Event& e, float dt, int currentLevel);
	void start(int amountOfEnemies, std::vector<int> enemyX, std::vector<int> enemyY, std::vector<int> width, std::vector<int> height, SDL_Rect src);
	void collisionEnemy();
	void draw(SDL_Renderer* renderer);

	void setType(int currentLevel) 
	{
		switch (currentLevel)
		{
		case 3:
			type[0] = strDown;
			type[1] = strLeft;
			break;
		case 4:
			type[0] = strDown;
			type[1] = waveRight;
			break;
		case 5:
			type[0] = strUp;
			type[1] = waveLeft;
			break;
		}
	}

	std::vector<SDL_Rect*> getBoundaries() 
	{
		return boundaries;
	}

	std::vector<SDL_Rect*> setBoundaries(int x, int y, int i)
	{
		boundaries[i]->x = x;
		boundaries[i]->y = y;
		return boundaries;
	}

	std::vector<vector2<int>*> setPositions(int x, int y, int i)
	{
		positions[i]->x = x;
		positions[i]->y = y;
		return positions;
	}

private:

	std::vector<moveType> type;
	std::vector<vector2<int>*> positions;
	std::vector<SDL_RendererFlip*> flips;

	std::vector<vector2<int>> startPos;

	std::vector<SDL_Rect*> boundaries;

	std::vector<int> widths;
	std::vector<int> heights;
	SDL_Texture* sprite;

	timer time;
};
