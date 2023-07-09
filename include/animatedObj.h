#pragma once
#include "renderObj.h"

class animatedObj : public renderObj {

public:
    animatedObj(std::string path, SDL_Renderer* renderer, int frames, int w, int h, int fDelay = 50);
    void animRender(SDL_Renderer* ren, int x, int y, int w = 0, int h = 0, int animationNum = 0);
private:
    int advFrameTimer;
    int maxFrames;
    int frameDelay;
    int currentFrame;
    int spriteWidth;
    int spriteHeight;
};