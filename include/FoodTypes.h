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
    Type getType() const{return food_type};
protected:
    Type food_type;
    FoodTypes(int newX, int newY, Type R);
    int GetPoints() const;
    void applyEffect(Snake& snake) override;
};