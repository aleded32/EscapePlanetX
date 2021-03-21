#include "Entity.h"

player::player(int _x, int _y, int _h, int _w, SDL_Renderer* render)
{
	position.x = _x;
	position.y = _y;
	h = _h;
	w = _w;

	sprite = Render::sprite("assets/player.png", render, sprite);
	
	isMoving = false;
	isPressed = false;

	gravity = 0.098;
	clickCount = 0;

	collisionBoundaries = new vector2<int>(34, 18);

	currentPar = 0;

	


}

player::~player()
{
	delete collisionBoundaries;
}


void player::start() 
{
	boundaries.x = position.x;
	boundaries.y = position.y;
	boundaries.h = h;
	boundaries.w = w;
}


void player::update(SDL_Event &e, float dt)
{
	
	if (e.type == SDL_MOUSEBUTTONDOWN && isPressed == false)
	{
		switch (e.button.button)
		{
		case SDL_BUTTON_LEFT:
			
			if(clickCount < 2 && cantAim == false)
			{
				gravity = 0.098;
				CreateDirection(e,dt);
				clickCount++;
				currentPar++;
			}
				
			isMoving = true;
			isPressed = true;
			break;
		}

	}
	else if (e.type == SDL_MOUSEBUTTONUP && isPressed == true)
	{
		switch (e.button.button)
		{
		case SDL_BUTTON_LEFT:
			isPressed = false;
			break;
		}

	}
	
	
	worldCollision();
	

}


void player::CreateDirection(SDL_Event &e, float dt) 
{
	
	//distance vector between ball and mouse
	displacement.x = e.motion.x - (boundaries.x + 16);
	displacement.y = e.motion.y - (boundaries.y + 8);

	

	speed = sqrt(abs(pow(displacement.x, 2)) + abs(pow(displacement.y, 2)))/60;

	if (speed < 3) 
	{
		speed = 3;
	}
	else if (speed >= 13) 
	{
		speed = 13;
	}


	//angle in radians between both x and y values atan(y,x) is the angle given between the displacement and 0,0
	AngleMouseBall = atan2(displacement.y, displacement.x);


	
	//cos is used as its the adjacent and hypotenuse of the angle
	velocity.x = cos(AngleMouseBall) * speed * dt;
	//sin is used as its the oppsite and hyptonuse of the angle.
	velocity.y = sin(AngleMouseBall) * speed * dt;

	
	
	
}

void player::worldCollision() 
{
	startPos.x = 50;
	startPos.y = 200;

	ActualBounderies.x = boundaries.x + collisionBoundaries->x;
	ActualBounderies.y = boundaries.y + collisionBoundaries->y;

	

	if (ActualBounderies.y > 720) 
	{
		boundaries.x = startPos.x;
		boundaries.y = startPos.y;
		velocity.y = 0;
		clickCount = 0;
		velocity.x = 0;
		
	}
		moving();
	
}

void player::tilingCollisionLevel1(int tile, int tileX, int tileY, SDL_Rect dest, int j, int i) 
{

	//wall
	for (int u = 1; u < 8; u++)
	{
		
		if (collision::DownTileCollision(boundaries, dest, tile, tileX, tileY, u, i, j) == true && getVelocity().y < 0)
		{
			std::cout << "down" << std::endl;
			boundaries.y = (32 * i) + 34;
			setVelocity(0, gravity);
		}

		else if (collision::RightTileCollision(boundaries, dest, tile, tileX, tileY, u, i, j) == true && getVelocity().x > 0)
		{
			boundaries.x = (32 * j) - 33;
			setVelocity(0, gravity);

		}
		else if (collision::LeftTileCollision(boundaries, dest, tile, tileX, tileY, u, i, j) == true && getVelocity().x < 0)
		{
			std::cout << "working" << std::endl;
			if (tile == u)
			{
				boundaries.x = (32 * j) + 34;
				setVelocity(0, gravity);
			}



		}
		else if (collision::UpTileCollision(boundaries, dest, tile, tileX, tileY, u, i, j) == true && getVelocity().y > 0)
		{
			
			boundaries.y = (32 * i) - 16;
			setVelocity(0, 0);
			gravity = 0;
			clickCount = 0;
		}
	}
			

	//spike collision
	for (int u = 10; u < 14; u++)
	{

		if (collision::DownTileCollision(boundaries, dest, tile, tileX, tileY, u, i, j) == true)
		{
			boundaries.y = (32 * i) + 34;
			setVelocity(0, gravity);
			
			boundaries.y = 50;
			boundaries.x = 50;
			
			clickCount = 0;
		}

		else if (collision::RightTileCollision(boundaries, dest, tile, tileX, tileY, u, i, j) == true)
		{

			boundaries.x = (32 * j) - 33;
			setVelocity(0, gravity);

			boundaries.y = 50;
			boundaries.x = 50;
			clickCount = 0;

		}
		else if (collision::LeftTileCollision(boundaries, dest, tile, tileX, tileY, u, i, j) == true)
		{

			if (tile == u)
			{
				boundaries.x = (32 * j) + 34;
				setVelocity(0, gravity);

				boundaries.y = 50;
				boundaries.x = 50;

				clickCount = 0;
			}



		}
		else if (collision::UpTileCollision(boundaries, dest, tile, tileX, tileY, u, i, j) == true)
		{
			if(boundaries.x > (32 * j) && boundaries.x < (32 * j) + dest.w || boundaries.x + boundaries.w > (32 * j) && boundaries.x + boundaries.w < (32 * j) + dest.w && boundaries.y < (32 * i))
			{
				std::cout << "working" << std::endl;
				boundaries.y = (32 * i) - 16;
				boundaries.y = 50;
				boundaries.x = 50;
				clickCount = 0;
			}
			setVelocity(0, 0);
		}
	}

}

void player::moving() 
{

	velocity.y += gravity;
	boundaries.y += velocity.y;

	if (isMoving  == true)
	{
			boundaries.x += velocity.x;
	}


	
}



void player::draw(SDL_Renderer* renderer, SDL_Event &e)
{
	SDL_RenderCopy(renderer, sprite, 0, &boundaries);

		 if (clickCount < 2 && e.motion.x > 0 && e.motion.x < 1280)
				SDL_RenderDrawLine(renderer, e.motion.x, e.motion.y, boundaries.x + 32, boundaries.y + 8);

		 

}


vector2<float> player::setVelocity(float Velx, float Vely) 
{
	velocity.x = Velx;
	velocity.y = Vely;

	return velocity;
}

vector2<float> player::getVelocity()
{
	return velocity;
}