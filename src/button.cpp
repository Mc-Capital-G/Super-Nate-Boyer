#include "button.h"

button::button(std::string label, SDL_Renderer* ren) {
    pressed = false;
    selected = false;
    text = label;
    createTexture("assets/button.png", ren);
}

void button::buttonRender(SDL_Renderer* ren) {

    if(selected) {
        SDL_SetTextureColorMod(tex, 200, 200, 200); // modulate color if selected
        SDL_SetTextureColorMod(labelText.tex, 255, 255, 0);
    }
    else {
        SDL_SetTextureColorMod(tex, 255, 255, 255);
        SDL_SetTextureColorMod(labelText.tex, 255, 255, 255);
    }

    labelText.setTarget(target.x + target.w/2, target.y + target.h/2, target.w * .5, target.h * .3, MIDDLE);

    render(ren);
    labelText.render(ren);
}