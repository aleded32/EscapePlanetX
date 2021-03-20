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

	srcX = new int[]
	{
		0, 32, 64, 96, 128,
		0, 32, 64, 96, 128,
		0, 32, 64, 96, 128,
	};

	srcY = new int[]
	{
		0, 32, 64, 96, 128,
		0, 32, 64, 96, 128,
		0, 32, 64, 96, 128,
		0, 32, 64, 96, 128,
		0, 32, 64, 96, 128,
	};
}

tilemaps::~tilemaps() 
{
	delete levelTiles;
	delete srcX;
	delete srcY;
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
				src.x = srcX[0];
				src.y = srcY[0];
				break;
			case 1:
				src.x = srcX[1];
				src.y = srcY[0];
				break;
			case 2:
				src.x = srcX[2];
				src.y = srcY[0];
				break;
			case 3:
				src.x = srcX[3];
				src.y = srcY[0];
				break;
			case 4:
				src.x = srcX[4];
				src.y = srcY[0];
				break;
			case 5:
				src.x = srcX[5];
				src.y = srcY[6];
				break;
			case 6:
				src.x = srcX[6];
				src.y = srcY[6];
				break;
			case 7:
				src.x = srcX[7];
				src.y = srcY[6];
				break;
			case 8:
				src.x = srcX[8];
				src.y = srcY[6];
				break;
			case 9:
				src.x = srcX[9];
				src.y = srcY[6];
				break;
			case 10:
				src.x = srcX[10];
				src.y = srcY[12];
				break;
			case 11:
				src.x = srcX[11];
				src.y = srcY[12];
				break;
			case 12:
				src.x = srcX[12];
				src.y = srcY[12];
				break;
			case 13:
				src.x = srcX[13];
				src.y = srcY[12];
				break;
			case 14:
				src.x = srcX[14];
				src.y = srcY[12];
				break;

			}
			
			SDL_RenderCopy(renderer, tiles, &src, &dest);
		}
		
	}
	
	
}

 