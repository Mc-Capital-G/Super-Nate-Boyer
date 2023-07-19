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

void animatedObj::animRender(SDL_Renderer* ren, int animationNum, SDL_RendererFlip flip) {
    
    //calculate render clip based on what frame we are on, and the sprite width/height
    SDL_Rect c = {spriteWidth * currentFrame, spriteHeight * animationNum, spriteWidth, spriteHeight}; 

    render(ren, tex, &target, &c, flip);
    if(advFrameTimer == 0) {
        advFrameTimer = SDL_GetTicks64() + frameDelay; //set a time in the future to move to the next frame of animation, based on the current time and frame delay
    }
    else if(SDL_GetTicks64() >= advFrameTimer) {
        currentFrame++;
        advFrameTimer = 0;
    }
    if(currentFrame >= maxFrames) currentFrame = 0;
}