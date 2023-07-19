#pragma once
#include "includeSDL.h"

enum ALIGNMENT {
	MIDDLE = 0,
	TOP_LEFT = 1,
	TOP_RIGHT = 2
};

class renderObj {
public:
	renderObj();
	~renderObj();
	void createTexture(std::string path, SDL_Renderer* renderer);
	void setTarget(int x, int y, int w, int h, int alignment = MIDDLE);
	void render(SDL_Renderer* renderer, SDL_Texture* texture = NULL, SDL_Rect* t = NULL, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	SDL_Texture* tex;
	SDL_Rect target;
	int width;
	int height;
	int posX;
	int posY;
private:
};