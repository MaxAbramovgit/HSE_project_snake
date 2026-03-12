#include <gtest/gtest.h>
#include "FoodTypes.h"
#include "Snake.h"

class FoodTest : public ::testing::Test {
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

TEST_F(FoodTest, BananaPoints) {
    EXPECT_EQ(banana->getPoints(), 1);
}

TEST_F(FoodTest, HamburgerPoints) {
    EXPECT_EQ(hamburger->getPoints(), 2);
}

TEST_F(FoodTest, BombPoints) {
    EXPECT_EQ(bomb->getPoints(), -3);
}

TEST_F(FoodTest, PoisonApplePoints) {
    EXPECT_EQ(poisonApple->getPoints(), -1);
}

TEST_F(FoodTest, BananaEffect) {
    size_t oldSize = snake->getBody().size();
    banana->applyEffect(*snake);
    EXPECT_GT(snake->getBody().size(), oldSize);
}

TEST_F(FoodTest, HamburgerEffect) {
    size_t oldSize = snake->getBody().size();
    hamburger->applyEffect(*snake);
    EXPECT_GT(snake->getBody().size(), oldSize + 1);
}

TEST_F(FoodTest, BombEffect) {
    bomb->applyEffect(*snake);
    EXPECT_FALSE(snake->isAlive());
}

TEST_F(FoodTest, PoisonAppleEffect) {
    size_t oldSize = snake->getBody().size();
    poisonApple->applyEffect(*snake);
    EXPECT_LT(snake->getBody().size(), oldSize);
}

TEST_F(FoodTest, Polymorphism) {
    Food* foodPtr = banana.get();
    EXPECT_EQ(foodPtr->getPoints(), 1);

    foodPtr = hamburger.get();
    EXPECT_EQ(foodPtr->getPoints(), 2);
}

TEST_F(FoodTest, Coordinates) {
    EXPECT_EQ(banana->getX(), 5);
    EXPECT_EQ(banana->getY(), 5);

    banana->setPosition(10, 10);
    EXPECT_EQ(banana->getX(), 10);
    EXPECT_EQ(banana->getY(), 10);
}

TEST_F(FoodTest, GetType) {
    EXPECT_EQ(banana->getType(), FoodTypes::Type::BANANA);
    EXPECT_EQ(hamburger->getType(), FoodTypes::Type::HAMBURGER);
    EXPECT_EQ(bomb->getType(), FoodTypes::Type::BOMB);
    EXPECT_EQ(poisonApple->getType(), FoodTypes::Type::POISON_APPLE);
}

TEST_F(FoodTest, Constructor) {
    FoodTypes apple(3, 4, FoodTypes::Type::POISON_APPLE);
    EXPECT_EQ(apple.getX(), 3);
    EXPECT_EQ(apple.getY(), 4);
    EXPECT_EQ(apple.getType(), FoodTypes::Type::POISON_APPLE);
    EXPECT_EQ(apple.getPoints(), -1);
}