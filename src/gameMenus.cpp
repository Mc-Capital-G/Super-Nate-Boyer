#include "menu.h"

bool mainMenu(SDL_Renderer* renderer, inputHandler* handler) {

    menu menu;
    font PublicPixel("assets/PublicPixel.ttf", 25);

    button* start = new button("START", renderer);
    button* options = new button("OPTIONS", renderer);
    button* credits = new button("CREDITS", renderer);

    menu.buttons.emplace_back(start);
    menu.buttons.emplace_back(options);
    menu.buttons.emplace_back(credits);

    animatedObj title("assets/titlewiggle.png", renderer, 15, 400, 400);

    int size = menu.buttons.size();
    for(int i = 0; i < size; i++) {
        menu.buttons[i]->labelText = PublicPixel.createText(menu.buttons[i]->text, renderer);
    }

    while(!handler->quit){

        handler->handle();
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);

        title.animRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/4, 400, 400);

        start->buttonRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/1.65, 225, 112);
        options->buttonRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/1.65 + 120, 200, 100);
        credits->buttonRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/1.65 + 230, 200, 100);
        
        SDL_RenderPresent(renderer);
    }
}