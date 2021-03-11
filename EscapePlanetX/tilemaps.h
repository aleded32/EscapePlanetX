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

	int FindTile;

	int setLevel(const char file[24]);

	int getTile(int x, int y);

	int getLevelPar() 
	{
		return levelpar;
	}


	void drawLevel(SDL_Renderer* renderer);
	

private:

	int w, h;
	std::ifstream* read;
	SDL_Texture* tiles;
	SDL_Rect src;
	int **levelTiles;
	int levelpar;
};

