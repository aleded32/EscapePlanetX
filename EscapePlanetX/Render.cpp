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

SDL_Texture* Render::ItextSprite(const char* text, SDL_Texture* texture, SDL_Color _colour, TTF_Font* _font, SDL_Renderer* renderer) 
{
	SDL_Color colours = _colour;

	tmpSurface = TTF_RenderText_Solid(_font, text, colours);

	if (tmpSurface != nullptr) 
	{
		texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);
		return texture;
	}
	else 
	{
		std::cout << "error" << std::endl;
	}

}