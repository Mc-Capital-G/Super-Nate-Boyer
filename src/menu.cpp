#include "menu.h"

menu::menu() {
    buttons.clear();
    font = NULL;
}

menu::~menu() {
    buttons.clear();
    font = NULL;
}

int menu::buttonHandle(inputHandler* handler) {

    int size = buttons.size();
    for(int i = 0; i < size; i++) {
        if(SDL_PointInRect(&handler->mousePos, &buttons[i]->target)) {
            buttons[i]->selected = true;
        }
        else buttons[i]->selected = false;
    }
    return -1;
}