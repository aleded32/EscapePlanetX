#include "Entity.h"

player::player(int _x, int _y, int _h, int _w, SDL_Renderer* render)
{
	position.x = _x;
	position.y = _y;
	h = _h;
	w = _w;

	EntityRender.sprite("assets/Ball.png", render, texture);
	isMoving = false;

}

player::~player(){}


void player::start() 
{
	boundaries.x = position.x;
	boundaries.y = position.y;
	boundaries.h = h;
	boundaries.w = w;
}


void player::update(SDL_Event &e)
{
	if (e.type == SDL_KEYDOWN) 
	{
		switch (e.key.keysym.sym) 
		{
		case SDLK_a:
			std::cout << "is pressed" << std::endl;
			break;
		}
	}
	if (e.type == SDL_MOUSEBUTTONDOWN && isMoving == false)
	{
		switch (e.button.button)
		{
		case SDL_BUTTON_LEFT:
			move(e);
			break;
		}
	}
	
	if (isMoving == true) 
	{
			boundaries.x += velocity.x;
			boundaries.y += velocity.y;
	}

	worldCollision();

}


void player::move(SDL_Event &e) 
{
	distance = sqrt(abs((pow(e.motion.x, 2)) - abs(pow(boundaries.x + 32, 2))) + abs((pow(e.motion.y, 2)) - abs(pow(boundaries.y + 32, 2))));


	displacement.x = e.motion.x - (boundaries.x + 32);
	displacement.y = e.motion.y - (boundaries.y + 32);

	

	velocity.x = displacement.x * (15/distance);
	velocity.y = displacement.y * (15/distance);

	
	isMoving = true;
	
}


void player::worldCollision() 
{

	vector2<int> collisionBoundaries(64, 64);
	
	vector2<int> ActualBounderies;

	ActualBounderies.x = boundaries.x + collisionBoundaries.x;
	ActualBounderies.y = boundaries.y + collisionBoundaries.y;

	if (boundaries.x < 0) 
	{
		isMoving = false;
	}
	else if (ActualBounderies.x> 1600) 
	{
		isMoving = false;
	}

	if (boundaries.y < 0) 
	{
		isMoving = false;
	}
	else if (ActualBounderies.y > 800) 
	{
		isMoving = false;
	}
}

void player::draw(SDL_Renderer* renderer) 
{
	SDL_RenderCopy(renderer, EntityRender.Sprite, 0, &boundaries);
}