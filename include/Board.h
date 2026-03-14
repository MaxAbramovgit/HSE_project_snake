#pragma once

#include "GameField.h"
#include "Snake.h"
#include "Food.h"
#include <vector>


class Board : public GameField {
    std::unique_ptr<Snake> snake;
    std::vector<std::unique_ptr<Food>> food;
    bool over;
    int score;
public:
    Board(int x, int y); //constructor

    void addFood(std::unique_ptr<Food> newfood); //adds new food to constructor

    int GetHeight() const override; //return height
    int GetWidth() const override; //return width

    Snake& getSnake() const; //return pointer to the snake

    const std::vector<std::unique_ptr<Food>>&  getFood() const; //return pointer to the vector of the food

    bool isGameOver() const; //return over

    void update(); //updates frames

    int getScore() const; //returns score

    bool isCellOccupiedByFood(int x, int y) const; //checks if cell is occupied by food

    ~Board() override; //destructor
};
