#include "animatedObj.h"
#include <iostream>

animatedObj::animatedObj(std::string path, SDL_Renderer* renderer, int frames, int w, int h, int fDelay) {
    renderObj();
    createTexture(path, renderer);
    maxFrames = frames;
    currentFrame = 0;
    frameDelay = fDelay;
    spriteWidth = w;
    spriteHeight = h;
    advFrameTimer = 0;
    //std::cout << "sw = " << spriteWidth << "sh = " << spriteHeight << "mf = " << maxFrames << std::endl;
}

void animatedObj::animRender(SDL_Renderer* ren, int x, int y, int w, int h, int animationNum) {
    //std::cout << "current frame = " << currentFrame << std::endl;
    SDL_Rect c = {spriteWidth * currentFrame, spriteHeight * animationNum, spriteWidth, spriteHeight}; //calculate render clip based on what frame we are on, and the sprite width/height
    //std::cout << "c.x = " << c.x << " c.y = " << c.y << " c.h = " << c.h << " c.w = " << c.w << std::endl;
    SDL_Rect t = {x, y, w, h};
    if(t.w == 0) t.w = spriteWidth;
    if(t.h == 0) t.h = spriteHeight;
    target = &t;
    render(ren, tex, &c, target);
    if(advFrameTimer == 0) {
        advFrameTimer = SDL_GetTicks64() + frameDelay;
    }
    else if(SDL_GetTicks64() > advFrameTimer) {
        currentFrame++;
        advFrameTimer = 0;
    }
    if(currentFrame >= maxFrames) currentFrame = 0;
}