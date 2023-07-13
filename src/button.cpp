#include "button.h"

button::button(std::string label, SDL_Renderer* ren) {
    pressed = false;
    selected = false;
    text = label;
    createTexture("assets/button.png", ren);
    labelText = NULL;
}

void button::buttonRender(SDL_Renderer* ren, int x, int y, int w, int h) {
    target->x = x;
    target->y = y;
    target->w = w;
    target->h = h;

    SDL_Rect textTarget = {x, y, w * .5, h * .3};
    render(ren, tex, target);
    render(ren, labelText, &textTarget);
}