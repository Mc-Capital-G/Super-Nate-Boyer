#pragma once
#include "button.h"
#include "font.h"
#include <vector>


class menu : public renderObj{
public:
    menu();
    ~menu();
    int pressButton();
    bool press(int x, int y);
    std::vector<button*> buttons;
    font* font;
};