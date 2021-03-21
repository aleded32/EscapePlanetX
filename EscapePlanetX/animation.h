#pragma once
#include "SDL.h"
#include "tilemaps.h"
#include "time.h"
#include <iostream>

class animation 
{
public:

	animation(float timePerSecond, int _maxImgCount, SDL_Rect src, int srcX, int srcY, int* modifiablesrcX, int* modifiablesrcY);
	~animation();

	void updateAnimationTile(int tileValue, int* x, int* y, float dt);
	void setSrc(int tileValue, int newSrcX, int newSrcY, int* srcX, int* srcY);
	void updateAnimationEntity();
	




private:

	float timePerFrame;
	float elaspedTime;
	int imgCount, MaxImgCount;
	SDL_Rect src;
	int tileValue;
	int srcX, srcY;
	int* modSrcX;
	int* modSrcY;
	int i, j;
	bool startAnimation;
	timer time;

};