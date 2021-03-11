#include "Enemy.h"


enemy::enemy(SDL_Renderer* render) 
{
	sprite = Render::sprite("assets/tiles.png", render, sprite);
}

enemy::~enemy() {}

void enemy::start(int amountOfEnemies, std::vector<int> enemyX, std::vector<int> enemyY, std::vector<int> width, std::vector<int> height, SDL_Rect _src)
{

	src = _src;

	for (int i = 0; i < amountOfEnemies; i++) 
	{

		positions.push_back(new vector2<int>(enemyX[i], enemyY[i]));
		widths.push_back(width[i]);
		heights.push_back(height[i]);
		
		flips.push_back(new SDL_RendererFlip);

		boundaries.push_back(new SDL_Rect);
		type.push_back(none);

		boundaries[i]->x = positions[i]->x;
		boundaries[i]->y = positions[i]->y;
		boundaries[i]->w = widths[i];
		boundaries[i]->h = heights[i];

		*flips[i] = SDL_FLIP_NONE;
	}

	
}


void enemy::draw(SDL_Renderer* renderer)
{

	SDL_Point point;
	point.x = 16;
	point.y = 16;
	
	for (size_t i = 0; i < boundaries.size(); i++) 
	{
		SDL_RenderCopyEx(renderer, sprite, &src, boundaries[i], 0, &point, *flips[i]);
		
	}

	
}


void enemy::update(SDL_Event &e, float dt) 
{
	
	
	if (boundaries[0]->x < positions[0]->x - 50)
		type[0] = strRight;
	else if (boundaries[0]->x > positions[0]->x + 400)
		type[0] = strLeft;

	if (boundaries[1]->y < positions[1]->y - 140)
		type[1] = waveDown;
	else if (boundaries[1]->y > positions[1]->y + 140)
		type[1] = waveUp;
	

		move(type[0], 0, dt);
		move(type[1], 1, dt);
	
}


void enemy::move(moveType type, int enemy, float dt) 
{
	timer::startTimer();

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
		case enemy::waveLeft:
			boundaries[enemy]->y += 1* (sin(2 * M_PI * 0.25 *(int)timer::getElapsedTimer()) + 0);
			boundaries[enemy]->x -= 1.5 * dt;
			*flips[enemy] = SDL_FLIP_NONE;
			break;
		case enemy::waveRight:
			boundaries[enemy]->y += 1 * (sin(2 * M_PI * 0.25 * (int)timer::getElapsedTimer()) + 0);
			boundaries[enemy]->x += 1.5 * dt;
			*flips[enemy] = SDL_FLIP_HORIZONTAL;
			break;
		case enemy::waveUp:
			boundaries[enemy]->x += 1 * (sin(2 * M_PI * 0.25 * (int)timer::getElapsedTimer()) + 0);
			boundaries[enemy]->y -= 1.5 * dt;
			break;
		case enemy::waveDown:
			boundaries[enemy]->x += 1 * (sin(2 * M_PI * 0.25 * (int)timer::getElapsedTimer()) + 0);
			boundaries[enemy]->y += 3 * dt;
			break;
		}

		
		
	}
	
}

