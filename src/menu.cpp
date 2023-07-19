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

    int size = buttons.size(); //get number of buttons in the menu
    int pKeys = handler->pressedKeys.size(); //get number of pressed keys
    for(int i = 0; i < size; i++) {
        if(!SDL_PointInRect(&handler->mousePos, &buttons[i]->target)) { //selects button if the mouse is hovering over the button
            buttons[i]->selected = false;
            continue;
        }
        buttons[i]->selected = true;
        
        for(int j = 0; j < pKeys; i++) {
            if(handler->pressedKeys[j] == SDL_BUTTON_LEFT) { //presses button if LMB is pressed and mouse is hovering over button
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