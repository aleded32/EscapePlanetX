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
	vector2<int> startPos;
	

	void update(SDL_Event& e);
	void start();
	void draw(SDL_Renderer* renderer);

	SDL_Texture* texture;
	Render EntityRender;


};


class player : public entity
{
public:

	
	int clickCount;
	vector2<int> ActualBounderies;

	player(int _x, int _y, int h, int w, SDL_Renderer* render);
	~player();

	void CreateDirection(SDL_Event& e);
	void moving();
	void worldCollision();
	void update(SDL_Event& e);
	void start();
	void draw(SDL_Renderer* renderer, SDL_Event& e);

	vector2<float> setVelocity(float x, float y);
	vector2<float> getVelocity();


private:

	timer Time;
	float gravity;
	double AngleMouseBall;
	vector2<int> displacement;
	
	vector2<float> velocity;
	bool isMoving;
	int speed;
	
	bool isPressed;
	vector2<int>* collisionBoundaries;


};