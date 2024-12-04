#pragma once

#include <conio.h>  // For _kbhit() and _getch()
#include "Snake_class.h"

class Keyboard {
public:
    // Function to get keystrokes and update the snake's direction
    void GetKeyStrokes(Snake* snake);
};
