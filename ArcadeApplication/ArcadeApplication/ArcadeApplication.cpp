// ArcadeApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL.h>

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;

int main(int argc, const char * argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "SDL_Init failed\n";
		return 1;
	}
	SDL_Window* optrWindow = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (optrWindow == nullptr)
	{
		std::cout << "Window creation failed. Error: " << SDL_GetError() << std::endl;
	}
		SDL_Event sdlEvent;
		bool running = true;
		while (running)
		{
			while (SDL_PollEvent(&sdlEvent))
			{
				switch (sdlEvent.type)
				{
					case SDL_QUIT:
						running=false;
					break;
				}
			}
		}
	SDL_DestroyWindow(optrWindow);
	SDL_Quit();
	return 0;
}