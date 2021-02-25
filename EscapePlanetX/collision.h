#pragma once
#include <iostream>
#include "SDL.h"

class collision 
{
public:

	bool isLeft;

	bool tileCollision(SDL_Rect player, SDL_Rect tileRect,int tile, int x , int y, int tileValue, int i, int j)
	{
			    tileXY.x = 32* j;
				tileXY.y = 32 * i;
				
				playerXY.x = player.x + 32;
				playerXY.y = player.y + 32;
				
				

				if (playerXY.x > tileXY.x && player.x < tileXY.x + tileRect.w && playerXY.y > tileXY.y && player.y < tileXY.y + tileRect.h)
				{

					if (tile == tileValue)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
	}

	bool RightTileCollision(SDL_Rect player, SDL_Rect tileRect, int tile, int x, int y, int tileValue, int i, int j)
	{
		tileXY.x = 32 * j;
		tileXY.y = 32 * i;

		playerXY.x = player.x + 32;
		playerXY.y = player.y + 16;

		if (playerXY.x > tileXY.x && player.x < tileXY.x + tileRect.w && playerXY.y > tileXY.y && player.y < tileXY.y + tileRect.h && player.x < tileXY.x)
		{
			if (player.x + player.w > tileXY.x && player.y < tileXY.y + tileRect.h && player.y > tileXY.y)
			{
				if (tile == tileValue)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			
		}
		else
		{
			return false;
		}
		

	}

	bool LeftTileCollision(SDL_Rect player, SDL_Rect tileRect, int tile, int x, int y, int tileValue, int i, int j)
	{
		tileXY.x = 32 * j;
		tileXY.y = 32 * i;

		playerXY.x = player.x + 32;
		playerXY.y = player.y + 16;

		if (playerXY.x > tileXY.x && player.x < tileXY.x + tileRect.w && player.y < tileXY.y + tileRect.h && player.y > tileXY.y)
		{
			if (player.x < tileXY.x + tileRect.w && player.y < tileXY.y + tileRect.h && player.y > tileXY.y && player.x + player.w > tileXY.x + tileRect.w)
			{
				if (tile == tileValue)
				{
					
					return true;
				}
				else
				{
					return false;
				}
			}

		}
		else
		{
			return false;
			
		}


	}

	bool UpTileCollision(SDL_Rect player, SDL_Rect tileRect, int tile, int x, int y, int tileValue, int i, int j)
	{
		tileXY.x = 32 * j;
		tileXY.y = 32 * i;

		playerXY.x = player.x + 32;
		playerXY.y = player.y + 16;

		if (playerXY.x > tileXY.x && player.x < tileXY.x + tileRect.w && playerXY.y > tileXY.y && player.y < tileXY.y + tileRect.h)
		{
			if (player.x > tileXY.x && player.x < tileXY.x + tileRect.w && player.y  < tileXY.y)
			{
				if (tile == tileValue)
				{
						return true;
				}
				else
				{
					return false;
				}
			}

		}
		else
		{
			return false;
		}


	}

	bool DownTileCollision(SDL_Rect player, SDL_Rect tileRect, int tile, int x, int y, int tileValue, int i, int j)
	{
		tileXY.x = 32 * j;
		tileXY.y = 32 * i;

		playerXY.x = player.x + 32;
		playerXY.y = player.y + 16;

		if (playerXY.x > tileXY.x && player.x < tileXY.x + tileRect.w && playerXY.y > tileXY.y && player.y < tileXY.y + tileRect.h)
		{
			if (tileXY.x > player.x && tileXY.x < playerXY.x && player.y < tileXY.y + tileRect.h && playerXY.y > tileXY.y + tileRect.h)
			{
				if (tile == tileValue)
				{
					
					return true;
				}
				else
				{
					return false;
				}
			}

		}
		else
		{
			return false;
		}


	}

	void entityCollision() 
	{
	
	}



private:

	vector2<int> tileXY;
	vector2<int> playerXY;
	

};