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
        animatedObj globe("assets/nateboyer3d.png", window.gameRenderer, 10, 400, 400, 100);
        font PublicPixel("assets/PublicPixel.ttf", 25);
        button test("START", window.gameRenderer);
        test.labelText = PublicPixel.createText(test.text, window.gameRenderer);
        

        while (!handler.quit) {
            handler.handle();

            

            SDL_RenderClear(window.gameRenderer);
            SDL_SetRenderDrawColor(window.gameRenderer, 0xFF, 0xFF, 0xFF, 0x00);
            
            title.animRender(window.gameRenderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/3, 400, 400);
            globe.animRender(window.gameRenderer, 0 + 100/2, SCREEN_HEIGHT - 100/2, 100, 100);
            test.buttonRender(window.gameRenderer, SCREEN_WIDTH/2, title.target->y, 200, 100);

            SDL_RenderPresent(window.gameRenderer);
        }

    }
    closeSDL();
    return 0;
}