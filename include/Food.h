#pragma once
#include <memory>
#include "GameEntity.h"

class Food : public GameEntity {
public:
    Food(int x, int y) : GameEntity(x, y) {}
    virtual ~Food() = default;

    virtual int getPoints() const = 0;
    virtual void applyEffect(class Snake& snake) = 0;
};