#pragma once
#include "renderObj.h"

//default class for any object we want to render with an animation - can interpret sprite sheets

class animatedObj : public renderObj {

public:
    animatedObj(std::string path, SDL_Renderer* renderer, int frames, int w, int h, int fDelay = 50);
    void animRender(SDL_Renderer* ren, int animationNum = 0, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
    int advFrameTimer;
    int maxFrames;
    int frameDelay;
    int currentFrame;
    int spriteWidth;
    int spriteHeight;
};