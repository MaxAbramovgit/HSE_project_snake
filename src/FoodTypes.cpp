#include "../include/FoodTypes.h"
#include "Food.h"
#include "../include/Board.h"
FoodTypes::FoodTypes(int newX, int newY, Type R) : Food(newX, newY), food_type(R){}

int FoodTypes::getPoints() const{
    switch (food_type) {
        case Type::BANANA:
            return 1;
        case Type::HAMBURGER:
            return 2;
        case Type::POISON_APPLE:
            return -1;
        case Type::BOMB:
            return -3;
    }
    return 0;
};

void FoodTypes::applyEffect(Snake &snake) {
    switch (food_type) {
        case Type::BANANA:
            snake.grow();
            break;
        case Type::HAMBURGER:
            snake.grow();
            snake.grow();
            break;
        case Type::POISON_APPLE:
            snake.shrink();
            break;
        case Type::BOMB:
            snake.die();
            break;
    }
}
