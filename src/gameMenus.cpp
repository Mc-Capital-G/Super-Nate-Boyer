#include "menu.h"
#include "renderObj.h"
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
        menu.buttons.emplace_back(new button(bTexts[i], renderer)); // create menu buttons
        menu.buttons[i]->labelText = PublicPixel.createText(bTexts[i], renderer); // create button texts
    }

    animatedObj title("assets/titlewiggle.png", renderer, 15, 400, 400);

    renderObj superNate;
    superNate.createTexture("assets/SuperNateBoyer.png", renderer);
    superNate.target.x = SCREEN_WIDTH/5;
    superNate.target.y = SCREEN_HEIGHT/2;
    superNate.target.w = 200;
    superNate.target.h = 200;

    renderObj background;
    background.createTexture("assets/background.png", renderer);
    
    background.target.w = SCREEN_HEIGHT / 0.14765625;
    background.target.h = SCREEN_HEIGHT;
    background.target.x = 0 + background.target.w/2;
    background.target.y = SCREEN_HEIGHT/2;

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
                creditsMenu(renderer, handler);
                break;
            default:
                break;
        }



        SDL_Rect bgTarg2 = {background.target.x + background.target.w, background.target.y, background.target.w, background.target.h};

        SDL_Rect snTarget2 = {superNate.target.x * 4, superNate.target.y, superNate.target.w, superNate.target.h};

        // render zone
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);

        background.render(renderer);
        background.render(renderer, NULL, &bgTarg2, NULL);

        title.animRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/4, 400, 400);

        superNate.render(renderer);
        superNate.render(renderer, NULL, &snTarget2);

        menu.buttons[START]->buttonRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/1.65, 225, 112);
        menu.buttons[OPTIONS]->buttonRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/1.65 + 120, 200, 100);
        menu.buttons[CREDITS]->buttonRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/1.65 + 230, 200, 100);
        
        SDL_RenderPresent(renderer);

        background.target.x--;
        if(background.target.x + background.target.w < 0 + background.target.w/2) background.target.x = 0 + background.target.w/2;
    }

    return false;
}

void creditsMenu(SDL_Renderer* renderer, inputHandler* handler) {
    
}