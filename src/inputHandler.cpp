#include "includeSDL.h"
#include "inputHandler.h"
#include <iostream>

inputHandler::inputHandler() {
	quit = false;
	keyState = NULL;
}

inputHandler::~inputHandler() {
	quit = true;
	keyState = NULL;
}

void inputHandler::handle() {
	pressedKeys.clear();
	SDL_GetMouseState(&mousePos.x, &mousePos.y);
	//std::cout << "mouse x: " << mousePos.x << " mouse y: " << mousePos.y << std::endl;
	SDL_Event event;
	SDL_PollEvent(&event);
	keyState = SDL_GetKeyboardState(NULL);
	switch(event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_MOUSEBUTTONUP:
			pressedKeys.emplace_back(event.button.button); //puts the id of the mouse button that was pressed into pressedKeys
		default: 
			for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
				if (keyState[i]) pressedKeys.emplace_back(i);
			}
			break;
	}
}