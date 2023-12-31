#include "game.h"

void game(SDL_Renderer* renderer, inputHandler* handler) { //most of this is temporary code being used for testing/proof of concept at the moment, therefore not documented well

    animatedObj snbUPDATE("assets/snbspritesheetUPDATE.png", renderer, 4, 58, 58, 200);
    snbUPDATE.setTarget(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 200, 200);
    int faceDirection = 0; // temporary value, will be implemented into a player class once we get that far
    //0 - up, 1 - right, 2 - down, 3 - left

    renderObj floor;
    floor.createTexture("assets/floor.png", renderer);
    
    renderObj bookshelf;
    bookshelf.createTexture("assets/bookshelf.png", renderer);
    bookshelf.setTarget(SCREEN_WIDTH/3, SCREEN_HEIGHT/3, 256, 128);

    while(!handler->quit) {

        SDL_Rect floorTar = {0, 0, 128, 128};

        handler->handle();

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        for(int y = 0; floorTar.y < SCREEN_HEIGHT; y++) {
            floorTar.x = 0;
            for(int x = 0; floorTar.x < SCREEN_WIDTH; x++) {
                floor.render(renderer, NULL, &floorTar);
                floorTar.x += floorTar.w - 1;
            }
            floorTar.y += floorTar.h - 1;
        }

        bookshelf.render(renderer);

        if(handler->keyState[SDL_SCANCODE_W]) {
            faceDirection = 0;
            snbUPDATE.target.y-=2;
            snbUPDATE.animRender(renderer);
        }
        else if(handler->keyState[SDL_SCANCODE_D]) {
            faceDirection = 1;
            snbUPDATE.target.x+=2;
            snbUPDATE.animRender(renderer, 1);
        }
        else if(handler->keyState[SDL_SCANCODE_A]) {
            faceDirection = 3;
            snbUPDATE.animRender(renderer, 1, SDL_FLIP_HORIZONTAL);
            snbUPDATE.target.x-=2;
        }
        else if(handler->keyState[SDL_SCANCODE_S]) {
            faceDirection = 2;
            snbUPDATE.target.y+=2;
            snbUPDATE.animRender(renderer, 2);
        }
        else {
            if(faceDirection != 3) {
                SDL_Rect clip = {174, 58 * faceDirection, 58, 58};
                snbUPDATE.render(renderer, NULL, NULL, &clip);
            }
            else {
                SDL_Rect clip = {174, 58, 58, 58};
                snbUPDATE.render(renderer, NULL, NULL, &clip, SDL_FLIP_HORIZONTAL);
            }
        }

        SDL_RenderPresent(renderer);
    }

}