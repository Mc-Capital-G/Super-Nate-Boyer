#pragma once

#include "renderObj.h"

class animatedObj : public renderObj {

public:
    animatedObj(std::string path, SDL_Renderer* renderer, int frames, int h, int w);
    void animRender(SDL_Renderer* ren, SDL_Rect* t, int animationNum = 0);
private:
    int maxFrames;
    int currentFrame;
    int spriteWidth;
    int spriteHeight;
};