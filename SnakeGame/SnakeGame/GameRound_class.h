#pragma once

class GameRound {
public:
    // Member variables
    int FoodX;
    int FoodY;

    // Constructor
    GameRound();

    // Destructor
    ~GameRound();

    // Member functions
    void GenerateFood(int gridWidthX, int gridWidthY);
    void PlayRound();
};
