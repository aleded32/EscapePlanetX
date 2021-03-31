#pragma once

#include "SDL_mixer.h"
#include <iostream>
#include <vector>

class soundManager 
{
public:

	soundManager();
	~soundManager();

	

	static soundManager* Instance()
	{
		if (instance == NULL)
			instance = new soundManager();

		return instance;
	}

	void loadMusicList(const char* filenames);
	void playMusic(int currentLevel);
	std::vector<Mix_Chunk*> musicList;
	void playSFX(int soundIndex);

private:

	static soundManager* instance;
	bool soundisPlaying;

	


};