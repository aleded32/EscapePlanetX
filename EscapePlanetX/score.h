#pragma once

#include "Render.h"
#include "SDL.h"
#include <iostream>
#include <String>




class Score
{
public:

	Score(int _levelPar, int clickAmount,SDL_Renderer* renderer);
	~Score();

	void update(SDL_Event& e, int clickAmount, SDL_Renderer* renderer);
	void start();
	void draw(SDL_Renderer* renderer);

	int getCurrentPar() 
	{
		return currentPar;
	}

	int totalPar;
	int totalLevelPar;


private:

	int currentPar;
	int levelPar;
	
	TTF_Font* font;
	SDL_Rect texts[2];
	SDL_Texture** texture;
	std::string String[2];

};