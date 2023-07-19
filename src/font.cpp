#include "font.h"

font::font(std::string path, int fontSize, int r, int g, int b, int a) {
	fontType = TTF_OpenFont(path.c_str(), fontSize); //open ttf file
	//initialize color
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
}

SDL_Texture* font::createText(std::string renderText, SDL_Renderer* renderer, bool wrap, int wrapLength) {
	SDL_Surface* loadedSurface;
	if(wrap) loadedSurface = TTF_RenderText_Solid_Wrapped(fontType, renderText.c_str(), color, wrapLength); //generate surface based on text
	else loadedSurface = TTF_RenderText_Solid(fontType, renderText.c_str(), color);
	if (loadedSurface == NULL) {
		SDL_Log("Text could not be loaded into a texture. SDL Error: %s\n", SDL_GetError());
		return NULL;
	}
	else {
		SDL_Texture* newTex = SDL_CreateTextureFromSurface(renderer, loadedSurface); //create new texture from loaded surface
		if (newTex == NULL) {
			SDL_Log("Texture could not be created from text. SDL Error: %s\n", SDL_GetError());
			return NULL;
		}
		else {
			//initialize target width and height from text
			target.w = loadedSurface->w;
			target.h = loadedSurface->h;
			SDL_SetTextureBlendMode(newTex, SDL_BLENDMODE_BLEND);
			SDL_FreeSurface(loadedSurface); //deallocate surface
			return newTex;
		}
	}
}