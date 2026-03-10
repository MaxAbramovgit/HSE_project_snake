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
    Board(int x, int y);

    void addFood(std::unique_ptr<Food> food);

    int GetHeight() const override;
    int GetWidth() const override;

    Snake& getSnake() const;

    const std::vector<std::unique_ptr<Food>>& getFood() const;

    bool isGameOver() const;

    void update();

    int getScore() const;

    ~Board() override;
};
