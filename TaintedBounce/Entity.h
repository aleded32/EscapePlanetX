#pragma once
#include "SDL.h"
#include "render.h"
#include "vectors.h"
#include "time.h"
#include <iostream>


class entity 
{
public:

	int h, w;
	vector2<int> position;

	SDL_Rect boundaries;

	

	void update(SDL_Event& e);
	void start();
	void draw(SDL_Renderer* renderer);

	SDL_Texture* texture;
	Render EntityRender;


};


class player : public entity
{
public:

	


	player(int _x, int _y, int h, int w, SDL_Renderer* render);
	~player();

	void CreateDirection(SDL_Event& e);
	void moving();
	void worldCollision();
	void update(SDL_Event& e);
	void start();
	void draw(SDL_Renderer* renderer, SDL_Event& e);


private:

	timer Time;
	float gravity;
	double AngleMouseBall;
	vector2<int> displacement;
	vector2<float> velocity;
	bool isMoving;
	int speed;
	int clickCount;
	bool isPressed;



};
