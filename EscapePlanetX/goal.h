#pragma once

#include "SDL.h"
#include "Entity.h"
#include <iostream>


class goal : public entity
{
public:

	goal();
	~goal();


	int update(SDL_Event& e,int level, SDL_Rect& player, int& currentPar, int& totalPar, bool& levelStart, bool& hasLevelEnded, vector2<int> startPos);
	void start(SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer);

	bool setIsLevelEnd(bool x) 
	{
		islevelEnd = x;
		return islevelEnd;
	}

	bool getIsLevelEnd() 
	{
		return islevelEnd;
	}

private:

	bool islevelEnd;
	

};