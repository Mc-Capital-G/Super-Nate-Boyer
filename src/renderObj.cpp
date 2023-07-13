#include "renderObj.h"

renderObj::renderObj() {
	tex = NULL;
	posX = 0;
	posY = 0;
	width = 0;
	height = 0;
}

renderObj::~renderObj() {
	SDL_DestroyTexture(tex);
}

void renderObj::createTexture(std::string path, SDL_Renderer* renderer) {
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		printf("%s could not be loaded. SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	else {
		SDL_Texture* newTex = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTex == NULL) {
			printf("Texture could not be created from %s. SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else {

			width = loadedSurface->w;
			height = loadedSurface->h;
			SDL_SetTextureBlendMode(newTex, SDL_BLENDMODE_BLEND);
			SDL_FreeSurface(loadedSurface);
			//SDL_Rect t = { posX, posY, width, height };
			target.x = posX;
			target.y = posY;
			target.w = width;
			target.h = height;
			tex = newTex;
		}
	}
}

void renderObj::render(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* t, SDL_Rect* clip) {

	//texture, target, and clip all default to the renderObj's objects

	if(texture != NULL && t != NULL) { // given target and texture
		t->x -= t->w/2;
		t->y -= t->h/2;
		SDL_RenderCopy(renderer, texture, clip, t);
	}
	else if(t != NULL) { //given target, no texture
		t->x -= t->w/2;
		t->y -= t->h/2;
		SDL_RenderCopy(renderer, tex, clip, t);
	}
	else if(texture != NULL) { //given texture, no target
		t->x -= t->w/2;
		t->y -= t->h/2;
		SDL_RenderCopy(renderer, texture, clip, &target);
	}
	else {
		SDL_RenderCopy(renderer, tex, clip, &target);
	}
}