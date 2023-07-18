#include "game.h"

void game(SDL_Renderer* renderer, inputHandler* handler) {

    animatedObj snb("assets/SNB_SpriteSheet.png", renderer, 9, 58, 58, 500);
    animatedObj snbUPDATE("assets/snbspritesheetUPDATE.png", renderer, 4, 58, 58, 500);
    int faceDirection = 0; // temporary value, will be implemented into a player class once we get that far
    //0 - up, 1 - right, 2 - down, 3 - left

    renderObj floor;
    floor.createTexture("assets/floor.png", renderer);
    

    while(!handler->quit) {

        SDL_Rect tar = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 500, 500};
        SDL_Rect floorTar = {0, 0, 256, 256};

        handler->handle();

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        for(int y = 0; floorTar.y < SCREEN_HEIGHT; y++) {
            floorTar.x = 0;
            for(int x = 0; floorTar.x < SCREEN_WIDTH; x++) {
                floor.render(renderer, NULL, &floorTar, NULL, TOP_LEFT);
                floorTar.x += floorTar.w;
            }
            floorTar.y += floorTar.h - 4;
        }

        if(handler->keyState[SDL_SCANCODE_W]) {
            faceDirection = 0;
            snbUPDATE.animRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 200, 200);
        }
        else if(handler->keyState[SDL_SCANCODE_D]) {
            faceDirection = 1;
            snbUPDATE.animRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 200, 200, 1);
        }
        else if(handler->keyState[SDL_SCANCODE_A]) {
            faceDirection = 3;
            snbUPDATE.animRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 200, 200, 1, SDL_FLIP_HORIZONTAL);
            
        }
        else if(handler->keyState[SDL_SCANCODE_S]) {
            faceDirection = 2;
            snbUPDATE.animRender(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 200, 200, 2);
        }
        else {
            if(faceDirection != 3) {
                SDL_Rect clip = {174, 58 * faceDirection, 58, 58};
                snbUPDATE.render(renderer, NULL, &tar, &clip);
            }
            else {
                SDL_Rect clip = {174, 58, 58, 58};
                snbUPDATE.render(renderer, NULL, &tar, &clip, MIDDLE, SDL_FLIP_HORIZONTAL);
            }
        }

        SDL_RenderPresent(renderer);
    }

}