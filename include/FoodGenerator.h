#pragma once
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Food.h"
#include "Board.h"

class FoodGenerator : public GameField {
public:
    FoodGenerator(int x, int y);

    std::unique_ptr<Food> generateRandomFood();
    std::unique_ptr<Food> generate(const Snake& snake);
};