#include "menu.h"
#include "renderObj.h"
#include <iostream>

bool mainMenu(SDL_Renderer* renderer, inputHandler* handler) {

    // The main menu of the game that opens on startup, returns true if we should continue to the next menu, false if the program should exit

    menu menu;
    font PublicPixel("assets/PublicPixel.ttf", 25);

    enum buttonTypes { // aliases used for indexing the list of buttons that belongs to the menu obj -> ease of reading
        START = 0,
        OPTIONS = 1,
        CREDITS = 2
    };

    std::string bTexts[3] = {"START", "OPTIONS", "CREDITS"}; //button labels

    for(int i = 0; i < 3; i++) {
        menu.buttons.emplace_back(new button(bTexts[i], renderer)); // create menu buttons based on defined labels (see string list bTexts[])
        menu.buttons[i]->labelText.tex = PublicPixel.createText(bTexts[i], renderer); // create button texts based on defined labels
    }

    //set the position of buttons
    menu.buttons[START]->setTarget(SCREEN_WIDTH/2, SCREEN_HEIGHT/1.65, 225, 112);
    menu.buttons[OPTIONS]->setTarget(SCREEN_WIDTH/2, SCREEN_HEIGHT/1.65 + 120, 200, 100);
    menu.buttons[CREDITS]->setTarget(SCREEN_WIDTH/2, SCREEN_HEIGHT/1.65 + 230, 200, 100);

    //create the title object and set its position
    animatedObj title("assets/titlewiggle.png", renderer, 15, 400, 400);
    title.setTarget(SCREEN_WIDTH/2, SCREEN_HEIGHT/4, 400, 400, MIDDLE);

    //create the background and set its position
    renderObj background;
    background.createTexture("assets/background.png", renderer);
    background.setTarget(0, 0, (SCREEN_HEIGHT / 0.14765625), SCREEN_HEIGHT, TOP_LEFT);

    while(!handler->quit){

        handler->handle(); //get current state of user input -> collects info on keyboard and mouse actions

        switch(menu.buttonHandle(handler)) { //test if a button has been pressed, and act accordingly
            case START: //exit the menu
                return true;
                break;
            case OPTIONS:  // load the options submenu (currently a temporary menu)
                tempMenu(renderer, handler);
                break;
            case CREDITS: // load the credits menu
                creditsMenu(renderer, handler, &PublicPixel);
                break;
            default: //if no button was pressed, do nothing and continue operating in the current menu
                break;
        }

        //sets an alternate target for a second copy of the background
        SDL_Rect bgTarg2 = {background.target.x + background.target.w, background.target.y, background.target.w, background.target.h};

        //clear and prep the render for drawing a new frame
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        //rendering context -> all render commands should be done in this section
        background.render(renderer);
        background.render(renderer, NULL, &bgTarg2);

        title.animRender(renderer);

        menu.buttons[START]->buttonRender(renderer);
        menu.buttons[OPTIONS]->buttonRender(renderer);
        menu.buttons[CREDITS]->buttonRender(renderer);

        //draw the current frame
        SDL_RenderPresent(renderer);

        //scroll the background
        background.target.x--;
        if(background.target.x + background.target.w < 0) background.target.x = 0;
    }

    return false;
}

void creditsMenu(SDL_Renderer* renderer, inputHandler* handler, font* font) {

    //creates a rectangle that will be where the everything in the menu will be rendered, as well as where objects positions will be calculated in
    SDL_Rect menuViewport;
    menuViewport.w = SCREEN_WIDTH * .6;
    menuViewport.h = SCREEN_HEIGHT * .9;
    menuViewport.x = SCREEN_WIDTH/2 - menuViewport.w/2;
    menuViewport.y = SCREEN_HEIGHT/2 - menuViewport.h/2;

    //create the menu background
    renderObj menuBackground;
    menuBackground.createTexture("assets/button.png", renderer);
    menuBackground.setTarget(0, 0, menuViewport.w, menuViewport.h, TOP_LEFT);

    //create the menu object and button(s)
    menu credits;
    credits.buttons.emplace_back(new button("BACK", renderer));
    credits.buttons[0]->labelText.tex = font->createText(credits.buttons[0]->text, renderer);
    credits.buttons[0]->setTarget(menuViewport.x + menuViewport.w/2, menuViewport.y + menuViewport.h - 50, 100, 50);
    
    //create the menu title text
    renderObj title;
    title.tex = font->createText("CREDITS", renderer);
    title.setTarget(menuViewport.x + menuViewport.w/2, menuViewport.y + 50, menuViewport.w * .4, menuViewport.h * .07);

    while(!handler->quit) {

        handler->handle(); // handle input

        credits.buttonHandle(handler); //check buttons

        if(credits.buttons[0]->pressed) break;

        //render context
        SDL_SetTextureColorMod(menuBackground.tex, 0, 0, 0);
        menuBackground.render(renderer, NULL, &menuViewport);
        title.render(renderer);
        credits.buttons[0]->buttonRender(renderer);

        SDL_RenderPresent(renderer);

    }
}

//temporary menu, will not be documenting (everything here is pretty much copy pasted from other menus anyway)
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