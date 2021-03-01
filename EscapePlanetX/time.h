#pragma once
#include "SDL.h"
#include <iostream>


class timer 
{
public:

	timer(const timer&) = delete;

	static timer& get() 
	{
		static timer instance;
		return instance;
	}

	
	static float getElapsedTimer() { return get().IgetElapsedTime(); }

	static void startTimer() { return get().IstartTimer(); }

	static void stopTimer() { return get().IstopTimer(); }

	static void FPSFrameCap60() { return get().IFPSFrameCap60(); }

	static float getDeltaTime() { return get().IgetDeltaTime(); }

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
	}

	~timer() 
	{
		
	}

	

private:

	float IgetElapsedTime()
	{
		return seconds;
	}


	void IstartTimer()
	{
		start++;

		if (start > 60)
		{
			seconds += 1;
			start = 0;
		}
	}

	void IstopTimer()
	{
		start = 0;
		seconds = 0;
	}

	void IFPSFrameCap60()
	{
		

		frametime = SDL_GetTicks() - framestart;

		if (frameDelay > frametime)
		{
			SDL_Delay(frameDelay - frametime);
		}
		framestart = SDL_GetTicks();
	}

	float IgetDeltaTime()
	{

		deltaTime = (SDL_GetTicks() - lastTime) * (FPS/1000);

		if (deltaTime > TargetDeltaTime)
			deltaTime = TargetDeltaTime;

		lastTime = SDL_GetTicks();


		return deltaTime;
	}

	

	float TargetDeltaTime, lastTime, FPS, frameDelay, deltaTime, framestart, frametime;
	float  start, end, elapsedTime, seconds;
	

};

