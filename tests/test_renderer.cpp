#include <gtest/gtest.h>
#include "Renderer.h"
#include "Board.h"
#include "FoodTypes.h"

class RendererTest : public ::testing::Test {
protected:
    void SetUp() override {
        board = std::make_unique<Board>(10, 10);
        renderer = std::make_unique<Renderer>(*board, 30);
    }

    std::unique_ptr<Board> board;
    std::unique_ptr<Renderer> renderer;
};

TEST_F(RendererTest, WindowIsCreated) {
    EXPECT_TRUE(renderer->isOpen());
}

TEST_F(RendererTest, WindowCanBeClosed) {
    renderer->close();
    EXPECT_FALSE(renderer->isOpen());
}

TEST_F(RendererTest, PollEvent) {
    sf::Event event;
    EXPECT_NO_THROW(renderer->pollEvent(event));
}

TEST_F(RendererTest, RenderWithoutCrash) {
    EXPECT_NO_THROW(renderer->render());
}

TEST_F(RendererTest, RenderGameOverWithoutCrash) {
    EXPECT_NO_THROW(renderer->renderGameOver());
}

TEST_F(RendererTest, RenderWithFood) {
    auto food = std::make_unique<FoodTypes>(5, 5, FoodTypes::Type::BANANA);
    board->addFood(std::move(food));

    EXPECT_NO_THROW(renderer->render());
}

TEST_F(RendererTest, RenderWithAllFoodTypes) {
    board->addFood(std::make_unique<FoodTypes>(2, 2, FoodTypes::Type::BANANA));
    board->addFood(std::make_unique<FoodTypes>(3, 3, FoodTypes::Type::HAMBURGER));
    board->addFood(std::make_unique<FoodTypes>(4, 4, FoodTypes::Type::BOMB));
    board->addFood(std::make_unique<FoodTypes>(5, 5, FoodTypes::Type::POISON_APPLE));

    EXPECT_NO_THROW(renderer->render());
}

TEST_F(RendererTest, RenderWithDeadSnake) {
    board->getSnake().die();
    EXPECT_NO_THROW(renderer->render());
}

TEST_F(RendererTest, RenderWithScore) {
    auto food = std::make_unique<FoodTypes>(6, 5, FoodTypes::Type::BANANA);
    board->addFood(std::move(food));

    auto& snake = board->getSnake();
    snake.setDirection(Direction::RIGHT);
    board->update();

    EXPECT_NO_THROW(renderer->render());
}

TEST_F(RendererTest, DifferentCellSizes) {
    Renderer smallRenderer(*board, 20);
    Renderer bigRenderer(*board, 50);

    EXPECT_NO_THROW(smallRenderer.render());
    EXPECT_NO_THROW(bigRenderer.render());
}

TEST_F(RendererTest, ReferencesSameBoard) {
    auto food = std::make_unique<FoodTypes>(3, 3, FoodTypes::Type::HAMBURGER);
    board->addFood(std::move(food));
    EXPECT_NO_THROW(renderer->render());
}

TEST_F(RendererTest, MultipleEvents) {
    sf::Event event;
    for (int i = 0; i < 10; ++i) {
        EXPECT_NO_THROW(renderer->pollEvent(event));
    }
}

TEST_F(RendererTest, CloseAndCheck) {
    renderer->close();
    EXPECT_FALSE(renderer->isOpen());
}

TEST_F(RendererTest, RenderAfterClose) {
    renderer->close();
    EXPECT_NO_THROW(renderer->render());
}

TEST_F(RendererTest, RenderWithNormalState) {
    EXPECT_NO_THROW(renderer->render());
}