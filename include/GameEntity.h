#pragma once

class GameEntity {
protected: // available to this class and all its descendants, but not to external code
    int x, y; // coordinates of the object on the game field

public:
    GameEntity(int startX, int startY); // constructor takes initial coordinates

    virtual ~GameEntity() = default; // virtual destructor provide proper cleanup of derived classes when deleted through base pointer

    int getX() const; // returns x coordinate (const means it doesn't modify the object)
    int getY() const;

    void setPosition(int newX, int newY); // changes object's position to new coordinates

    virtual char getSymbol() const; // virtual method - each derived class decides how to represent itself visually. Base class returns '?' as default.
};