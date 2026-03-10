#include "../include/Game.h"
#include "../include/Snake.h"
#include "../include/FoodGenerator.h"
#include <thread>
#include <chrono>


Game::Game(int width, int height) : board(width, height),
    foodgenerator(board.GetWidth(), board.GetHeight()),
    renderer(board, 20),
    running(true) { }

void Game::handleInput()
{
    sf::Event event = sf::Event();
    while (renderer.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            running = false;
            renderer.close();
        }

        if (event.type == sf::Event::KeyPressed)
        {
            Snake& snake = board.getSnake();

            if (!snake.isAlive())
            {
                continue;
            }

            switch(event.key.code)
            {
            case sf::Keyboard::W:
            case sf::Keyboard::Up:
                snake.setDirection(Direction::UP);
                break;
            case sf::Keyboard::S:
            case sf::Keyboard::Down:
                snake.setDirection(Direction::DOWN);
                break;
            case sf::Keyboard::A:
            case sf::Keyboard::Left:
                snake.setDirection(Direction::LEFT);
                break;
            case sf::Keyboard::D:
            case sf::Keyboard::Right:
                snake.setDirection(Direction::RIGHT);
                break;
            case sf::Keyboard::Q:
            case sf::Keyboard::Escape:
                running = false;
                renderer.close();
                break;
            default:
                break;
            }
        }
    }
}

void Game::update()
{
    if (!running)
    {
        return;
    }

    board.update();

    if (board.getFood() == nullptr && !board.isGameOver())
    {
        if (std::unique_ptr<Food> newFood = foodgenerator.generate(board.getSnake()))
        {
            board.setFood(std::move(newFood));
        }
    }
}

void Game::render()
{
    if (renderer.isOpen())
    {
        renderer.render();
    }
}

bool Game::isRunning() const
{
    return (running && !board.isGameOver() && renderer.isOpen());
}

void Game::run()
{
    constexpr int frameDelay = 200; // 100 миллисекунд будет между кадрами

    while(isRunning())
    {
        auto startTime = std::chrono::steady_clock::now();

        handleInput();
        update();
        render();

        auto endTime = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

        if (elapsed.count() < frameDelay)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(frameDelay - elapsed.count()));
        }
    }

    renderer.renderGameOver();
    std::this_thread::sleep_for(std::chrono::seconds(2));
}