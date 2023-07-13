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

void::inputHandler::handle() {
	pressedKeys.clear();
	handleKeyboard();
	handleMouse();
}

void inputHandler::handleKeyboard() {
	SDL_Event event;
	SDL_PollEvent(&event);
	keyState = SDL_GetKeyboardState(NULL);
	switch(event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		default: 
			for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
				if (keyState[i]) {
					pressedKeys.emplace_back(i);
				}
			}
			break;
	}
}

void inputHandler::handleMouse() {
	SDL_GetMouseState(&mousePos.x, &mousePos.y);
	std::cout << "mouse x: " << mousePos.x << " mouse y: " << mousePos.y << std::endl;
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			pressedKeys.emplace_back(event.button.button); //puts the id of the mouse button that was pressed into pressedKeys
			break;
	}
}

