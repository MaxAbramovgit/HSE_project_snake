#pragma once
#include "Renderer.h"
#include "FoodGenerator.h"
#include "Board.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include "../include/Snake.h"
#include <thread>
#include <chrono>

class Game
{
private:
    Board board; //contains snake and food on board
    FoodGenerator foodgenerator; //creates new food
    Renderer renderer; //handles all graphics
    bool running;

public:
    Game(int width = 30, int height = 20);

    void handleInput(); //checks users input(to start or end the game)

    void update();//check the board - if the snake is alive, if there is enough food

    void render();//checks if game is still running to tell class Renderer to continue working

    bool isRunning() const;//just checks if the game is running

    void run();//main game loop to run the game
};