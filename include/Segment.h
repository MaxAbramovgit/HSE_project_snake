#pragma once

#include "GameEntity.h"

enum class SegmentType { NORMAL, GHOST };

class Segment : public GameEntity {
    SegmentType type;

public:
    Segment(int startX, int startY, SegmentType t = SegmentType::NORMAL);
    
    SegmentType getType() const;

    void setType(SegmentType t);
    
    char getSymbol() const override;
};