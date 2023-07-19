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

void renderObj::setTarget(int x, int y, int w, int h, int alignment) {
	if(alignment == MIDDLE) {
		target.x = x - w/2;
		target.y = y - h/2;
	}
	if(alignment == TOP_LEFT) {
		target.x = x;
		target.y = y;
	}
	if(alignment == TOP_RIGHT) {
		target.x = x - w;
		target.y = y;
	}
		target.w = w;
		target.h = h;
}

void renderObj::render(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* t, SDL_Rect* clip, SDL_RendererFlip flip) {

	//texture, target, and clip all default to the renderObj's objects

	if(texture != NULL && t != NULL) SDL_RenderCopyEx(renderer, texture, clip, t, 0, 0, flip); // given target and texture

	else if(t != NULL) SDL_RenderCopyEx(renderer, tex, clip, t, 0, 0, flip); //given target, no texture

	else if(texture != NULL) SDL_RenderCopyEx(renderer, texture, clip, &target, 0, 0, flip); //given texture, no target

	else SDL_RenderCopyEx(renderer, tex, clip, &target, 0, 0, flip); // given nothing

}