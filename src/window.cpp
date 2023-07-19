#include "window.h"

//some window init code was written with help and inspiration from Lazy Foo Production's online tutorials at https://lazyfoo.net/tutorials/SDL/

Window::Window() {
	gameWindow = NULL;
	gameRenderer = NULL;
}

Window::~Window() {
	SDL_DestroyWindow(gameWindow);
	SDL_DestroyRenderer(gameRenderer);
	gameWindow = NULL;
	gameRenderer = NULL;
}

bool Window::init(const char* title, int screenWidth, int screenHeight) {

	// Initializes SDL and its subsystems, and logs errors and returns false if any errors in initialization were encountered

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) { //initialize SDL
		SDL_Log("SDL could not be initialized. SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else {
		gameWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_INPUT_FOCUS); //create window
		if (gameWindow == NULL) {
			SDL_Log("SDL Window could not be created. SDL Error: %s\n", SDL_GetError());
			return false;
		}
		else {
			gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_PRESENTVSYNC); //create renderer
			if (gameRenderer == NULL) {
				SDL_Log("Renderer could not be created. SDL Error: %s\n", SDL_GetError());
				return false;
			}
			else { //initialize SDL Subsystems
				SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0x00); //initialize default render color
				int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG; //flags to give to SDL_image init function - defines what extensions can be loaded 
				if (IMG_Init(imgFlags) != imgFlags) { //initialize SDL_image
					SDL_Log("SDL Image could not be initialized. SDL Error: %s\n", SDL_GetError());
					return false;
				}
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) { //initialize SDL_mixer
					SDL_Log("SDL Mixer could not initialize. SDL Error: %s\n", SDL_GetError());
					return false;
				}
				if (TTF_Init() == -1) { //initialize SDL_ttf
					SDL_Log("SDL ttf could not not initialize. SDL Error: %s\n", SDL_GetError());
					return false;
				}
			}
		}
	}
	return true;
}