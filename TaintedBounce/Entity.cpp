#include "Entity.h"

player::player(int _x, int _y, int _h, int _w, SDL_Renderer* render)
{
	position.x = _x;
	position.y = _y;
	h = _h;
	w = _w;

	EntityRender.sprite("assets/Ball.png", render, texture);
	
	isMoving = false;

	gravity = 0.098;

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
			gravity = 0.098;
			CreateDirection(e);
			break;
		}
	}
	
	
	moving();
	worldCollision();

}


void player::CreateDirection(SDL_Event &e) 
{
	
	//distance vector between ball and mouse
	displacement.x = e.motion.x - (boundaries.x + 32);
	displacement.y = e.motion.y - (boundaries.y + 32);

	

	speed = sqrt(abs(pow(displacement.x, 2)) + abs(pow(displacement.y, 2)))/60;

	if (speed < 6) 
	{
		speed = 6;
	}
	else if (speed >= 15) 
	{
		speed = 15;
	}

	std::cout << speed << std::endl;

	//angle in radians between both x and y values atan(y,x) is the angle given between the displacement and 0,0
	AngleMouseBall = atan2(displacement.y, displacement.x);


	
	//cos is used as its the adjacent and hypotenuse of the angle
	velocity.x = cos(AngleMouseBall) * (speed);
	//sin is used as its the oppsite and hyptonuse of the angle.
	velocity.y = sin(AngleMouseBall) * (speed);


	isMoving = true;
	
	
}

void player::moving() 
{

	velocity.y += gravity;
	boundaries.y += velocity.y;

	if (isMoving == true)
	{
		Time.startTimer();
		
		if (Time.getElapsedTime() <= 10)
		{
			boundaries.x += velocity.x;
		}
		else if (Time.getElapsedTime() > 10)
		{
			Time.stopTimer();
			isMoving = false;
		}
	}

	
}



void player::worldCollision() 
{

	vector2<int> collisionBoundaries(66, 66);
	
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
		if (gravity < 1) 
		{
			gravity /= 0.5;
			velocity.y = -velocity.y;
		}
		else
		{
			velocity.y = 0;
			gravity = 0;
			Time.stopTimer();
			isMoving = false;
		}

	}
}

void player::draw(SDL_Renderer* renderer, SDL_Event &e) 
{
	SDL_RenderCopy(renderer, EntityRender.Sprite, 0, &boundaries);
	if(isMoving != true)
		SDL_RenderDrawLine(renderer, e.motion.x, e.motion.y, boundaries.x + 32, boundaries.y + 32);
}