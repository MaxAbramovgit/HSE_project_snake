#pragma once
#include "GameEntity.h"
#include "Snake.h"

class Food : public GameEntity { // inheritance from GameEntity.
public: // we do it public, becuse we need to use Food in GameEntity.
    Food(int x, int y) : GameEntity(x, y) {} // it takes the coordinates (x,y) and then calls the constructor. We need it to make our food w coordinates.

    virtual int getPoints() const = 0; //each specific type of food must know how many points it gives. We use virtual to make the polymorphism work. If you have a pointer or link to Food, when you call getPoints(), the implementation of a specific descendant will be called.
    virtual void applyEffect(Snake& snake) = 0; // we have a Snake& snake as a parameter, because we need to change an existing snake.
    virtual ~Food() = default; //declares the default virtual destructor. If we delete a descendant object through a pointer to the base class, then without a virtual destructor only a base class destructor can be called and will lead to a mistake.
};