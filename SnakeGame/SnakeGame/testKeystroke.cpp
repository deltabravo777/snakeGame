#pragma once
#include <string>
#include <thread>  // For std::this_thread::sleep_for
#include <chrono>  // For std::chrono::milliseconds
#include <vector>
#include <iostream>
#include <conio.h>


void testKeyPressedDelayLoop() {
    std::vector<std::vector<std::string>> grid(3, std::vector<std::string>(3, ""));

    for (int i = 1; i <= 20; i++) {
        // Wait for 500 milliseconds (half a second)
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
         
        bool arrowKey = false;

        // Check if a key has been pressed
        if (_kbhit()) {
            char key = _getch();  // Get the pressed key

            //-- this is in case we are using the arrow keys, which for now dont work
            if (key == 27) {  // If it's an escape character, handle special keys like arrow keys
                char next = _getch();  // Get the next character
                if (next == 91) {  // 91 is the next byte for the arrow key escape sequences
                    char arrow = _getch();  // Get the actual arrow key code
                    switch (arrow) {
                    case 65:
                        arrowKey = true;
                        std::cout << "Up Arrow pressed!" << std::endl;
                        break;
                    case 66:
                        arrowKey = true;
                        std::cout << "Down Arrow pressed!" << std::endl;
                        break;
                    case 67:
                        arrowKey = true;
                        std::cout << "Right Arrow pressed!" << std::endl;
                        break;
                    case 68:
                        arrowKey = true;
                        std::cout << "Left Arrow pressed!" << std::endl;
                        break;
                    default:
                        arrowKey = true;
                        std::cout << "Unknown special key" << std::endl;
                        break;
                    }
                }
            }
            /*else {
                std::cout << "Iteration " << i << ": You pressed: " << key << std::endl;
            }*/

            //-- added this so we dont register multiple key presses that carry over to the next iteration
            while (_kbhit()) {
                key = _getch();
            }

            if(arrowKey) {
                std::cout << "Iteration " << i << ": You pressed arrow key: " << key << std::endl;
            }
            else {
                std::cout << "Iteration " << i << ": You pressed: " << key << std::endl;
                // H M P K -- up, right, down, left
            }
        }
        else {
            std::cout << "Iteration " << i << ": No key pressed" << std::endl;
        }
    }
}