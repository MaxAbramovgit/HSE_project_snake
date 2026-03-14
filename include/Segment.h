#pragma once
#include "GameEntity.h" // includes base class because Segment inherits from it

class Segment : public GameEntity { // public inheritance
public:
    Segment(int startX, int startY); // constructor takes initial coordinates and passes them to GameEntity constructor

    char getSymbol() const override; // overrides virtual method from GameEntity. Returns 'O' as visual representation of snake segment. 'override' keyword ensures we're actually overriding a virtual method
};
