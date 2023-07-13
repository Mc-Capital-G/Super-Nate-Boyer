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
    int pKeys = handler->pressedKeys.size();
    for(int i = 0; i < size; i++) {
        if(!SDL_PointInRect(&handler->mousePos, &buttons[i]->target)) {
            buttons[i]->selected = false;
            continue;
        }
        buttons[i]->selected = true;
        
        for(int j = 0; j < pKeys; i++) {
            if(handler->pressedKeys[j] == SDL_BUTTON_LEFT) {
                buttons[i]->pressed = true;
                return i;
            }
            else {
                buttons[i]->pressed = false;
                break; // will throw errors if not here, no idea why
            }
        }
        
    }
    return -1;
}