#include "menu.h"
#include <iostream>

bool mainMenu(SDL_Renderer* renderer, inputHandler* handler) {

    menu menu;
    font PublicPixel("assets/PublicPixel.ttf", 25);

    enum buttonTypes {
        START = 0,
        OPTIONS = 1,
        CREDITS = 2
    };

    std::string bTexts[3] = {"START", "OPTIONS", "CREDITS"}; //button labels

    for(int i = 0; i < 3; i++) {
        menu.buttons.emplace_back(new button(bTexts[i], renderer));
        menu.buttons[i]->labelText = PublicPixel.createText(bTexts[i], renderer);
    }

    animatedObj title("assets/titlewiggle.png", renderer, 15, 400, 400);

    int size = menu.buttons.size();
    
    for(int i = 0; i < size; i++) menu.buttons[i]->labelText = PublicPixel.createText(menu.buttons[i]->text, renderer);
    

    while(!handler->quit){

        handler->handle();

        switch(menu.buttonHandle(handler)) {

            case START:
                std::cout << "Start button pressed" << std::endl;
                return true;
                break;
            case OPTIONS:
                std::cout << "OPTIONS button pressed" << std::endl;

                break;
            case CREDITS:
                std::cout << "CREDITS button pressed" << std::endl;
                break;
            default:
                break;
        }

        // render zone
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);

        title.animRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/4, 400, 400);

        menu.buttons[START]->buttonRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/1.65, 225, 112);
        menu.buttons[OPTIONS]->buttonRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/1.65 + 120, 200, 100);
        menu.buttons[CREDITS]->buttonRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/1.65 + 230, 200, 100);
        
        SDL_RenderPresent(renderer);
    }

    return false;
}