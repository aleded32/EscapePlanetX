#pragma once

#include <iostream>
#include "vectors.h"
#include <fstream>
#include "Render.h";




class tilemaps 
{

public:
	
	vector2<int> grid;

	tilemaps(int x, int y, SDL_Renderer* renderer, int levelpar);
	~tilemaps();

	Render tileRender;
	
	SDL_Rect dest;
	SDL_Rect src;

	int FindTile;

	int setLevel(const char file[24]);

	int getTile(int x, int y);

	int getLevelPar() 
	{
		return levelpar;
	}

	int** getLevel() 
	{
		return levelTiles;
	}

	void drawLevel(SDL_Renderer* renderer);
	int* srcX;
	int* srcY;
	SDL_Texture* tiles;

private:

	int w, h;
	std::ifstream* read;
	
	
	int **levelTiles;

	int levelpar;
};

