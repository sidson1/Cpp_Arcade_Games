// ArcadeApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL.h>
#include "Color.h"
#include "ScreenBuffer.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;

//void SetPixel(SDL_Surface* noptrWindowSurface, uint32_t color, int x, int y);
//size_t GetIndex(SDL_Surface* noptrSurface, int r, int c);

int main(int argc, const char* argv[])
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
	SDL_Surface* noptrWindowSurface = SDL_GetWindowSurface(optrWindow);
	SDL_PixelFormat* pixelFormat = noptrWindowSurface->format;
	Color::InitColorFormat(pixelFormat);
	Color c(255, 255, 0, 255);
	ScreenBuffer screenBuffer;
	screenBuffer.Init(pixelFormat->format, noptrWindowSurface->w, noptrWindowSurface->h);
	screenBuffer.SetPixel(Color::Red(), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	SDL_BlitSurface(screenBuffer.GetSurface(), nullptr, noptrWindowSurface, nullptr);
	//std::cout << "The window pixel format is: " << SDL_GetPixelFormatName(pixelFormat->format);
	//uint32_t color = 0xFFFF0000;
	//SetPixel(noptrWindowSurface, Color::Orange().GetPixelColor(), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	SDL_UpdateWindowSurface(optrWindow);
	SDL_Event sdlEvent;
	bool running = true;
	while (running)
	{
		while (SDL_PollEvent(&sdlEvent))
		{
			switch (sdlEvent.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			}
		}
	}
	SDL_DestroyWindow(optrWindow);
	SDL_Quit();
	return 0;
}

void SetPixel(SDL_Surface* noptrWindowSurface, uint32_t color, int x, int y)
{
	SDL_LockSurface(noptrWindowSurface);
	uint32_t* pixels = (uint32_t*)noptrWindowSurface->pixels;
	SDL_UnlockSurface(noptrWindowSurface);
}

size_t GetIndex(SDL_Surface* noptrSurface, int r, int c)
{
	return r * noptrSurface->w + c;
}