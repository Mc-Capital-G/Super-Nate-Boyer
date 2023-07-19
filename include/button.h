#pragma once
#include "renderObj.h"

class button : public renderObj{
public:
    button(std::string label, SDL_Renderer* ren);
    void buttonRender(SDL_Renderer* ren);
    std::string text;
    renderObj labelText;
    bool pressed;
    bool selected;
};