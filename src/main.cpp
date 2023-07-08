#include "includeSDL.h"
#include "inputHandler.h"
#include "window.h"
#include "closeSDL.h"

int main(int argc, char* argv[]) {

    Window window;
    if(!window.init(1280, 720)) {
        return 1;
    }
    else {
        inputHandler handler;
        handler.inputTimer.start();

        while (!handler.quit) {
            handler.handle();

            SDL_RenderClear(window.gameRenderer);

            SDL_RenderPresent(window.gameRenderer);
        }

    }
    closeSDL();
    return 0;
}