#include <gtest/gtest.h>
#include "FoodGenerator.h"
#include "Snake.h"
#include "FoodTypes.h"

class FoodGeneratorTest : public ::testing::Test {
protected:
    void SetUp() override {
        generator = std::make_unique<FoodGenerator>(10, 10);
        snake = std::make_unique<Snake>(5, 5);
    }

    std::unique_ptr<FoodGenerator> generator;
    std::unique_ptr<Snake> snake;
};

TEST_F(FoodGeneratorTest, FoodWithinBounds) {
    auto food = generator->generateRandomFood();
    int x = food->getX();
    int y = food->getY();

    EXPECT_GE(x, 0);
    EXPECT_LT(x, 10);
    EXPECT_GE(y, 0);
    EXPECT_LT(y, 10);
}

TEST_F(FoodGeneratorTest, FoodNotsdOnSnake) {
    auto result = generator->generate(*snake);
    ASSERT_TRUE(result.has_value()) << "Failed to generate food";
    auto& food = *result;
    EXPECT_NE(food, nullptr);
    EXPECT_FALSE(snake->collidesWith(food->getX(), food->getY()));
}


TEST_F(FoodGeneratorTest, RandomFoodNotNull) {
    auto food = generator->generateRandomFood();
    EXPECT_NE(food, nullptr);
}

TEST_F(FoodGeneratorTest, GenerateNotNull) {
    auto food = generator->generate(*snake);
    EXPECT_NE(food, nullptr);
}

TEST_F(FoodGeneratorTest, AllFoodTypes) {
    bool hasBanana = false;
    bool hasBurger = false;
    bool hasBomb = false;
    bool hasApple = false;

    for (int i = 0; i < 50; ++i) {
        auto food = generator->generateRandomFood();
        auto* foodType = dynamic_cast<FoodTypes*>(food.get());
        ASSERT_NE(foodType, nullptr);

        switch (foodType->getType()) {
            case FoodTypes::Type::BANANA:
                hasBanana = true;
                break;
            case FoodTypes::Type::HAMBURGER:
                hasBurger = true;
                break;
            case FoodTypes::Type::BOMB:
                hasBomb = true;
                break;
            case FoodTypes::Type::POISON_APPLE:
                hasApple = true;
                break;
        }
    }

    EXPECT_TRUE(hasBanana);
    EXPECT_TRUE(hasBurger);
    EXPECT_TRUE(hasBomb);
    EXPECT_TRUE(hasApple);
}

TEST_F(FoodGeneratorTest, GenerateOnFullBoard) {
    for (int i = 0; i < 50; ++i) {
        snake->grow();
    }

    auto result = generator->generate(*snake);
    ASSERT_TRUE(result.has_value()) << "Failed to generate food";
    auto& food = *result;
    EXPECT_NE(food, nullptr);
    EXPECT_FALSE(snake->collidesWith(food->getX(), food->getY()));
}

TEST_F(FoodGeneratorTest, DifferentSeeds) {
    FoodGenerator gen1(10, 10);
    FoodGenerator gen2(10, 10);

    auto food1 = gen1.generateRandomFood();
    auto food2 = gen2.generateRandomFood();
    EXPECT_NE(food1, nullptr);
    EXPECT_NE(food2, nullptr);
}