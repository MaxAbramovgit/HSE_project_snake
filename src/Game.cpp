#include <iostream>
#include "Game.h"


class Game
{
    Game::Game(int width, int height) : board(width, height), foodgenerator(width, height), renderer(board), running(true) { }

    void Game::handleInput()
    {
        char input;
        std::cin >> input;

        auto& snake = board.getSnake();

        if (input == "w" || input == "W")
        {
            snake.setDirection(Direction::UP);
        }

        if (input == "s" || input == "S")
        {
            snake.setDirection(Direction::DOWN);
        }

        if (input == "a" || input == "A")
        {
            snake.setDirection(Direction::LEFT);
        }

        if (input == "d" || input == "D")
        {
            snake.setDirection(Direction::RIGHT);
        }

        if (input == "q" || input == "Q")
        {
            running = false;
        }
    }

    void Game::update()
    {
        board.update();

        if (board.getFood() == nullptr && !(board.isGameOver()))
        {
            auto addFood = foodgenerator.generateFoodNotOnSnake(board.getSnake());
            board.setFood(std::move(addFood));
        }
    }

    void Game::render() const
    {
        renderer.render();
    }

    bool Game::isRunning()
    {
        return (running && !(board.isGameOver));
    }

    void Game::run()
    {
        while(isRunning)
        {

        }
    }
};