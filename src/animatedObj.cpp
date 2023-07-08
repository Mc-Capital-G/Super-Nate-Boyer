#include "animatedObj.h"
#include <iostream>

animatedObj::animatedObj(std::string path, SDL_Renderer* renderer, int frames, int h, int w) {
    renderObj();
    createTexture(path, renderer);
    maxFrames = frames;
    currentFrame = 0;
    spriteWidth = w;
    spriteHeight = h;
    std::cout << "sw = " << spriteWidth << "sh = " << spriteHeight << "mf = " << maxFrames << std::endl;
}

void animatedObj::animRender(SDL_Renderer* ren, int x, int y, int w, int h, int animationNum) {
    std::cout << "current frame = " << currentFrame << std::endl;
    SDL_Rect c = {spriteWidth * currentFrame, spriteHeight * animationNum, spriteWidth, spriteHeight};
    std::cout << "c.x = " << c.x << " c.y = " << c.y << " c.h = " << c.h << " c.w = " << c.w << std::endl;
    SDL_Rect t = {x, y, w, h};
    if(t.w == 0) t.w = spriteWidth;
    if(t.h == 0) t.h = spriteHeight;
    target = &t;
    render(ren, &c);
    currentFrame++;
    if(currentFrame >= maxFrames) currentFrame = 0;
}