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
        if(!SDL_PointInRect(&handler->mousePos, &buttons[i]->target)) {
            buttons[i]->selected = false;
            continue;
        }
        buttons[i]->selected = true;
        for(int j = 0; j < handler->pressedKeys.size(); i++) {
            if(handler->pressedKeys[j] != SDL_BUTTON_LEFT) {
                buttons[i]->pressed = false;
                continue;
            }
            buttons[i]->pressed = true;
            return i;
        }
        
    }
    return -1;
}