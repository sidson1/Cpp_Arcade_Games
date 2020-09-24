// ArcadeApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL.h>
#include "Color.h"
#include "ScreenBuffer.h"
#include "Screen.h"
#include "Line2D.h"
#include "Triangle.h"
#include "AARectangle.h"
#include "Circle.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 4;

int main(int argc, const char* argv[])
{
	Screen theScreen;
	theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
	Line2D line = { Vec2D(0,0), Vec2D(SCREEN_WIDTH, SCREEN_HEIGHT) };
	Triangle triangle = { Vec2D(60, 10),Vec2D(10, 110),Vec2D(110, 110) };
	AARectangle rectangle = { Vec2D(SCREEN_WIDTH / 2 - 25, SCREEN_HEIGHT / 2 - 25),50,50 };
	Circle circle = { Vec2D(SCREEN_WIDTH / 2 + 50, SCREEN_HEIGHT / 2 + 50), 50 };
	theScreen.Draw(triangle, Color::Blue());
	theScreen.Draw(rectangle, Color::Yellow());
	theScreen.Draw(circle, Color::Pink());
	theScreen.Draw(line, Color::White());
	theScreen.Draw(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, Color::Yellow());
	theScreen.SwapScreens();
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