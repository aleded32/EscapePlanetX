#pragma once
#include "SDL.h"
#include <iostream>


class timer 
{
public:

	

	
	timer() 
	{
		TargetDeltaTime = 1.5;
		lastTime = 0;
		FPS = 60;
		frameDelay = 1000/FPS;
	}


	~timer() 
	{
	
	}


	void FPSFrameCap60() 
	{
		framestart = SDL_GetTicks();

		frametime = SDL_GetTicks() - framestart;

		if (frameDelay > frametime) 
		{
			SDL_Delay(frameDelay - frametime);
		}
	}

	 float getDeltaTime() 
	 {
		
		deltaTime = (SDL_GetTicks() -  lastTime);
		

		if (deltaTime > TargetDeltaTime) 
		{
			deltaTime = TargetDeltaTime;
		}
		lastTime = SDL_GetTicks();
		
		return deltaTime;
	}

private:

	float  TargetDeltaTime, lastTime, FPS, frameDelay, deltaTime, framestart, frametime;

};

