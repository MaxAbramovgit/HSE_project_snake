#pragma once
#pragma once

#include "GameField.h"
#include "Snake.h"
#include "Food.h"

class Board : public GameField {
    std::unique_ptr<Snake> snake;
    std::unique_ptr<Food> food;
    bool over;
    size_t score;
public:
    Board(int x, int y);

    int GetHeight() const;
    int GetWidth() const;

    Snake& getSnake() const;

    Food* getFood() const;

    bool isGameOver() const;

    void setFood(std::unique_ptr<Food> food);

    ~Board() = default;

    void update();

    int getScore() const;

};
