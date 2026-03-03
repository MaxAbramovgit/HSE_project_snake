#include "../include/Segment.h"

int a = 0;
Segment::Segment(int startX, int startY) : GameEntity(startX, startY) {}

char Segment::getSymbol() const {
    return 'O';
}