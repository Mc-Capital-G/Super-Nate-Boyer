#pragma once
#include "button.h"
#include "font.h"
#include "window.h"
#include "inputHandler.h"
#include "animatedObj.h"
#include <vector>

class menu : public renderObj{
public:
    menu();
    ~menu();
    int pressButton();
    bool press(int x, int y);
    std::vector<button*> buttons;
    font* font;
};

bool mainMenu(SDL_Renderer* renderer, inputHandler* handler);