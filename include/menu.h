#pragma once
#include "button.h"
#include "font.h"
#include "window.h"
#include "inputHandler.h"
#include "animatedObj.h"
#include <vector>
#include <iostream>

class menu : public renderObj{
public:
    menu();
    ~menu();
    int buttonHandle(inputHandler* handler);
    font* font;
    std::vector<button*> buttons;
};

bool mainMenu(SDL_Renderer* renderer, inputHandler* handler);
void creditsMenu(SDL_Renderer* renderer, inputHandler* handler, font* font);