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
        menu.buttons[i]->labelText.tex = PublicPixel.createText(bTexts[i], renderer); // create button texts
    }

    menu.buttons[START]->setTarget(SCREEN_WIDTH/2, SCREEN_HEIGHT/1.65, 225, 112);
    menu.buttons[OPTIONS]->setTarget(SCREEN_WIDTH/2, SCREEN_HEIGHT/1.65 + 120, 200, 100);
    menu.buttons[CREDITS]->setTarget(SCREEN_WIDTH/2, SCREEN_HEIGHT/1.65 + 230, 200, 100);

    animatedObj title("assets/titlewiggle.png", renderer, 15, 400, 400);
    title.setTarget(SCREEN_WIDTH/2, SCREEN_HEIGHT/4, 400, 400, MIDDLE);

    renderObj background;
    background.createTexture("assets/background.png", renderer);
    background.setTarget(0, 0, (SCREEN_HEIGHT / 0.14765625), SCREEN_HEIGHT, TOP_LEFT);

    int size = menu.buttons.size();

    while(!handler->quit){

        handler->handle();

        switch(menu.buttonHandle(handler)) {

            case START:
                //std::cout << "Start button pressed" << std::endl;
                return true;
                break;
            case OPTIONS:
                //std::cout << "OPTIONS button pressed" << std::endl;
                tempMenu(renderer, handler);
                break;
            case CREDITS:
                //std::cout << "CREDITS button pressed" << std::endl;
                creditsMenu(renderer, handler, &PublicPixel);
                break;
            default:
                break;
        }

        SDL_Rect bgTarg2 = {background.target.x + background.target.w, background.target.y, background.target.w, background.target.h};

        // render zone
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);

        background.render(renderer);
        background.render(renderer, NULL, &bgTarg2);

        title.animRender(renderer);

        menu.buttons[START]->buttonRender(renderer);
        menu.buttons[OPTIONS]->buttonRender(renderer);
        menu.buttons[CREDITS]->buttonRender(renderer);
        
        SDL_RenderPresent(renderer);

        background.target.x--;
        if(background.target.x + background.target.w < 0) background.target.x = 0;
    }

    return false;
}

void creditsMenu(SDL_Renderer* renderer, inputHandler* handler, font* font) {
    
    SDL_Rect screenViewport = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

    SDL_Rect menuViewport;
    menuViewport.w = SCREEN_WIDTH * .6;
    menuViewport.h = SCREEN_HEIGHT * .9;
    menuViewport.x = SCREEN_WIDTH/2 - menuViewport.w/2;
    menuViewport.y = SCREEN_HEIGHT/2 - menuViewport.h/2;

    renderObj menuBackground;
    menuBackground.createTexture("assets/button.png", renderer);
    menuBackground.setTarget(0, 0, menuViewport.w, menuViewport.h, TOP_LEFT);

    menu credits;
    credits.buttons.emplace_back(new button("BACK", renderer));
    credits.buttons[0]->labelText.tex = font->createText(credits.buttons[0]->text, renderer);
    credits.buttons[0]->setTarget(menuViewport.x + menuViewport.w/2, menuViewport.y + menuViewport.h - 50, 100, 50);
    
    renderObj title;
    title.tex = font->createText("CREDITS", renderer);
    title.setTarget(menuViewport.x + menuViewport.w/2, menuViewport.y + 50, menuViewport.w * .4, menuViewport.h * .07);

    while(!handler->quit) {

        handler->handle();

        credits.buttonHandle(handler);

        if(credits.buttons[0]->pressed) break;

        //render context
        SDL_SetTextureColorMod(menuBackground.tex, 0, 0, 0);
        menuBackground.render(renderer, NULL, &menuViewport);
        title.render(renderer);
        credits.buttons[0]->buttonRender(renderer);

        SDL_RenderPresent(renderer);

    }
}

void tempMenu(SDL_Renderer* renderer, inputHandler* handler) {

    renderObj menu;

    menu.createTexture("assets/menu.png", renderer);
    menu.setTarget(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, TOP_LEFT);

    int a = 255;

    Mix_Music* instaThud = Mix_LoadMUS("assets/vineboom.mp3");
    Mix_PlayMusic(instaThud, 0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    while(a >= 0) {



        SDL_RenderClear(renderer);
        SDL_SetTextureAlphaMod(menu.tex, a);

        menu.render(renderer);

        SDL_RenderPresent(renderer);

        a -= 2;
    }
}