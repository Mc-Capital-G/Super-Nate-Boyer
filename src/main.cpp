#include "includeSDL.h"
#include "inputHandler.h"
#include "window.h"
#include "closeSDL.h"
#include "renderObj.h"
#include "animatedObj.h"
#include "menu.h"
#include "font.h"

int main(int argc, char* argv[]) {

    Window window;
    if(!window.init("Super Nate Boyer", SCREEN_WIDTH, SCREEN_HEIGHT)) {
        return 1;
    }
    else {
        inputHandler handler;
        handler.inputTimer.start();

        animatedObj title("assets/titlewiggle.png", window.gameRenderer, 15, 800, 800);
        animatedObj globe("assets/nateboyer3d.png", window.gameRenderer, 10, 400, 400);
        font PublicPixel("assets/PublicPixel.ttf");
        button test("START", window.gameRenderer);
        

        while (!handler.quit) {
            handler.handle();

            

            SDL_RenderClear(window.gameRenderer);
            SDL_SetRenderDrawColor(window.gameRenderer, 0x00, 0x00, 0x00, 0x00);
            
            title.animRender(window.gameRenderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 400, 400);
            globe.animRender(window.gameRenderer, 0 + globe.target->w/4, SCREEN_HEIGHT - globe.target->h/4, 100, 100);
            test.buttonRender(window.gameRenderer, SCREEN_WIDTH/2, title.target->y + title.target->h/2, 200, 100);
            PublicPixel.display(test.text, window.gameRenderer, test.target->x + test.target->w/2, test.target->y + test.target->h/2, test.target->w, 25);

            SDL_RenderPresent(window.gameRenderer);
            SDL_Delay(100);
        }

    }
    closeSDL();
    return 0;
}