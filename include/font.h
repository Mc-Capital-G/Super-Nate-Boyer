#pragma once
#include "includeSDL.h"
#include "renderObj.h"

class font : public renderObj {
public:
	font(std::string path, int r = 255, int g = 255, int b = 255, int a = 0);
	bool createTex(std::string renderText, SDL_Renderer* renderer, int wrapLength);
	void display(std::string renderText, SDL_Renderer* renderer, int x, int y, int w, int fontSize);
	std::string pathToFont;
	TTF_Font* fontType;
	SDL_Color color;
};

