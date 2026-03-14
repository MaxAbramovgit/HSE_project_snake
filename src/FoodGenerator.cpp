#include "FoodGenerator.h"


int start(int a) {// this function is made to understand what types of food should be generated at the begining of th game
    if (a == 1 || a == 2) {
        return 2;
    }
    if (a == 0) {
        return 3;
    }
    return 0;
}

FoodGenerator::FoodGenerator(int w, int h) : GameField(w, h) { //constructor
    counter_gen = 0;
    static bool seeded = false;
    poisoned_counter = 0;
    bomb_counter = 0;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seeded = true;
    }
}

std::unique_ptr<Food> FoodGenerator::generateRandomFood() { //generates food (without checking the collision with snake)
    int x = std::rand() % GetWidth();
    int y = std::rand() % GetHeight();
    int type;

    FoodTypes::Type foodType;

    if (counter_gen < 3) {
        type = start(counter_gen);
        counter_gen += 1;
    }
    else if (bomb_counter > 0) {
        if (poisoned_counter > 2) {
            type = std::rand() % 2;
            poisoned_counter -= 1;
        }
        else {
            type = std::rand() % 3;
        }
    }
    else {
        type = std::rand() % 4;
    }

    switch (type) {
        case 0:
            foodType = FoodTypes::Type::BANANA;
            break;
        case 1:
            foodType = FoodTypes::Type::HAMBURGER;
            break;
        case 2:
            foodType = FoodTypes::Type::POISON_APPLE;
            poisoned_counter += 1;
            break;
        case 3:
            foodType = FoodTypes::Type::BOMB;
            bomb_counter += 1;
            break;
        default:
            foodType = FoodTypes::Type::BANANA;
            break;
    }

    return std::make_unique<FoodTypes>(x, y, foodType);
}
std::optional<std::unique_ptr<Food>> FoodGenerator::generate(const Snake& snake) { //gives a std:move of coordinates and type of the food, i it doesnt generates on snake
    const int maxAttempts = 1000;
    int attempts = 0;

    while (attempts < maxAttempts) {
        auto food = generateRandomFood();
        if (!snake.collidesWith(food->getX(), food->getY())) {
            return std::move(food);
        }
        attempts++;
    }

    return std::nullopt;
}