#include "includeSDL.h"
#include "window.h"

int main(int argc, char* argv[]) {

    Window window;
    if(!window.init(1280, 720)) {
        return 1;
    }
    else SDL_Delay(10000);

    return 0;
}