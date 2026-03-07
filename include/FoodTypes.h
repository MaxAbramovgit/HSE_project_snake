#pragma once
#include "Board.h"
#include "Food.h"

class FoodTypes : public Food {
public:
    enum class Type {
        BANANA,
        HAMBURGER,
        BOMB,
        POISON_APPLE
    };
    Type getType() const{return food_type};
private:
    Type food_type;
public:
    FoodTypes(int newX, int newY, Type R);
    int GetPoints() const;
    void applyEffect(Snake& snake) override;
};