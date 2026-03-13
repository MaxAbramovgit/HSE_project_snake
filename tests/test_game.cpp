#include <gtest/gtest.h>
#include "Game.h"
#include "Snake.h"

class GameTest : public ::testing::Test {
protected:
    void SetUp() override {
        game = std::make_unique<Game>(10, 10);
    }

    std::unique_ptr<Game> game;
};

TEST_F(GameTest, ConstructorDoesntCrash) {
    EXPECT_NE(game, nullptr);
}

TEST_F(GameTest, InitiallyRunning) {
    EXPECT_TRUE(game->isRunning());
}

TEST_F(GameTest, UpdateDoesntCrash) {
    EXPECT_NO_THROW(game->update());
}

TEST_F(GameTest, HandleInputDoesntCrash) {
    EXPECT_NO_THROW(game->handleInput());
}

TEST_F(GameTest, RenderDoesntCrash) {
    EXPECT_NO_THROW(game->render());
}

TEST_F(GameTest, StillRunningAfterManyUpdates) {
    game->update();
    EXPECT_TRUE(game->isRunning());
}
