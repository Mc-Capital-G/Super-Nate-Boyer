#pragma once

//Include SDL library and other globally accessed libraries

#if defined(__APPLE__)

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>

#else

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#endif

#include <cstdlib>
#include <string>
#include <stdio.h>
#include <iostream>