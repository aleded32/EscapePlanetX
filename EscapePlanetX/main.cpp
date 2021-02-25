#include "game.h"
#include <iostream>

int main(int argc, char *args[])
{
	game* Game = new game("Escape planet X", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 704, false);

	Game->update();
	Game->clean();


	delete Game;

	return 0;
}

