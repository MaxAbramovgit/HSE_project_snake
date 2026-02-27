#pragma once
#include <memory>
#include "Board.h"
#include "GameEntity.h"

class Food : GameEntity{
public:
    enum Type {
        BANANA,
        HUMBURGER,
        BOMB,
    };
    Type food_type;
    Food(int x, int y, Type R): GameEntity(x, y), food_type(R);
    int GetPoints() {
        if (food_type == BANANA) {
            return 1;
        }
        if (food_type == HUMBURGER) {
            return 2;
        }
        if (food_type == BOMB) {
            return -1;
        }
        return 0;
    }
};