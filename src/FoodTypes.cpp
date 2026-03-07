#include "../include/FoodTypes.h"
#include "../include/GameEntity.h"
#include "../include/Board.h"
FoodTypes::FoodTypes(int x, int y, Type R) : Food(x, y), food_type(R){}

int FoodTypes::GetPoints() const {
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