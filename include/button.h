#pragma once
#include "renderObj.h"
#include "font.h"

class button : public renderObj{
public:
    button(std::string label, SDL_Renderer* ren);
    void buttonRender(SDL_Renderer* ren, int x, int y, int w, int h);
    std::string text;
    bool pressed;
    bool selected;
};