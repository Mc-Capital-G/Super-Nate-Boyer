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

        while (!handler.quit) {
            handler.handle();

            

            SDL_RenderClear(window.gameRenderer);
            
            //title.render(window.gameRenderer);
            SDL_Rect temp = {1280/2, 720/2, 200, 200};
            title.animRender(window.gameRenderer, &temp);

            SDL_RenderPresent(window.gameRenderer);
            SDL_Delay(100);
        }

    }
    closeSDL();
    return 0;
}