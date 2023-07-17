#include "includeSDL.h"
#include "inputHandler.h"
#include "window.h"
#include "closeSDL.h"
#include "renderObj.h"
#include "animatedObj.h"
#include "menu.h"
#include "font.h"
#include "game.h"

int main(int argc, char* argv[]) {

    Window window;
    if(!window.init("Super Nate Boyer", SCREEN_WIDTH, SCREEN_HEIGHT)) {
        return 1;
    }
    else {
        inputHandler handler;
        handler.inputTimer.start();

        if(!mainMenu(window.gameRenderer, &handler)) return 0;
        game(window.gameRenderer, &handler);

    }
    closeSDL();
    return 0;
}