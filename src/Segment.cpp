#include "../include/Segment.h"

Segment::Segment(int startX, int startY, SegmentType t)
    : GameEntity(startX, startY), type(t) {}

SegmentType Segment::getType() const { return type; }
void Segment::setType(SegmentType t) { type = t; }

char Segment::getSymbol() const {
    return (type == SegmentType::GHOST) ? '~' : '#';
}