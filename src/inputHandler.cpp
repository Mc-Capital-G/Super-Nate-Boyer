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

void inputHandler::handle() { //gets mouse and keyboard state
	pressedKeys.clear();
	SDL_GetMouseState(&mousePos.x, &mousePos.y);
	SDL_Event event;
	SDL_PollEvent(&event);
	keyState = SDL_GetKeyboardState(NULL); //stores boolean for each key/button -> = true if pressed, false if not
	switch(event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_MOUSEBUTTONUP:
			pressedKeys.emplace_back(event.button.button); //puts the id of the mouse button that was pressed into pressedKeys
		default: 
			for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
				if (keyState[i]) pressedKeys.emplace_back(i); //puts the id of any pressed keys into pressedKeys
			}
			break;
	}
}