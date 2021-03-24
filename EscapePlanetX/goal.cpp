#include "goal.h";


goal::goal() 
{
	boundaries.x = 0;
	boundaries.y = 0;
	boundaries.w = 64;
	boundaries.h = 64;


}


goal::~goal() {}


void goal::start(SDL_Renderer* renderer)
{
	sprite = Render::sprite("assets/goal.png", renderer, sprite);
}

int goal::update(SDL_Event& e, int level, SDL_Rect player, int currentPar, int totalPar) 
{
	switch (level)
	{
	case 3:
		boundaries.x = 1280-64;
		boundaries.y = 450;
		break;
	}


	if (collision::entityCollision(boundaries, player) == true) 
	{
		
		totalPar += currentPar;
		level++;
		
	}
	return level;
}

void goal::draw(SDL_Renderer* renderer) 
{
	SDL_RenderCopy(renderer, sprite, 0, &boundaries);
}