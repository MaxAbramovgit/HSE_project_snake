#include <gtest/gtest.h>
#include "Snake.h"

class SnakeTest : public ::testing::Test {
protected:
    void SetUp() override {
        snake = std::make_unique<Snake>(5, 5);
    }

    std::unique_ptr<Snake> snake;
};

TEST_F(SnakeTest, SnakeInitialization) {
    EXPECT_EQ(snake->getBody().size(), 3);
    EXPECT_TRUE(snake->isAlive());
}

TEST_F(SnakeTest, SnakeMove) {
    auto [oldX, oldY] = snake->getHeadPosition();
    snake->move();
    auto [newX, newY] = snake->getHeadPosition();
    EXPECT_NE(oldX, newX);
}

TEST_F(SnakeTest, SnakeGrow) {
    size_t oldSize = snake->getBody().size();
    snake->grow();
    EXPECT_EQ(snake->getBody().size(), oldSize + 1);
}

TEST_F(SnakeTest, SnakeShrink) {
    size_t oldSize = snake->getBody().size();
    snake->shrink();
    EXPECT_EQ(snake->getBody().size(), oldSize - 1);
}

TEST_F(SnakeTest, SnakeDie) {
    snake->die();
    EXPECT_FALSE(snake->isAlive());
}

TEST_F(SnakeTest, CollidesWithSelf) {
}