#include "../include/FoodGenerator.h"

FoodGenerator::FoodGenerator(int x, int y) : GameField(x, y) {
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seeded = true;
    }
}

std::unique_ptr<Food> FoodGenerator::generateRandomFood() {}

std::unique_ptr<Food> FoodGenerator::generateFoodNotOnSnake(const Snake& snake) {
    while (true) {
        auto food = generateRandomFood();
        if (!snake.collidesWith(food->getX(), food->getY())) {
            return food;
        }
    }
}
