#pragma once
#include "includeSDL.h"
#include "renderObj.h"

class font : public renderObj {
public:
	font(std::string path, int fontSize, int r = 255, int g = 255, int b = 255, int a = 0);
	SDL_Texture* createText(std::string renderText, SDL_Renderer* renderer, bool wrap = false, int wrapLength = 0);
	TTF_Font* fontType;
	SDL_Color color;
};

