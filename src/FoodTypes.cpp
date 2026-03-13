#include "../include/FoodTypes.h"
#include "Food.h"
#include "../include/Board.h"
FoodTypes::FoodTypes(int newX, int newY, Type R) : Food(newX, newY), food_type(R){}

int FoodTypes::getPoints()const{
    switch (food_type) {
        case Type::BANANA: {
            constexpr int BANANA_POINTS = 1;
            return BANANA_POINTS;
        }
        case Type::HAMBURGER: {
            constexpr int HAMBURGER_POINTS = 2;
            return HAMBURGER_POINTS;
        }
        case Type::POISON_APPLE: {
            constexpr int POISON_POINTS = -1; //чтобы на этапе компилляции эти переменные сразу заровнялись и не тратили ни секунду времени (сейвит время) + inline дописать можно
            return POISON_POINTS;
        }
        case Type::BOMB: {
            constexpr int BOMB_POINTS = -3;
            return BOMB_POINTS;
        }
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
//нельзя статистический тк метод каждый разный свой food_type (про case)