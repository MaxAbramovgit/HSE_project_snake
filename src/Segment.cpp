#include "../include/Segment.h"

Segment::Segment(int startX, int startY) : GameEntity(startX, startY) {}

char Segment::getSymbol() const {
    return 'O';
}