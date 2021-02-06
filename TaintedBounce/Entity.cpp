#include "Entity.h"

player::player(int _x, int _y, int _h, int _w, SDL_Renderer* render)
{
	position.x = _x;
	position.y = _y;
	h = _h;
	w = _w;

	EntityRender.sprite("assets/Ball.png", render, texture);
	isMoving = false;

	speed = 20.0;

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
	
	//distance vector between ball and mouse
	displacement.x = e.motion.x - (boundaries.x + 32);
	displacement.y = e.motion.y - (boundaries.y + 32);

	//angle in radians between both x and y values atan(y,x) is the angle given between the displacement and 0,0
	AngleMouseBall = atan2(displacement.y, displacement.x);


	
	//cos is used as its the adjacent and hypotenuse of the angle
	velocity.x = cos(AngleMouseBall) * (speed);
	//sin is used as its the oppsite and hyptonuse of the angle.
	velocity.y = sin(AngleMouseBall) * (speed);

	
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
		velocity.x = -velocity.x;
		
	}
	else if (ActualBounderies.x> 1600) 
	{
		velocity.x = -velocity.x;
	}

	if (boundaries.y < 0) 
	{
		velocity.y = -velocity.y;
	}
	else if (ActualBounderies.y > 800) 
	{
		velocity.y = -velocity.y;
	}
}

void player::draw(SDL_Renderer* renderer) 
{
	SDL_RenderCopy(renderer, EntityRender.Sprite, 0, &boundaries);
}