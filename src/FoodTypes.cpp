#include "../include/FoodTypes.h"
#include "../include/GameEntity.h"
FoodTypes::FoodTypes(int x, int y, Type R) : Food(x, y), food_type(R){}

int FoodTypes::GetPoints() const {
    if (food_type == Type::BANANA) {
        return 1;
    }
    if (food_type == Type::HAMBURGER) {
        return 2;
    }
    if (food_type == Type::POISON_APPLE) {
        return -1;
    }
    return 0;
};