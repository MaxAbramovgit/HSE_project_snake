#pragma once
#include "GameEntity.h"

class Segment : public GameEntity {
public:
    Segment(int startX, int startY);
    char getSymbol() const override;
};
