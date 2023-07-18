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
		SDL_Log("%s could not be loaded. SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	else {
		SDL_Texture* newTex = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTex == NULL) {
			SDL_Log("Texture could not be created from %s. SDL Error: %s\n", path.c_str(), SDL_GetError());
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

void renderObj::render(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* t, SDL_Rect* clip, int alignment, SDL_RendererFlip flip) {

	//texture, target, and clip all default to the renderObj's objects

	if(texture != NULL && t != NULL) { // given target and texture
		if(alignment == MIDDLE) {
			t->x -= t->w/2;
			t->y -= t->h/2;
		}
		SDL_RenderCopyEx(renderer, texture, clip, t, 0, 0, flip);
	}
	else if(t != NULL) { //given target, no texture
		if(alignment == MIDDLE) {
			t->x -= t->w/2;
			t->y -= t->h/2;
		}
		SDL_RenderCopyEx(renderer, tex, clip, t, 0, 0, flip);
	}
	else if(texture != NULL) { //given texture, no target
		if(alignment == MIDDLE) {
			t->x -= t->w/2;
			t->y -= t->h/2;
		}
		SDL_RenderCopyEx(renderer, texture, clip, &target, 0, 0, flip);
	}
	else { // given nothing
		if(alignment == MIDDLE) {
			SDL_Rect tempTarg = {target.x - target.w/2, target.y - target.h/2, target.w, target.h};
			SDL_RenderCopyEx(renderer, tex, clip, &tempTarg, 0, 0, flip);
		} 
		else SDL_RenderCopyEx(renderer, tex, clip, &target, 0, 0, flip);
	}
}