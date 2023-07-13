#pragma once
#include "window.h"
#include "timer.h"
#include <vector>

class inputHandler {
public:
	inputHandler();
	~inputHandler();
	void handle();
	bool quit;
	const Uint8* keyState;
	timer inputTimer;
	SDL_Point mousePos;
	std::vector<int> pressedKeys;
private:
	void handleKeyboard();
	void handleMouse();
};