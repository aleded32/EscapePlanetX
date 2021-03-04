#pragma once

#include "Entity.h"
#include <vector>


class enemy
{

public:

	
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

	void update(SDL_Event& e, float dt);
	void start(int amountOfEnemies, std::vector<int> enemyX, std::vector<int> enemyY, std::vector<int> width, std::vector<int> height, SDL_Renderer* render, SDL_Rect src);
	void collisionEnemy();
	void draw(SDL_Renderer* renderer);

	moveType setType(moveType _type, int enemy) 
	{
		type[enemy] = _type;
		return type[enemy];
	}

	std::vector<SDL_Rect*> getBoundaries() 
	{
		return boundaries;
	}

private:

	std::vector<moveType> type;
	std::vector<vector2<int>*> positions;
	std::vector<SDL_RendererFlip*> flips;

	std::vector<vector2<int>> startPos;

	std::vector<SDL_Rect*> boundaries;

	std::vector<int> widths;
	std::vector<int> heights;
	std::vector<SDL_Texture*> sprites;
	SDL_Texture* sprite;
};
