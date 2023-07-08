#include "includeSDL.h"
#include "inputHandler.h"
#include "window.h"
#include "closeSDL.h"
#include "renderObj.h"
#include "animatedObj.h"

int main(int argc, char* argv[]) {

    Window window;
    if(!window.init(1280, 720)) {
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
            
            title.animRender(window.gameRenderer, 540, 260, 200, 200);
            globe.animRender(window.gameRenderer, 0, 0);


            SDL_RenderPresent(window.gameRenderer);
            SDL_Delay(100);
        }

    }
    closeSDL();
    return 0;
}