#include "Render.h"

Render::Render(){}

Render::~Render(){}

SDL_Texture* Render::Isprite(const char* file, SDL_Renderer* renderer, SDL_Texture* texture)
{
	tmpSurface = IMG_Load(file);
	
	if (tmpSurface != nullptr)
	{
		texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);
		return texture;

	}
	else
	{
		std::cout << "error" << std::endl;
		std::cout << IMG_GetError() << std::endl;
	}
	

}