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
		deltaTime = 0;
		FPS = 60;
		frameDelay = 1000 / FPS;
		timerControl = false;
		currentTime = 0;
	}

	~timer() 
	{
		
	}

	



	float getElapsedTime()
	{
		return seconds;
	}


	void startTimer(float dt)
	{
		
		if (timerControl == false) 
		{
			
			currentTime += dt;
			if (currentTime >= 40) 
			{
				seconds+=0.25;
				currentTime = 0;
			}
		}
			
	}

	void stopTimer()
	{
		timerControl = true;
		seconds = 0;
		currentTime = 0;
	}

	void FPSFrameCap60()
	{
		

		frametime = SDL_GetTicks() - framestart;

		if (frameDelay > frametime)
		{
			SDL_Delay(frameDelay - frametime);
		}
		framestart = SDL_GetTicks();
	}

	float getDeltaTime()
	{

		deltaTime = (SDL_GetTicks() - lastTime) * (FPS/1000);

		if (deltaTime > TargetDeltaTime)
			deltaTime = TargetDeltaTime;

		lastTime = SDL_GetTicks();


		return deltaTime;
	}

	void restartTime() 
	{
		timerControl = false;
		seconds = 0;
		currentTime = 0;
	}

	void pauseTime() 
	{
		timerControl = true;
	}

	void resumeTime() 
	{
		timerControl = false;
	}

private:

	float TargetDeltaTime, lastTime, FPS, frameDelay, deltaTime, framestart, frametime;
	float  start, end, elapsedTime, seconds, currentTime;
	bool timerControl;
	

};

