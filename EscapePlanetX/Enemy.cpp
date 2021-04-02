#include "Enemy.h"


enemy::enemy(SDL_Renderer* render) 
{
	sprite = Render::sprite("assets/tiles.png", render, sprite);
}

enemy::~enemy() {}

void enemy::start(int _amountOfEnemies, std::vector<int> enemyX, std::vector<int> enemyY, std::vector<int> width, std::vector<int> height, SDL_Rect _src)
{
	amountOfEnemies = _amountOfEnemies;
	src = _src;

	positions.clear();
	boundaries.clear();
	type.clear();
	flips.clear();
	widths.clear();
	heights.clear();

	

	for (int i = 0; i < amountOfEnemies; i++) 
	{
		

		positions.push_back(new vector2<int>(enemyX[i], enemyY[i]));
		widths.push_back(width[i]);
		heights.push_back(height[i]);
		
		flips.push_back(new SDL_RendererFlip);

		boundaries.push_back(new SDL_Rect);
		type.push_back(moveType::none);

		boundaries[i]->x = positions[i]->x;
		boundaries[i]->y = positions[i]->y;
		boundaries[i]->w = widths[i];
		boundaries[i]->h = heights[i];

		

		*flips[i] = SDL_FLIP_NONE;
	}
	
	
}


void enemy::draw(SDL_Renderer* renderer, int currentLevel)
{

	SDL_Point point;
	point.x = 16;
	point.y = 16;

	
	
	if (currentLevel < 4 && currentLevel > 1)
	{
		for (size_t i = 0; i < 2; i++)
		{
			
			SDL_RenderCopyEx(renderer, sprite, &src, boundaries[i], 0, &point, *flips[i]);

		}
	}
	
	if (currentLevel > 3 && currentLevel < 5) 
	{
		for (size_t i = 0; i < 3; i++)
		{
			
			SDL_RenderCopyEx(renderer, sprite, &src, boundaries[i], 0, &point, *flips[i]);

		}
	}
	
	

	
}


void enemy::update(SDL_Event &e, float dt, int currentLevel, bool& isGamePaused)
{
	
	
	
	

	switch(currentLevel)
	{
	case 2:
		if (boundaries[1]->x < positions[1]->x - 100)
			type[1] = strRight;
		if (boundaries[1]->x > positions[1]->x + 100)
			type[1] = strLeft;

		if (boundaries[0]->y < positions[0]->y - 80)
			type[0] = strDown;
		 if (boundaries[0]->y > positions[0]->y + 80)
			type[0] = strUp;
		break;
	case 3:
		if (boundaries[1]->x < positions[1]->x - 60)
			type[1] = diagonalRight;
		else if (boundaries[1]->x > positions[1]->x + 60)
			type[1] = diagonalLeft;

		if (boundaries[0]->y < positions[0]->y - 60)
			type[0] = strDown;
		if (boundaries[0]->y > positions[0]->y + 60)
			type[0] = strUp;
		break;
	case 4:
		if (boundaries[1]->x < positions[1]->x - 80)
			type[1] = diagonalRight;
		if (boundaries[1]->x > positions[1]->x + 80)
			type[1] = diagonalLeft;

		if (boundaries[0]->y < positions[0]->y - 60)
			type[0] = strDown;
		if (boundaries[0]->y > positions[0]->y + 60)
			type[0] = strUp;

		if (boundaries[2]->x < positions[2]->x - 50)
			type[2] = diagonalRight;
		if (boundaries[2]->x > positions[2]->x + 50)
			type[2] = diagonalLeft;
		break;

	}
	
	if(!isGamePaused) 
	{

		
		move(type[0], 0, dt);
		move(type[1], 1, dt);
		move(type[2], 2, dt);
	}
	
}


void enemy::move(moveType type, int enemy, float dt) 
{
	

	

	srand(time(NULL));


	if (enemy < boundaries.size() && enemy > -1) 
	{
		
		switch (type)
		{
		case enemy::strLeft:
			boundaries[enemy]->x -= 4 * dt;
			*flips[enemy] = SDL_FLIP_NONE;
			break;
		case enemy::strRight:
			boundaries[enemy]->x += 4 * dt;
			*flips[enemy] = SDL_FLIP_HORIZONTAL;
			break;
		case enemy::strDown:
			boundaries[enemy]->y += 4 * dt;
			break;
		case enemy::strUp:
			boundaries[enemy]->y -= 4 * dt;
			break;
		case enemy::diagonalLeft:
			boundaries[enemy]->y -= 1.7 * dt;
			boundaries[enemy]->x -= 1.7 * dt;
			*flips[enemy] = SDL_FLIP_NONE;
			break;
		case enemy::diagonalRight:
			boundaries[enemy]->y +=  1.7 * dt;
			boundaries[enemy]->x +=  1.7 * dt;
			*flips[enemy] = SDL_FLIP_HORIZONTAL;
			break;
	
		}

		
		
	}
	
}

