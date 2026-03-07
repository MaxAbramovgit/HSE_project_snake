#pragma once
#include <memory>
#include "Board.h"
#include "GameEntity.h"

class FoodTypes : public Food {
public:
    enum class Type {
        BANANA,
        HAMBURGER,
        BOMB,
        POISON_APPLE
    };
private:
    Type food_type;
    FoodTypes(int x, int y, Type type);
    int GetPoints() const;
};