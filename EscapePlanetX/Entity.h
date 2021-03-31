#pragma once
#include "SDL.h"
#include "render.h"
#include "vectors.h"
#include "collision.h"
#include "time.h"
#include "soundManager.h"
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

	SDL_Texture* sprite;
	
	

	

};


class player : public entity
{
public:

	
	int clickCount;
	vector2<int> ActualBounderies;

	player(int _x, int _y, int h, int w, SDL_Renderer* render);
	~player();

	void CreateDirection(SDL_Event& e, float dt);
	void moving();
	void worldCollision();
	void tilingCollision(int tile, int tileX, int tileY, SDL_Rect dest, int j, int i);
	void update(SDL_Event& e, float dt, int currentLevel);
	void start();
	void draw(SDL_Renderer* renderer, SDL_Event& e);

	vector2<float> setVelocity(float x, float y);
	vector2<float> getVelocity();

	int currentPar;
	bool level1Start;
	bool hasLevelEnded;
	float gravity;

private:

	
	bool cantAim;
	float AngleMouseBall;
	vector2<int> displacement;
	
	vector2<float> velocity;
	bool isMoving;
	float currentTime;
	int speed;

	timer leveltime;
	
	bool isPressed;
	vector2<int>* collisionBoundaries;


};
