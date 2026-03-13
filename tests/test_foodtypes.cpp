#include <gtest/gtest.h>
#include <memory>

#include "FoodTypes.h"
#include "Snake.h"
#include "Food.h"

class FoodTypesTest : public ::testing::Test {
protected:
    void SetUp() override {
        banana = std::make_unique<FoodTypes>(5, 5, FoodTypes::Type::BANANA);
        hamburger = std::make_unique<FoodTypes>(5, 5, FoodTypes::Type::HAMBURGER);
        bomb = std::make_unique<FoodTypes>(5, 5, FoodTypes::Type::BOMB);
        poisonApple = std::make_unique<FoodTypes>(5, 5, FoodTypes::Type::POISON_APPLE);
        snake = std::make_unique<Snake>(5, 5);
    }

    std::unique_ptr<FoodTypes> banana;
    std::unique_ptr<FoodTypes> hamburger;
    std::unique_ptr<FoodTypes> bomb;
    std::unique_ptr<FoodTypes> poisonApple;
    std::unique_ptr<Snake> snake;
};

TEST_F(FoodTypesTest, BananaPoints) {
    EXPECT_EQ(banana->getPoints(), 1);
}

TEST_F(FoodTypesTest, HamburgerPoints) {
    EXPECT_EQ(hamburger->getPoints(), 2);
}

TEST_F(FoodTypesTest, BombPoints) {
    EXPECT_EQ(bomb->getPoints(), -3);
}

TEST_F(FoodTypesTest, PoisonApplePoints) {
    EXPECT_EQ(poisonApple->getPoints(), -1);
}

TEST_F(FoodTypesTest, BananaEffect) {
    size_t oldSize = snake->getBody().size();
    banana->applyEffect(*snake);
    EXPECT_GT(snake->getBody().size(), oldSize);
}

TEST_F(FoodTypesTest, HamburgerEffect) {
    size_t oldSize = snake->getBody().size();
    hamburger->applyEffect(*snake);
    EXPECT_GT(snake->getBody().size(), oldSize + 1);
}

TEST_F(FoodTypesTest, BombEffect) {
    bomb->applyEffect(*snake);
    EXPECT_FALSE(snake->isAlive());
}

TEST_F(FoodTypesTest, PoisonAppleEffect) {
    snake->grow();
    snake->grow();

    size_t oldSize = snake->getBody().size();
    poisonApple->applyEffect(*snake);
    EXPECT_LT(snake->getBody().size(), oldSize);
}

TEST_F(FoodTypesTest, Polymorphism) {
    Food* foodPtr = banana.get();
    EXPECT_EQ(foodPtr->getPoints(), 1);

    foodPtr = hamburger.get();
    EXPECT_EQ(foodPtr->getPoints(), 2);

    foodPtr = bomb.get();
    EXPECT_EQ(foodPtr->getPoints(), -3);

    foodPtr = poisonApple.get();
    EXPECT_EQ(foodPtr->getPoints(), -1);
}

TEST_F(FoodTypesTest, Coordinates) {
    EXPECT_EQ(banana->getX(), 5);
    EXPECT_EQ(banana->getY(), 5);

    banana->setPosition(10, 10);
    EXPECT_EQ(banana->getX(), 10);
    EXPECT_EQ(banana->getY(), 10);
}

TEST_F(FoodTypesTest, GetType) {
    EXPECT_EQ(banana->getType(), FoodTypes::Type::BANANA);
    EXPECT_EQ(hamburger->getType(), FoodTypes::Type::HAMBURGER);
    EXPECT_EQ(bomb->getType(), FoodTypes::Type::BOMB);
    EXPECT_EQ(poisonApple->getType(), FoodTypes::Type::POISON_APPLE);
}

TEST_F(FoodTypesTest, Constructor) {
    FoodTypes food(3, 4, FoodTypes::Type::POISON_APPLE);
    EXPECT_EQ(food.getX(), 3);
    EXPECT_EQ(food.getY(), 4);
    EXPECT_EQ(food.getType(), FoodTypes::Type::POISON_APPLE);
    EXPECT_EQ(food.getPoints(), -1);
}