#pragma once

#include "animatedObj.h"
#include "inputHandler.h"
#include "window.h"

enum DIRECTIONS {
    UP = 0,
    LEFT = 1,
    DOWN = 2,
    RIGHT = 3
}

class Player : public animatedObj {

public:
    


private:
    int faceDirection;
};