CC = emcc
all: main.cpp
	$(CC) main.cpp -O2 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' -s USE_SDL_TTF=2 -s USE_SDL_MIXER=2 --preload-file assets -o escapePlanetX.html

