#include "goal.h";


goal::goal() 
{
	boundaries.x = 0;
	boundaries.y = 0;
	boundaries.w = 64;
	boundaries.h = 64;
	islevelEnd = false;

}


goal::~goal() {}


void goal::start(SDL_Renderer* renderer)
{
	sprite = Render::sprite("assets/goal.png", renderer, sprite);
}

int goal::update(SDL_Event& e, int level, SDL_Rect& player, int& currentPar, int& totalPar, bool& levelStart, bool& hasLevelEnded, vector2<int> startPos) 
{
	switch (level)
	{
	case 2:
		boundaries.x = 1100;
		boundaries.y = 315;
		break;
	case 3:
		boundaries.x = 1060;
		boundaries.y = 560;
		break;
	case 4:
		boundaries.x = 40;
		boundaries.y = 100;
		break;
	}

	

	if (collision::entityCollision(boundaries, player) == true && islevelEnd == false) 
	{
		
		totalPar += currentPar;
		currentPar = 0;
		levelStart = false;
		hasLevelEnded = false;
		level++;

		
		switch (level)
		{
		case 3:
			player.x = 60;
			player.y = 175;
			break;
		case 4:
			player.x = 85;
			player.y = 580;
			break;
		}
		islevelEnd = true;
		
	}
	
	return level;
}

void goal::draw(SDL_Renderer* renderer) 
{
	SDL_RenderCopy(renderer, sprite, 0, &boundaries);
}