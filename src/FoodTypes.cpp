#include "../include/FoodTypes.h"
#include "Food.h"
#include "../include/Board.h"
FoodTypes::FoodTypes(int newX, int newY, Type R) : Food(newX, newY), food_type(R){} //implementation of the FoodTypes class constructor.
//Food(newX, newY), food_type(R) is a initializer list that calls the base class constructor and initialize field food_type with R value.

int FoodTypes::getPoints()const{ // this method implements the function and returns the food points.
    //Also, we use const because the method only reads food_type, but does not change the object.
    switch (food_type) { //we use switch because there are several fixed enum options, plus it suits for enum class.
        case Type::BANANA: {
            constexpr int BANANA_POINTS = 1;
            return BANANA_POINTS;
        }
        case Type::HAMBURGER: {
            constexpr int HAMBURGER_POINTS = 2;
            return HAMBURGER_POINTS;
        }
        case Type::POISON_APPLE: {
            constexpr int POISON_POINTS = -1;
            return POISON_POINTS;
        }
        case Type::BOMB: {
            constexpr int BOMB_POINTS = -3;
            return BOMB_POINTS;
        }
    }
    return 0;
};

void FoodTypes::applyEffect(Snake &snake) {
    switch (food_type){//apply our effect to a snake. use void function because it doesnt need to return anything, just change object.
        case Type::BANANA:
            snake.grow();
            break;
        case Type::HAMBURGER:
            snake.grow();
            snake.grow();
            break;
        case Type::POISON_APPLE:
            snake.shrink();
            break;
        case Type::BOMB:
            snake.die();
            break;
    }
}
