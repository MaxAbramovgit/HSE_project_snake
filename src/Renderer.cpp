#include <iostream>
#include <vector>
#include "../include/Renderer.h"
#include "../include/Board.h"
#include "../include/Food.h"
#include "../include/FoodTypes.h"
#include <SFML/Graphics.hpp>


Renderer::Renderer(const Board& newboard, int cellSize)
    : board(newboard),
    cellSize(cellSize),
    window(sf::VideoMode(newboard.GetWidth() * cellSize,
        newboard.GetHeight() * cellSize, "Snake Game")
{
    if (!font.loadFromFile("Arial.ttf"))
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
    gameOverText.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 - 20);
}

void Renderer::render() const
{
    window.clear(sf::Color::Black);

    sf::RectangleShape gridLine(sf::Vector2f(cellSize, 1));
    gridLine.setFillColor(sf::Color(50, 50, 50));

    const auto& snake = board.getSnake();
    if (snake.isAlive())
    {
        const auto& body = snake.getBody();
        sf::RectangleShape cell(sf::Vector2f(cellSize - 2, cellSize - 2));

        for (size_t i = 0; i < body.size(); ++i)
        {
            int x = body[i]->getX;
            int y = body[i]->getY;

            cell.setPosition(x * cellSize + 1, y * cellSize + 1);

            if (i == 0)
            {
                cell.setFillColor(sf::Color::Green); // цвет головы будет зеленый
            }

            else
            {
                if (body[i]->getType() == SegmentType::GHOST)
                {
                    cell.setFillColor(sf::Color(200, 200, 200));
                }

                else
                {
                    cell.setFillColor(sf::Color::Yellow); // цвет тела змейки будет желтым
                }
            }

            window.draw(cell);
        }
    }


    FoodTypes* food = board.getFood();
    if (food)
    {
        sf::RectangleShape cell(sf::Vector2f(cellSize - 2, cellSize - 2));

        cell.setPosition(food->getX() * cellSize + 1, food->getY() * cellSize + 1);

        switch(food->food_type)
        {
        case FoodTypes::BANANA:
            cell.setFillColor(sf::Color::Yellow);
            break;
        case FoodTypes::HAMBURGER:
            cell.setFillColor(sf::Color::Brown)
            break;
        case FoodTypes::BOMB:
            cell.setFillColor(sf::Color::Black);
            break;
        case FoodTypes::POIZONAPPLE:
            cell.setFillColor(sf::Color::Red);
            break;
        }
        window.draw(cell);
    }

    scoreText.setString("Score: " + std::to_string(board.getScore()));
    window.draw(scoreText);
    window.display();
}

void Renderer::renderGameOver() const
{
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