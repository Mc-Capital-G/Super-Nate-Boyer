#include "includeSDL.h"
#include "inputHandler.h"
#include "window.h"
#include "closeSDL.h"
#include "renderObj.h"
#include "animatedObj.h"

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

        while (!handler.quit) {
            handler.handle();

            

            SDL_RenderClear(window.gameRenderer);
            
            title.animRender(window.gameRenderer, 440, 120, 400, 400);
            globe.animRender(window.gameRenderer, 0, 620, 100, 100);


            SDL_RenderPresent(window.gameRenderer);
            SDL_Delay(100);
        }

    }
    closeSDL();
    return 0;
}