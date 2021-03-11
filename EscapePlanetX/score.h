#pragma once

#include <iostream>
#include <String>
#include "Render.h"



class Score
{
public:

	Score(int _levelPar, int clickAmount,SDL_Renderer* renderer);
	~Score();

	void update(SDL_Event& e, int clickAmount, SDL_Renderer* renderer);
	void start();
	void draw(SDL_Renderer* renderer);




private:

	int currentPar;
	int levelPar;
	TTF_Font* font;
	SDL_Rect texts[2];
	SDL_Texture* texture[2];
	std::string String[2];

};