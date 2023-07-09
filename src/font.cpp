#include "font.h"

font::font(std::string path, int fontSize, int r, int g, int b, int a) {
	fontType = TTF_OpenFont(path.c_str(), fontSize);
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
}

SDL_Texture* font::createText(std::string renderText, SDL_Renderer* renderer, bool wrap, int wrapLength) {
	SDL_Surface* loadedSurface;
	if(wrap) loadedSurface = TTF_RenderText_Solid_Wrapped(fontType, renderText.c_str(), color, wrapLength);
	else loadedSurface = TTF_RenderText_Solid(fontType, renderText.c_str(), color);
	if (loadedSurface == NULL) {
		printf("Text could not be loaded into a texture. SDL Error: %s\n", SDL_GetError());
		return NULL;
	}
	else {
		SDL_Texture* newTex = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTex == NULL) {
			printf("Texture could not be created from text. SDL Error: %s\n", SDL_GetError());
			return NULL;
		}
		else {
			width = loadedSurface->w;
			height = loadedSurface->h;
			SDL_SetTextureBlendMode(newTex, SDL_BLENDMODE_BLEND);
			SDL_FreeSurface(loadedSurface);
			return newTex;
		}
	}
}