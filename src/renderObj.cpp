#include "renderObj.h"

renderObj::renderObj() {
	tex = NULL;
	target = {0, 0, 0, 0};
}
renderObj::~renderObj() {
	SDL_DestroyTexture(tex);
}

void renderObj::createTexture(std::string path, SDL_Renderer* renderer) { // create texture from specified path to file
	SDL_Surface* loadedSurface = IMG_Load(path.c_str()); // loads image file into a SDL_Surface
	if (loadedSurface == NULL) {
		SDL_Log("%s could not be loaded. SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	else {
		SDL_Texture* newTex = SDL_CreateTextureFromSurface(renderer, loadedSurface); // converts surface into texture (textures cannot be loaded directly from files)
		if (newTex == NULL) {
			SDL_Log("Texture could not be created from %s. SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else {
			//default texture width and height to image size

			target.w = loadedSurface->w; 
			target.h = loadedSurface->h;
			SDL_SetTextureBlendMode(newTex, SDL_BLENDMODE_BLEND);
			SDL_FreeSurface(loadedSurface); //deallocate SDL_Surface

			tex = newTex; //assign generated texture to desired target
		}
	}
}

void renderObj::setTarget(int x, int y, int w, int h, int alignment) { //sets the render target for renderObj
	if(alignment == MIDDLE) { //offset given postion to render as if the given position were at the center of the texture
		target.x = x - w/2; 
		target.y = y - h/2;
	}
	if(alignment == TOP_LEFT) { //offset given position to render as if the given position were at the top left of the texture
		target.x = x;
		target.y = y;
	}
	if(alignment == TOP_RIGHT) {//offset given position to render as if the given position were at the top right of the texture
		target.x = x - w;
		target.y = y;
	}
		target.w = w;
		target.h = h;
}

void renderObj::render(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* t, SDL_Rect* clip, SDL_RendererFlip flip) {

	//texture, target, and clip all default to the renderObj's objects
	//if a parameter is given as NULL, the function is to use the default values

	if(texture != NULL && t != NULL) SDL_RenderCopyEx(renderer, texture, clip, t, 0, 0, flip); // given target and texture

	else if(t != NULL) SDL_RenderCopyEx(renderer, tex, clip, t, 0, 0, flip); //given target, no texture

	else if(texture != NULL) SDL_RenderCopyEx(renderer, texture, clip, &target, 0, 0, flip); //given texture, no target

	else SDL_RenderCopyEx(renderer, tex, clip, &target, 0, 0, flip); // given nothing

}