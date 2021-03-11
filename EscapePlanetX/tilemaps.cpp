#include "tilemaps.h"


tilemaps::tilemaps(int _x, int _y, SDL_Renderer* renderer, int _levelpar)
{
	grid.x = _x;
	grid.y = _y;

	levelpar = _levelpar;

	levelTiles = new int* [grid.x];

	for (int i = 0; i < grid.x; i++) 
	{
		levelTiles[i] = new int[grid.y];
	}

	tiles = Render::sprite("assets/tiles.png", renderer, tiles);
}

tilemaps::~tilemaps() 
{
	delete levelTiles;
}

int tilemaps::setLevel(const char file[30]) 
{
	read = new std::ifstream(file);

	if (read->is_open()) 
	{
		for (int i = 0; i < grid.y; i++)
		{
			for (int j = 0; j < grid.x; j++)
			{
				*read >> levelTiles[j][i];	
			}
			
		}
		
		
	}
	else
	{
		printf("not file to open");
	}
	read->close();


	for (int i = 0; i < grid.y; i++)
	{
		for (int j = 0; j < grid.x; j++)
		{
			return levelTiles[j][i];
		}

	}

	



}

int tilemaps::getTile(int x, int y) 
{
	return levelTiles[x][y];
}



void tilemaps::drawLevel(SDL_Renderer* renderer) 
{
		
	src.h = 32;
	src.w = 32;
	dest.w = 32;
	dest.h = 32;
	

	for (int i = 0; i < grid.y; i++)
	{
		for (int j = 0; j < grid.x; j++)
		{

			dest.x = j * 32;
			dest.y = i * 32;


			switch (levelTiles[j][i])
			{
			case 0:
				src.x = 0;
				src.y = 0;
				break;
			case 1:
				src.x = 32;
				src.y = 0;
				break;
			case 2:
				src.x = 64;
				src.y = 0;
				break;
			case 3:
				src.x = 96;
				src.y = 0;
				break;
			case 4:
				src.x = 128;
				src.y = 0;
				break;
			case 5:
				src.x = 0;
				src.y = 32;
				break;
			case 6:
				src.x = 32;
				src.y = 32;
				break;
			case 7:
				src.x = 64;
				src.y = 32;
				break;
			case 8:
				src.x = 96;
				src.y = 32;
				break;
			case 9:
				src.x = 128;
				src.y = 32;
				break;
			case 10:
				src.x = 0;
				src.y = 64;
				break;
			case 11:
				src.x = 32;
				src.y = 64;
				break;
			case 12:
				src.x = 64;
				src.y = 64;
				break;
			case 13:
				src.x = 96;
				src.y = 64;
				break;
			case 14:
				src.x = 128;
				src.y = 64;
				break;

			}
			
			SDL_RenderCopy(renderer, tiles, &src, &dest);
		}
		
	}
	
	
}