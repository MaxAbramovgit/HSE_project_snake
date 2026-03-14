#pragma once
#include <memory>
#include <optional>
#include "GameField.h"
#include "Snake.h"
#include "Food.h"
#include "FoodTypes.h"
#include <memory>
#include <cstdlib>
#include <ctime>
#include <optional>

class FoodGenerator : public GameField {
    int counter_gen;
    int poisoned_counter;
    int bomb_counter;
public:
    FoodGenerator(int w, int h); //constructor

    std::optional<std::unique_ptr<Food>> generate(const Snake& snake); //generates food
    std::unique_ptr<Food> generateRandomFood(); //add food to vector
};