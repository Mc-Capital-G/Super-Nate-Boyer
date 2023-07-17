#include "game.h"


void game(SDL_Renderer* renderer, inputHandler* handler) {

    animatedObj snb("assets/SNB_SpriteSheet.png", renderer, 9, 58, 58, 500);

    while(!handler->quit) {

        handler->handle();

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        snb.animRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 200, 200);

        SDL_RenderPresent(renderer);
    }

}