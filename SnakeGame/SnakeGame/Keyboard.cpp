#include "Keyboard_class.h"

// Function to detect arrow key input and update the snake's direction
void Keyboard::GetKeyStrokes(Snake* snake) {


    //char key;
    std::vector<int> keyPresses;

    /*while (_kbhit()) {
        key = _getch();
    }*/

    //while (_kbhit()) {
    //    char key = _getch();  // Get the key pressed
    //    keyPresses.push_back(key);  // Store it in the vector

    //    // Limit the vector to the last 3 elements
    //    if (keyPresses.size() > 3) {
    //        keyPresses.erase(keyPresses.begin(), keyPresses.begin() + keyPresses.size() - 2);
    //    }

    //}

    while (_kbhit()) {
        char key = _getch();  // Get the key pressed

        // Clear the vector and store only the last key pressed
        //keyPresses.clear();
        keyPresses.push_back(key);
        break;
    }


    if (!keyPresses.empty()) {
        int firstKey = keyPresses[0];  // The first key pressed
        switch (firstKey) {
        case 119:  // Up arrow
            snake->SetDirection(Snake::Up);
            //std::cout << "Up Arrow pressed!" << std::endl;
            break;
        case 115:  // Down arrow
            snake->SetDirection(Snake::Down);
            //std::cout << "Down Arrow pressed!" << std::endl;
            break;
        case 100:  // Right arrow
            snake->SetDirection(Snake::Right);
            //std::cout << "Right Arrow pressed!" << std::endl;
            break;
        case 97:  // Left arrow
            snake->SetDirection(Snake::Left);
            //std::cout << "Left Arrow pressed!" << std::endl;
            break;
        default:
            //std::cout << "Unknown special key" << std::endl;
            break;
        }
    }

    // Check if a key has been pressed
//if (_kbhit()) {
//    int key = _getch(); // Get the key code

//    // Arrow keys return two codes: 0 or 224 followed by the actual code
//    if (key == 0 || key == 224) {
//        key = _getch(); // Get the actual arrow key code

//        // Update the snake's direction based on arrow key input
//        switch (key) {
//        case 72: // Up arrow
//            snake.SetDirection(Snake::Up);
//            break;
//        case 77: // Right arrow
//            snake.SetDirection(Snake::Right);
//            break;
//        case 80: // Down arrow
//            snake.SetDirection(Snake::Down);
//            break;
//        case 75: // Left arrow
//            snake.SetDirection(Snake::Left);
//            break;
//        }
//    }
//}


    //if (!keyPresses.empty()) {
    //    int firstKey = keyPresses[0];  // The first key pressed
    //    if (firstKey == 27) {  // ESC key, start of escape sequence
    //        int nextKey = keyPresses[1];  // Get the next character (91 for arrow keys)
    //        if (nextKey == 91) {  // 91 is the next byte for arrow keys
    //            char arrowKey = keyPresses[2];  // Get the actual arrow key code
    //            switch (arrowKey) {
    //            case 65:  // Up arrow
    //                snake.SetDirection(Snake::Up);
    //                //std::cout << "Up Arrow pressed!" << std::endl;
    //                break;
    //            case 66:  // Down arrow
    //                snake.SetDirection(Snake::Down);
    //                //std::cout << "Down Arrow pressed!" << std::endl;
    //                break;
    //            case 67:  // Right arrow
    //                snake.SetDirection(Snake::Right);
    //                //std::cout << "Right Arrow pressed!" << std::endl;
    //                break;
    //            case 68:  // Left arrow
    //                snake.SetDirection(Snake::Left);
    //                //std::cout << "Left Arrow pressed!" << std::endl;
    //                break;
    //            default:
    //                //std::cout << "Unknown special key" << std::endl;
    //                break;
    //            }
    //        }
    //    }
    //}
}
