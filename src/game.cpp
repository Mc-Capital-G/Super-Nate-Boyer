#include "game.h"

void game(SDL_Renderer* renderer, inputHandler* handler) {

    animatedObj snb("assets/SNB_SpriteSheet.png", renderer, 9, 58, 58, 500);
    animatedObj snbUPDATE("assets/snbspritesheetUPDATE.png", renderer, 4, 58, 58, 500);

    while(!handler->quit) {

        handler->handle();

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        if(handler->keyState[SDL_SCANCODE_W]) {
            snbUPDATE.animRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 200, 200);
        }
        else if(handler->keyState[SDL_SCANCODE_D]) {
            snbUPDATE.animRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 200, 200, 1);
        }
        else if(handler->keyState[SDL_SCANCODE_A]) {
            
            snbUPDATE.animRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 200, 200, 1, SDL_FLIP_HORIZONTAL);
            
        }
        else if(handler->keyState[SDL_SCANCODE_S]) {
            snbUPDATE.animRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 200, 200, 2);
        }

        SDL_RenderPresent(renderer);
    }

}