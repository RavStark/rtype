/*
R-TYPE
Remi Depond <depond.remi@gmail.com> 2015
*/

#include "Core.hpp"
#include <iostream>

int main(int argc, char *arvg[])
{
	Core core;

	if (!core.init())
		return 1;
	core.loop();
	core.close();
	//Init SDL
	/*else
	{
		
		{
			if (loadMedia())
			{
				
				SDL_BlitSurface(gtest, NULL, screenSurface, NULL);
				SDL_UpdateWindowSurface(window);
				SDL_Delay(5000);*/

	return 0;
}