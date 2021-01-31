#include "Render.h"

Render::Render(){}

Render::~Render(){}

void Render::sprite(SDL_Surface* _surface, const char* file, SDL_Renderer* renderer, SDL_Texture* texture)
{
	tmpSurface = IMG_Load(file);
	if (tmpSurface != nullptr)
	{
		texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);
		Sprite = texture;
		
	}
	else
	{
		std::cout << "error" << std::endl;
	}
	

}