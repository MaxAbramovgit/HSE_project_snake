#include "../include/FoodGenerator.h"

FoodGenerator::FoodGenerator(int x, int y) : GameField(x, y) {
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seeded = true;
    }
}

std::unique_ptr<Food> FoodGenerator::generateRandomFood() {
    int x = std::rand() % getWidth();
    int y = std::rand() % getHeight();
    int type = std::rand() % 4;  // 0,1,2,3

    switch (type) {
        case 0: return std::make_unique<SpeedFood>(x, y);
        case 1: return std::make_unique<SlowFood>(x, y);
        case 2: return std::make_unique<GhostFood>(x, y);
        case 3: return std::make_unique<PoisonFood>(x, y);
        default: return std::make_unique<SpeedFood>(x, y);
    }
}

std::unique_ptr<Food> FoodGenerator::generateFoodNotOnSnake(const Snake& snake) {
    while (true) {
        auto food = generateRandomFood();
        if (!snake.collidesWith(food->getX(), food->getY())) {
            return food;
        }
    }
}
