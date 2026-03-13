#pragma once
#include "Board.h"
#include "Food.h"

class FoodTypes : public Food { //we make a class FoodTypes that have an inheritance from Food.
public: //use public, because all the fruits (oblects) will be n use in other files.
    enum class Type {
        BANANA,
        HAMBURGER,
        BOMB,
        POISON_APPLE
    };
    static constexpr int FOOD_TYPE_COUNT = 4; //use static, because this constant belongs to the class and not to a specific object. We use constexpr because the value is known at the compilation stage.
    Type getType() const{return food_type;} //getter, returning the type of current food. It relevant for us because we can find out what type is stored in the object.
private: //to hide our realization
    Type food_type; //field in which the type of food is stored (so object would now what is it exactly).
public:
    FoodTypes(int newX, int newY, Type R); //initialize the constructor.
    int getPoints() const override; //have a redefinition of the base class virtual function. We use override because we need EXACTLY override the Food::getPoints().
    void applyEffect(Snake& snake) override; //override the virtual function from Food. Changes the snake according to the fruit that she ate.
};