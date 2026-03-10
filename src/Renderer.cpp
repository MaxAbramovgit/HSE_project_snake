#include <iostream>
#include <vector>
#include "../include/Renderer.h"
#include "../include/Board.h"
#include "../include/FoodTypes.h"
#include <SFML/Graphics.hpp>

Renderer::Renderer(const Board& otherboard, int cellSize)
    : board(otherboard),
    cellSize(cellSize),
    window(sf::VideoMode(otherboard.GetWidth() * cellSize,
        otherboard.GetHeight() * cellSize),
        "Snake Game")
{
    if (!font.loadFromFile("arialmt.ttf"))
    {
        std::cerr << "Warning: could not load Arial.ttf" << std::endl;
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    gameOverText.setFont(font);
    gameOverText.setCharacterSize(40);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setString("GAME OVER!");

    gameOverText.setPosition(static_cast<float>(window.getSize().x) / 2.0f - 100.0f,
        static_cast<float>(window.getSize().y) / 2.0f - 20.0f);
}

void Renderer::render()
{
    window.clear(sf::Color::Black);

    sf::VertexArray grid(sf::Lines);

    for (int x = 0; x <= board.GetWidth(); ++x)
    {
        float positionX = static_cast<float>(x * cellSize);
        grid.append(sf::Vertex(sf::Vector2f(positionX, 0.0f),
            sf::Color::White));
        grid.append(sf::Vertex(sf::Vector2f(positionX, static_cast<float>(board.GetHeight() * cellSize)),
            sf::Color::White));
    }

    for (int y = 0; y <= board.GetHeight(); ++y)
    {
        float positionY = static_cast<float>(y * cellSize);
        grid.append(sf::Vertex(sf::Vector2f(0.0f, positionY),
            sf::Color::White));
        grid.append(sf::Vertex(sf::Vector2f(static_cast<float>(board.GetWidth() * cellSize), positionY),
            sf::Color::White));
    }

    window.draw(grid);

    const auto& snake = board.getSnake();
    if (snake.isAlive())
    {
        const auto& body = snake.getBody();
        sf::RectangleShape cell(sf::Vector2f(static_cast<float>(cellSize - 2), static_cast<float>(cellSize - 2)));

        for (size_t i = 0; i < body.size(); ++i)
        {
            int x = body[i]->getX();
            int y = body[i]->getY();

            cell.setPosition(static_cast<float>(x * cellSize + 1), static_cast<float>(y * cellSize + 1));

            if (i == 0)
            {
                cell.setFillColor(sf::Color(0, 100, 0)); // цвет головы будет темно зеленый
            }

            else
            {
                cell.setFillColor(sf::Color(34, 139, 34)); // цвет тела змейки будет светло-зеленый
            }

            window.draw(cell);
        }
    }


    for (const std::unique_ptr<Food>& food : board.getFood())
    {
        if (auto* foodType = dynamic_cast<FoodTypes*>(food.get()))
        {
            sf::RectangleShape cell(sf::Vector2f(static_cast<float>(cellSize - 2), static_cast<float>(cellSize - 2)));

            cell.setPosition(static_cast<float>(food->getX() * cellSize + 1), static_cast<float>(food->getY() * cellSize + 1));

            switch(foodType->getType())
            {
            case FoodTypes::Type::BANANA:
                cell.setFillColor(sf::Color::Yellow);
                break;
            case FoodTypes::Type::HAMBURGER:
                cell.setFillColor(sf::Color(165, 42, 42));
                break;
            case FoodTypes::Type::BOMB:
                cell.setFillColor(sf::Color::Blue);
                break;
            case FoodTypes::Type::POISON_APPLE:
                cell.setFillColor(sf::Color::Red);
                break;
            }
            window.draw(cell);
        }
    }

    scoreText.setString("Score: " + std::to_string(board.getScore()));
    window.draw(scoreText);
    window.display();
}

void Renderer::renderGameOver()
{
    window.clear(sf::Color::Black);
    window.draw(gameOverText);
    window.display();
}

bool Renderer::isOpen() const
{
    return window.isOpen();
}

void Renderer::close()
{
    window.close();
}

bool Renderer::pollEvent(sf::Event& event)
{
    return window.pollEvent(event);
}