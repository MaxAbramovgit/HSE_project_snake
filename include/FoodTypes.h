#pragma once
#include <memory>
#include "Board.h"
#include "GameEntity.h"

class FoodTypes : GameEntity {
public:
    enum class Type {
        BANANA,
        HAMBURGER,
        BOMB,
        POISON_APPLE
    };
    Type food_type;
    FoodTypes(int x, int y, Type R);
    int GetPoints();