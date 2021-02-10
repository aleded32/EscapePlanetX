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
		start = 0;
		end = 0;
		elapsedTime = 0;
		FPS = 60;
		frameDelay = 1000/FPS;
	}


	~timer() 
	{
		
	}

	float getElapsedTime()
	{
		return seconds;
	}


	void startTimer() 
	{
		start++;

		if (start > 60) 
		{
			seconds += 1;
			start = 0;
		}
	}

	void stopTimer() 
	{
		start = 0;
		seconds = 0;
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

	float TargetDeltaTime, lastTime, FPS, frameDelay, deltaTime, framestart, frametime;
	float  start, end, elapsedTime, seconds;
	

};

