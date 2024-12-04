#include "Snake_class.h"
#include "Board_class.h"

extern int Points;

// Constructor initializes the snake with a starting position and direction
Snake::Snake(Board* boardRef) :
    currentDirection(Up),
    board(boardRef) {
    segments.push_back({ 10, 10 }); // Initial position of the snake's head
}


// Move the snake in the current direction
void Snake::Move() {
    std::pair<int, int> head = segments.front();
    int HeadX = head.first;
    int HeadY = head.second;


    switch (currentDirection) {
    case Up:    HeadY++; break;
    case Right: HeadX++; break;
    case Down:  HeadY--; break;
    case Left:  HeadX--; break;
    }

    std::pair<int, int> NewHead = std::make_pair(HeadX, HeadY);

    segments.insert(segments.begin(), NewHead);

  /*  segments.pop_back();*/
}

void Snake::MoveAndGrow() {
    Snake::Move();
}

void Snake::MoveAndDontGrow() {
    Snake::Move();
    std::pair<int, int> lastSegmentPosition = segments.back();
    segments.pop_back();
    board->ClearAtPosition(lastSegmentPosition.first, lastSegmentPosition.second);
}

// Grow the snake by adding a new segment
//void Snake::Grow() {
//    segments.push_back(segments.back());
//}

// Set the current direction of the snake

void Snake::EatFood() {
    Points++;
}



void Snake::SetDirection(Direction dir) {
    if ((currentDirection == Up && dir != Down) ||
        (currentDirection == Down && dir != Up) ||
        (currentDirection == Left && dir != Right) ||
        (currentDirection == Right && dir != Left)) {
        currentDirection = dir;
    }
}

// Get the current direction of the snake
Snake::Direction Snake::GetDirection() const {
    return currentDirection;
}

// Get the position of the snake's head
std::pair<int, int> Snake::GetHeadPosition() const {
    return segments.front();
}

// Destructor (empty for now, as no dynamic memory needs to be freed)
Snake::~Snake() {
    //-- all the deletes of the objects were done in PlayGameRound, which delted:
    //   Board
    //   Snake
    //   Keyboard
    //   and GameRound deleted itself in its destructor
}