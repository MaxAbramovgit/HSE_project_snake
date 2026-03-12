#pragma once
#include <memory>
#include <optional>
#include "GameField.h"
#include "Snake.h"
#include "Food.h"

class FoodGenerator : public GameField {
    int counter_gen;
    int poisoned_counter;
    int bomb_counter;
public:
    FoodGenerator(int w, int h);

    std::optional<std::unique_ptr<Food>> generate(const Snake& snake);
    std::unique_ptr<Food> generateRandomFood();
};