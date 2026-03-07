#include "FoodGenerator.h"
#include "FoodTypes.h"
#include <memory>
#include <cstdlib>
#include <ctime>

FoodGenerator::FoodGenerator(int w, int h) : GameField(w, h) {
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seeded = true;
    }
}

std::unique_ptr<Food> FoodGenerator::generateRandomFood() {
    int x = std::rand() % GetWidth();
    int y = std::rand() % GetHeight();
    int type = std::rand() % 4;

    FoodTypes::Type foodType;
    switch (type) {
        case 0:
            foodType = FoodTypes::Type::BANANA;
            break;
        case 1:
            foodType = FoodTypes::Type::HAMBURGER;
            break;
        case 2:
            foodType = FoodTypes::Type::POISON_APPLE;
            break;
        case 3:
            foodType = FoodTypes::Type::BOMB;
            break;
        default:
            foodType = FoodTypes::Type::BANANA;
            break;
    }

    return std::make_unique<FoodTypes>(x, y, foodType);
}

std::unique_ptr<Food> FoodGenerator::generateFoodNotOnSnake(const Snake& snake) {
    while (true) {
        auto food = generateRandomFood();
        if (!snake.collidesWith(food->getX(), food->getY())) {
            return food;
        }
    }
}