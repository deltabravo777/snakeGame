// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Board_class.h"

int GridWidthX = 75;
int GridWidthY = 35;
int Points = 0;
int Turns = 0;
int Growth = 2;
int GameDelay = 125;

void testKeyPressedDelayLoop();

int main()
{

    std::cout << "Hello World!\n";

    if (false) testKeyPressedDelayLoop();

    //Board board;
    //board.testPrintDefaultBoard();
    GameRound* gameRound = new GameRound;

    std::cout << "Press the Enter key to start playing! use the WASD keys for directions" << std::endl;
    std::cin.get();

    gameRound->PlayRound();

    delete gameRound;

    if (true) {
        //-- Accomplishments:
        //   1 food will not appear within the same coordinates as an existing snake segment
        //   2 game is printing over itself, the cursor has been removed. this prevents screen flickering
        //   3 gamespeed and snake growth are not hard-wired, and saved as global variables above, as well as board size
        //   4 the score the printed as the bottom
        //   5 keystrokes are not cleared after each iteration of the main-game while loop, so each keystroke is registered, making the game easy to play
        //   6 Board, Keyboard, Snake, and GameRound are all help allocated, to not hoarde memory in registers

        //-- To Do
        //-- replay round
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
