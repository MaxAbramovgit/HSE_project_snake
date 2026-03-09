#include "gtest/gtest.h"

#include "../include/Snake.h"

TEST(SnakeTest, Placeholder) {
    EXPECT_TRUE(true);
}

TEST(SnakeTest, MoveChangesPosition) {
    Snake snake(10, 10);
    auto [oldX, oldY] = snake.getHeadPosition();
    snake.move();
    auto [newX, newY] = snake.getHeadPosition();
    EXPECT_NE(oldX, newX);
}