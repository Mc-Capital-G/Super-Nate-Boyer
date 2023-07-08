#include "font.h"

font::font(std::string path, int r, int g, int b, int a) {
	pathToFont = path;
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
}

bool font::createTex(std::string renderText, SDL_Renderer* renderer, int wrapLength) {
	SDL_Surface* loadedSurface = TTF_RenderText_Solid_Wrapped(fontType, renderText.c_str(), color, wrapLength);
	if (loadedSurface == NULL) {
		printf("Text could not be loaded into a texture. SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else {
		SDL_Texture* newTex = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTex == NULL) {
			printf("Texture could not be created from text. SDL Error: %s\n", SDL_GetError());
			return false;
		}
		else {
			width = loadedSurface->w;
			height = loadedSurface->h;
			SDL_SetTextureBlendMode(newTex, SDL_BLENDMODE_BLEND);
			SDL_FreeSurface(loadedSurface);
			tex = newTex;
		}
	}
	return tex != NULL;
}

void font::display(std::string renderText, SDL_Renderer* renderer, int x, int y, int w, int fontSize) {
	SDL_Rect t = {x, y, width, height};
	target = &t;
	fontType = TTF_OpenFont(pathToFont.c_str(), fontSize);
	createTex(renderText, renderer, w);
	render(renderer);
	SDL_DestroyTexture(tex); // do not delete this line ever - without it tex eats memory instantly
}