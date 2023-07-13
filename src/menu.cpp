#include "menu.h"

menu::menu() {
    buttons.clear();
    font = NULL;
}

menu::~menu() {
    buttons.clear();
    font = NULL;
}

int menu::pressButton() { //return value of button that was pressed
    int size = buttons.size();
    for(int i = 0; i < size; i++) {
        if(buttons[i]->pressed) {
            buttons[i]->pressed = false;
            return i;
        } 
    }
    return -1;
}

bool menu::press(int x, int y) {
    int size = buttons.size();
    for(int i = 0; i < size; i++) { //check click position against buttons, return true if a button is clicked
        if(x >= buttons[i]->target->x) {
            if(x <= buttons[i]->target->x + buttons[i]->target->w) {
                if(y >= buttons[i]->target->y) {
                    if(y <= buttons[i]->target->y + buttons[i]->target->h) {
                        buttons[i]->pressed = true;
                        return true;
                    } 
                }
            }
        }
    }
    return false;
}