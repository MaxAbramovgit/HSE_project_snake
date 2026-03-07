#pragma once
#include "GameEntity.h"
#include "Snake.h"

class Food : public GameEntity {
public:
    Food(int x, int y) : GameEntity(x, y) {}

    virtual int getPoints() const = 0;
    virtual void applyEffect(Snake& snake) = 0;
    virtual ~Food() = default;
};