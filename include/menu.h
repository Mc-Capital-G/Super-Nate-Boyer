#pragma once
#include "button.h"
#include <vector>


class menu {
public:
    menu();
    ~menu();
    int pressButton();
    std::vector<button> buttons;
    SDL_Rect viewport;
    
};