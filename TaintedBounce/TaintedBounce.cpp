#include "game.h"
#include <iostream>

int main(int argc, char *args[])
{
	game* Game = new game("Tainted Bounce", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 800, false);

	Game->update();
	Game->clean();

	delete Game;

	return 0;
}

