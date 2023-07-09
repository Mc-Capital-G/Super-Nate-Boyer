#pragma once
#include "includeSDL.h"

class renderObj {
public:
	renderObj();
	~renderObj();
	void createTexture(std::string path, SDL_Renderer* renderer);
	void render(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* clip, SDL_Rect* t);
	SDL_Texture* tex;
	SDL_Rect* target;
	int width;
	int height;
	int posX;
	int posY;
private:
};

