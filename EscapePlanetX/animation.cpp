#include "animation.h"


animation::animation(float _timePerFrame, int _maxImgCount, SDL_Rect _src, int _srcX, int _srcY, int* modifiablesrcX, int* modifiablesrcY)
{
	timePerFrame = _timePerFrame;
	imgCount = 1;
	MaxImgCount = _maxImgCount;
	src = _src;
	srcX = _srcX;
	srcY = _srcY;
	modSrcX = modifiablesrcX;
	modSrcY = modifiablesrcY;
	i = srcX;
	j = srcY;
	startAnimation = false;

}

animation::~animation() {}


void animation::updateAnimationTile(int tileValue,int* x, int* y) 
{
	timer::startTimer();
	
	elaspedTime = timer::getElapsedTimer();

	setSrc(tileValue, modSrcX[i], modSrcY[j], x, y);
	

	if (elaspedTime > timePerFrame) 
	{
		
		if (imgCount <= MaxImgCount) 
		{
			
			if (i >= 5)
			{
				j ++;
				i = 0;

			}
			else if(i < 5)
			{
				//std::cout << imgCount << "  " << i << std::endl;
				
				i++;
				
			}
			
			imgCount++;
			
			

		}
		if (imgCount > MaxImgCount) 
		{
			i = srcX;
			j = srcY;
			
			imgCount = 1;
			
		}

		
		
		timer::restartTime();
		
	}
	
	

}

void animation::setSrc(int tileValue, int newSrcX, int newSrcY, int* srcsX, int* srcsY)
{

	std::cout << srcsX[2] << std::endl;


			switch (tileValue)
			{
			
			case 0:
				srcsX[0] = newSrcX;
				srcsY[0] = newSrcY;
				break;
			case 1:
				srcsX[1] = newSrcX;
				srcsY[0] = newSrcY;
				break;
			case 2:
				srcsX[2] = newSrcX;
				srcsY[0] = newSrcY;
				break;
			case 3:
				srcsX[3] = newSrcX;
				srcsY[0] = newSrcY;
				break;
			case 4:
				srcsX[4] = newSrcX;
				srcsY[0] = newSrcY;
				break;
			case 5:
				srcsX[5] = newSrcX;
				srcsY[5] = newSrcY;
				break;
			case 6:
				srcsX[6] = newSrcX;
				srcsY[5] = newSrcY;
				break;
			case 7:
				srcsX[7] = newSrcX;
				srcsY[5] = newSrcY;
				break;
			case 8:
				srcsX[8] = newSrcX;
				srcsY[5] = newSrcY;
				break;
			case 9:
				srcsX[9] = newSrcX;
				srcsY[5] = newSrcY;
				break;
			case 10:
				srcsX[10] = newSrcX;
				srcsY[10] = newSrcY;
				break;
			case 11:
				srcsX[11] = newSrcX;
				srcsY[10] = newSrcY;
				break;
			case 12:
				srcsX[12] = newSrcX;
				srcsY[10] = newSrcY;
				break;
			case 13:
				srcsX[13] = newSrcX;
				srcsY[10] = newSrcY;
				break;
			case 14:
				srcsX[14] = newSrcX;
				srcsY[10] = newSrcY;
				break;

			}

}
