#include <gtest/gtest.h>
#include "Board.h"
#include "FoodTypes.h"

class BoardTest : public ::testing::Test {
protected:
    void SetUp() override {
        board = std::make_unique<Board>(10, 10);
    }

    std::unique_ptr<Board> board;
};

TEST_F(BoardTest, Initialization) {
    EXPECT_EQ(board->GetWidth(), 10);
    EXPECT_EQ(board->GetHeight(), 10);
    EXPECT_FALSE(board->isGameOver());
    EXPECT_EQ(board->getScore(), 0);
    EXPECT_TRUE(board->getFood().empty());
}

TEST_F(BoardTest, AddFood) {
    auto food = std::make_unique<FoodTypes>(5, 5, FoodTypes::Type::BANANA);
    board->addFood(std::move(food));
    EXPECT_EQ(board->getFood().size(), 1);
}

TEST_F(BoardTest, GetSnake) {
    EXPECT_NO_THROW(board->getSnake());
    EXPECT_TRUE(board->getSnake().isAlive());
}


TEST_F(BoardTest, GameOverWhenHitWall) {
    auto& snake = board->getSnake();

    snake.setDirection(Direction::RIGHT);
    for (int i = 0; i < 10; ++i) {
        board->update();
        if (board->isGameOver()) break;
    }
    EXPECT_TRUE(board->isGameOver());
}

TEST_F(BoardTest, GameOverWhenHitSelf) {
    auto& snake = board->getSnake();
    for (int i = 0; i < 5; ++i) {
        snake.grow();
    }
    snake.setDirection(Direction::RIGHT);
    for (int i = 0; i < 3; ++i) {
        board->update();
    }
    snake.setDirection(Direction::UP);
    board->update();
    snake.setDirection(Direction::LEFT);
    board->update();
    snake.setDirection(Direction::DOWN);
    board->update();
    EXPECT_TRUE(board->isGameOver());
}

TEST_F(BoardTest, MultipleFoods) {
    board->addFood(std::make_unique<FoodTypes>(3, 3, FoodTypes::Type::BANANA));
    board->addFood(std::make_unique<FoodTypes>(4, 4, FoodTypes::Type::HAMBURGER));
    board->addFood(std::make_unique<FoodTypes>(5, 5, FoodTypes::Type::BOMB));
    EXPECT_EQ(board->getFood().size(), 3);
}


TEST_F(BoardTest, ScoreIncreases) {
    auto food = std::make_unique<FoodTypes>(6, 5, FoodTypes::Type::BANANA);
    board->addFood(std::move(food));
    auto& snake = board->getSnake();
    snake.setDirection(Direction::RIGHT);
    board->update();
    EXPECT_EQ(board->getScore(), 5 + 1);
}