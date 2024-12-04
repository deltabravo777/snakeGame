#include "GameRound_class.h"
#include "Snake_class.h"
#include "Board_class.h"
#include "Keyboard_class.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iostream>
#include <thread>   // For std::this_thread
#include <chrono>   // For std::chrono::milliseconds


// Extern declarations for global variables
extern int GridWidthX;
extern int GridWidthY;
extern int Points;
extern int Turns;
extern int Growth;
extern int GameDelay;

Board* board;
Snake* snake;
Keyboard* keyboard;

// Constructor initializes FoodX and FoodY to (maxX - 10, maxY - 10)
GameRound::GameRound()
    : FoodX(GridWidthX - 10), FoodY(GridWidthY - 10) {
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

// Function to randomly generate food coordinates within the specified range
void GameRound::GenerateFood(int maxX, int maxY) {

    while (true) {
        // Ensure FoodX is at least 5 and less than (maxX - 5)
        FoodX = 5 + (std::rand() % (maxX - 10));

        // Ensure FoodY is at least 5 and less than (maxY - 5)
        FoodY = 5 + (std::rand() % (maxY - 10));
    
        if (std::find(snake->segments.begin(), snake->segments.end(), std::make_pair(FoodX, FoodY)) == snake->segments.end()) {
            break; // Position is not in the segments; exit the loop
        }

        break;
    }

    
}


void GameRound::PlayRound() {
    bool gameOver = false;
    int ateFood = 0;
    
    // Create a Snake instance (assuming Snake class is accessible)
    
    board = new Board;
    snake = new Snake(board);
    keyboard = new Keyboard;

    // Start the game loop
    while (!gameOver) {
        // Call methods in the desired order for each loop iteration

        board->PrintBoard();
        keyboard->GetKeyStrokes(snake);

        // Move the snake
        if (ateFood == 0) {
            if (Turns++ < 5) {
                snake->MoveAndGrow();
            }
            else {
                snake->MoveAndDontGrow();
            }
            
        }
        else {
            snake->MoveAndGrow();
            if (ateFood == Growth) {
                //Points++;
                //-- we dont increment Points++, since this is done within the EatFood method, which is called below, when the snake intercepts a Food
            }

            ateFood = ateFood--;
        }
        

        // Check if the snake eats food
        //snake.EatFood();

        // Generate new food if the snake eats it
        //-- X is a 1's based system, so the lowest x coordinate that is still in bounds is 1, not 0
        //-- we could make the code below look like FoodX and SnakeX are equal if we changed our print method, which would make the 
        //   left-most empty column part of out-of-bounds, which is a bug
        //-- we could alternatively make 0,0 part of being in-bounds
        if (snake->segments.front().first - 1 == FoodX && snake->segments.front().second == FoodY) {
            snake->EatFood();
            ateFood = 2;
            GenerateFood(GridWidthX, GridWidthY);  // Generate food in the grid of size 50x35
        }

        // Placeholder for game over condition (this can be based on collisions, etc.)
        // For now, we will just loop indefinitely
        //-- after testing, y has less complication in its alignment with the border, so making it merely above 0 works fine
        if (snake->segments.front().first <= 0 || snake->segments.front().first > GridWidthX ||
            snake->segments.front().second < 0 || snake->segments.front().second > GridWidthY) {
            gameOver = true;
            std::cout << "Game Over! Snake went out of bounds.\n";
        }

        board->EditBoard(this, snake);

        // Add a short delay to make the game playable (adjust as needed)
        std::this_thread::sleep_for(std::chrono::milliseconds(GameDelay));  // Adjust speed
    }

    delete board;
    delete snake;
    delete keyboard;
}

GameRound::~GameRound() {
    //-- this has thrown an exception, stack overflow
    //delete this;
}