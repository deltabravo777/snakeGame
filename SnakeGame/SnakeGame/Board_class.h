#pragma once

#pragma once

#include <iostream>
#include <thread>  // For std::this_thread::sleep_for
#include <chrono>  // For std::chrono::milliseconds
#include <windows.h>
#include "GameRound_class.h"
#include "Snake_class.h"

class Board {
public:
    // Member variables
    int X;
    int Y;

    // Constructor
    Board();

    // Member functions
    void testPrintDefaultBoard();

    void PrintBoard();
    void EditBoard(GameRound* gameRound, Snake* snake);

    void SetCursorPosition(int x, int y);

    void ClearAtPosition(int x, int y);
};
