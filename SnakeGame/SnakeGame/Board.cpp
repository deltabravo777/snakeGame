#include "Board_class.h"
#include "GameRound_class.h"
#include "Snake_class.h"

extern int GridWidthX;
extern int GridWidthY;
extern int Points;

Board::Board() : X(3), Y(4) {}

void Board::SetCursorPosition(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // Get console handle
    COORD coord = { x, y };  // Define the cursor position (x = column, y = row)
    SetConsoleCursorPosition(consoleHandle, coord); // Set the cursor position
}

void Board::PrintBoard() {
    //system("cls");
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false; // Set the cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    SetCursorPosition(0, 0);
    std::cout << "|===========================================================================|" << std::endl;

    //for (int i = 1; i <= GridWidthY; i++) {
    //    SetCursorPosition(0, i);
    //    if (Y != GridWidthY - i) {
    //    //if (false) {

    //        std::cout << "|                                                                           |" << std::endl;
    //    }
    //    else {
    //        std::cout << "|";
    //        for (int j = 1; j < X; j++) {
    //            std::cout << " ";
    //        }

    //        bool testing = false;
    //        if (testing) {
    //            std::cout << "&";
    //        }
    //        else {
    //            std::cout << " ";
    //        }
    //        

    //        for (int j = 1; j <= GridWidthX - 1 - X; j++) {
    //            std::cout << " ";
    //        }
    //        std::cout << "|         " << std::endl;
    //        
    //    }
    //}




    for (int i = 1; i <= GridWidthY; i++) {
        SetCursorPosition(0, i);
        //std::cout << "|===========================================================================|" << std::endl;
        std::cout << "|                                                                           |       " << std::endl;
    }
    /*std::cout << "|==================================================|" << std::endl;*/
    std::cout << "|===========================================================================|" << std::endl;
    if (Y < 30) {
        Y++;
    }
    else {
        Y = 3;
    }


    //while (true) {
    //   //--^^ the code that originated here has been mvoed
    //    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    //}
}

void Board::EditBoard(GameRound* gameRound, Snake* snake) {
    //system("cls");
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false; // Set the cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    SetCursorPosition(0, 0);

    // 0 , 0  corresponds to 1 , maxY + 1
    // actual console [x,y] == x + 1, maxY - y + 1
    // |----------
    // |
    // |

        // Loop through the snake's body and print '#' for each segment
    for (const auto& segment : snake->segments) {
        // Extract x, y position of the segment
        int gameX = segment.first;
        int gameY = segment.second;

        // Convert game coordinates to console coordinates
        int consoleX = gameX;                       // Adjust for console x-coordinate
        int consoleY = GridWidthY - gameY + 1;      // Adjust for console y-coordinate

        // Set the cursor position and print '#'
        SetCursorPosition(consoleX, consoleY);
        std::cout << "#";
    }

    int foodX = gameRound->FoodX;
    int foodY = gameRound->FoodY;
    SetCursorPosition(foodX + 1, GridWidthY - foodY + 1);  // Adjust food position
    std::cout << "*"; // Using '*' for food or any other symbol you prefer


    SetCursorPosition(0, GridWidthY+3);
    std::cout << "Points: " << Points << std::endl;
}

void Board::testPrintDefaultBoard() {

    while (true) {
        Board::PrintBoard();
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}

void Board::ClearAtPosition(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false; // Set the cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    SetCursorPosition(x, GridWidthY - y + 1);
    std::cout << " ";

}