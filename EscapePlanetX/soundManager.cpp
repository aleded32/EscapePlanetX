#include "soundManager.h"

soundManager* soundManager::instance = NULL;

soundManager::soundManager()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("sound not working \n", Mix_GetError());
	
	}
	soundisPlaying = false;
}

void soundManager::loadMusicList(const char* filenames) 
{
	musicList.push_back(Mix_LoadWAV(filenames));
}

void soundManager::playMusic(int currentLevel) 
{
	Mix_Volume(-1, 4);
	Mix_Volume(0, 10);
	
	if (currentLevel > 2)
	{
		if(!soundisPlaying)
		{
			Mix_HaltChannel(-1);
		}
		Mix_PlayChannel(-1, musicList[0], -1);
		soundisPlaying = true;
	}
	else if (currentLevel <= 2) 
	{
		if (soundisPlaying) 
		{
			Mix_HaltChannel(-1);
		}
		Mix_PlayChannel(-1, musicList[1], -1);
		soundisPlaying = false;
	}

	
	
}

void soundManager::playSFX(int soundIndex) 
{
	Mix_PlayChannel(0, musicList[soundIndex], 0);
}


soundManager::~soundManager() {}