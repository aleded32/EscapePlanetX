#pragma once
#include <iostream>
#include "SDL.h"

class collision 
{
public:

	bool tileCollision(SDL_Rect player, SDL_Rect tileRect,int tile, int x , int y, int tileValue, int i, int j)
	{
			    tileXY.x = 32* j;
				tileXY.y = 32 * i;
				
				playerXY.x = player.x + 32;
				playerXY.y = player.y + 16;
				
				

				if (playerXY.x > tileXY.x && player.x < tileXY.x + tileRect.w && playerXY.y > tileXY.y && player.y < tileXY.y + tileRect.h)
				{

					if (tile == tileValue)
					{
						player.x = tileXY.x - 32;
						player.y = tileXY.y - 16;
						return true;
					}
					else
					{
						return false;
					}
				}
	}

	void entityCollision() 
	{
	
	}



private:

	vector2<int> tileXY;
	vector2<int> playerXY;

};