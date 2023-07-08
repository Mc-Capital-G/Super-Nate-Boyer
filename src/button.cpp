#include "button.h"

button::button(std::string label, SDL_Renderer* ren) {
    pressed = false;
    selected = false;
    text = label;
    createTexture("assets/button.png", ren);
}

void button::buttonRender(SDL_Renderer* ren, int x, int y, int w, int h) {
    SDL_Rect t = {x, y, w, h};
    target = &t;
    render(ren);
}