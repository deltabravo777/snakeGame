#pragma once
#include <vector>
#include <utility> // For std::pair

// Forward declaration of Board class
class Board;

class Snake {
public:
    // Enum for directions
    enum Direction {
        Up,
        Right,
        Down,
        Left
    };

    // Member variables
    Board* board; // Reference to the Board object
    std::vector<std::pair<int, int>> segments; // Stores the positions of the snake segments
    Direction currentDirection = Up;
    

    // Constructor
    Snake(Board* boardRef); // Use const reference

    // Destructor
    ~Snake();  // Destructor declaration

    // Member functions
    void Move();
    void MoveAndGrow();
    void MoveAndDontGrow();
    void SetDirection(Direction dir);
    Direction GetDirection() const;
    std::pair<int, int> GetHeadPosition() const;
    void EatFood();


};
