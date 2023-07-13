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

        if(!mainMenu(window.gameRenderer, &handler)) return 0;

    }
    closeSDL();
    return 0;
}