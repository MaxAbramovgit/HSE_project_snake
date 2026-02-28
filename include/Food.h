#pragma once
#include <memory>
#include "Board.h"
#include "GameEntity.h"

class Food : public GameEntity {
public:
    Food(int x, int y) : GameEntity(x, y) {}
    virtual ~Food() = default;

    virtual int GetPoints() const = 0;
    virtual char GetSymbol() const = 0;

};