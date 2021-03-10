#pragma once
#include <iostream>
#include <vector>
#include "vectors.h"
#include "SDL.h"

class collision 
{
public:

	

	static collision& get() 
	{
		static collision instance;
		return instance;
	}

	static bool tileCollision(SDL_Rect player, SDL_Rect tileRect, int tile, int x, int y, int tileValue, int i, int j) { return get().ItileCollision(player, tileRect, tile, x, y, tileValue,i,j); }
	static bool entityCollision(SDL_Rect player, std::vector<SDL_Rect*> object) { return get().IentityCollision(player, object); }
	static bool UpTileCollision(SDL_Rect player, SDL_Rect tileRect, int tile, int x, int y, int tileValue, int i, int j) { return get().IUpTileCollision(player, tileRect, tile, x, y, tileValue, i, j); }
	static bool DownTileCollision(SDL_Rect player, SDL_Rect tileRect, int tile, int x, int y, int tileValue, int i, int j) { return get().IDownTileCollision(player, tileRect, tile, x, y, tileValue, i, j); }
	static bool LeftTileCollision(SDL_Rect player, SDL_Rect tileRect, int tile, int x, int y, int tileValue, int i, int j) { return get().ILeftTileCollision(player, tileRect, tile, x, y, tileValue, i, j); }
	static bool RightTileCollision(SDL_Rect player, SDL_Rect tileRect, int tile, int x, int y, int tileValue, int i, int j) { return get().IRightTileCollision(player, tileRect, tile, x, y, tileValue, i, j); }

	collision()
	{

	}

private:

	bool ItileCollision(SDL_Rect player, SDL_Rect tileRect,int tile, int x , int y, int tileValue, int i, int j)
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

	bool IRightTileCollision(SDL_Rect player, SDL_Rect tileRect, int tile, int x, int y, int tileValue, int i, int j)
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

	bool ILeftTileCollision(SDL_Rect player, SDL_Rect tileRect, int tile, int x, int y, int tileValue, int i, int j)
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

	bool IUpTileCollision(SDL_Rect player, SDL_Rect tileRect, int tile, int x, int y, int tileValue, int i, int j)
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

	bool IDownTileCollision(SDL_Rect player, SDL_Rect tileRect, int tile, int x, int y, int tileValue, int i, int j)
	{
		vector2<int> tileXY;
		vector2<int> playerXY;

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

	bool IentityCollision(SDL_Rect player, std::vector<SDL_Rect*> object) 
	{
		for (int i = 0; i < object.size(); i++)
		{
			if (player.x + player.h > object[i]->x && player.x < object[i]->x + object[i]->w && player.y + player.h > object[i]->y && player.y < object[i]->y + object[i]->h)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}


	
	vector2<int> tileXY;
	vector2<int> playerXY;
	

};