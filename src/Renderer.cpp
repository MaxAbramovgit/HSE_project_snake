#include <iostream>
#include "Renderer.h"
#include "Board.h"
#include "Food.h"
#include "FoodType.h"


class Renderer
{
    Renderer::Renderer(const Board& newboard) : board(newboard) { }

    void Renderer::clearScreen()
    {
        system("clear");
    }

    void Renderer::render() const
    {
        clearScreen();

        std::vector<std::vector<char>> field(height, std::vector<char>(width, '.'));

        for (int i = 0; i < board.getSnake().getBody().size(); ++i)
        {
            int currentX = board.getSnake().getBody()[i]->getX;
            int currentY = board.getSnake().getBody()[i]->getY;

            field[currentY][currentX] = 'Z'; //means that snake is in that place
        }

        Food* food = board.getFood();
        if (board.getFood() != nullptr)
        {
            int currentX = board.getFood()->getX;
            int currentY = board.getFood()->getY;

            if (dynamic_cast<POISONAPPLE*>(food))
            {
                field[currentX][currentY] = 'P';
            }

            if (dynamic_cast<BANANA*>(food))
            {
                field[currentX][currentY] = 'B';
            }

            if (dynamic_cast<HAMBURGER*>(food))
            {
                field[currentX][currentY] = 'H';
            }

            if (dynamic_cast<BOMB*>(food))
            {
                field[currentX][currentY] = 'B';
            }
        }
    }

    void Renderer::renderGameOver() const
    {

    }
};