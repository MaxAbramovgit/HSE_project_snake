//
// Created by sophie on 26/02/2026.
//

#include "../include/FoodTypes.h"
FoodTypes::FoodTypes(int x, int y, Type R): GameEntity(x, y), food_type(R){}

int FoodTypes::GetPoints() {
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
}