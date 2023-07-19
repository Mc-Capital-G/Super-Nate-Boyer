#pragma once
#include "includeSDL.h"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 720

class Window {
public:
	SDL_Renderer* gameRenderer;
	SDL_Window* gameWindow;
	Window();
	~Window();
	bool init(const char *title, int screenWidth = 1280, int screenHeight = 720);
private:
};