#pragma once
#ifndef GRAPHICS_SCREEN_H
#define GRAPHICS_SCREEN_H

#include <stdint.h>
#include "ScreenBuffer.h"
#include "Color.h"

struct SDL_Window;
struct SDL_Surface;

class Vec2D;
class Line2D;

class Triangle;
class AARectangle;
class Circle;

class Screen
{
private:
	uint32_t mWidth, mHeight;
	SDL_Window* moptrWindow;
	SDL_Surface* mnoptrWindowSurface;
	ScreenBuffer mBackBuffer;
	Color mClearColor;

	Screen(const Screen& screen);
	Screen& operator=(const Screen& screen);

	void ClearScreen();
public:
	Screen();
	~Screen();
	SDL_Window* Init(uint32_t width, uint32_t height, uint32_t mag);
	void SwapScreens();
	inline void SetClearColor(const Color& clearColor) { mClearColor = clearColor; }
	inline uint32_t Width() const { return mWidth; }
	inline uint32_t Height() const { return mHeight; }

	//Draw Methods
	void Draw(int x, int y, const Color& color);
	void Draw(const Vec2D& point, const Color& color);
	void Draw(const Line2D& line, const Color& color);
	void Draw(const Triangle& triangle, const Color& color);
	void Draw(const AARectangle& rectangle, const Color& color);
	void Draw(const Circle& circle, const Color& color);
};

#endif // !GRAPHICS_SCREEN_H