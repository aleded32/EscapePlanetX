#include "score.h"

Score::Score( int clickAmount, SDL_Renderer* renderer)
{
	
	currentPar = clickAmount;
	levelPar = new int[]
	{
		2,4,3
	};
	font = TTF_OpenFont("assets/ARCADECLASSIC.TTF", 50);
	
	texture = new SDL_Texture * [2];
	
	
	texts[0].x = 20;
	texts[0].y = 2;

	texts[1].x = 1100;
	texts[1].y = 2;
	
	for (auto& e : texts) 
	{
		e.w = 150;
		e.h = 28;
	}

}

Score::~Score() {}


void Score::update(SDL_Event& e, int clickAmount, SDL_Renderer* renderer, int levelParIndex) 
{

	String[0] = "Current Par   " + std::to_string(currentPar);
	String[1] = "Level Par   " + std::to_string(levelPar[levelParIndex]);

	texture[0] = Render::textSprite(String[0].c_str(), texture[0], { 255,255,255 }, font, renderer);
	texture[1] = Render::textSprite(String[1].c_str(), texture[1], { 255,255,255 }, font, renderer);

	currentPar = clickAmount;
}


void Score::draw(SDL_Renderer* renderer) 
{
	for (int i = 0; i < 2; i++)
	{
		SDL_RenderCopy(renderer, texture[i], 0, &texts[i]);
		SDL_DestroyTexture(texture[i]);
	}

	
}