#pragma once
#include "Renderer.h"
#include "FoodGenerator.h"
#include "Board.h"
#include <memory>
#include <SFML/Graphics.hpp>

class Game
{
private:
    Board board;
    FoodGenerator foodgenerator;
    Renderer renderer;
    bool running;

public:
    Game(int width = 30, int height = 20);

    void handleInput();

    void update();

    void render();

    bool isRunning() const;

    void run();
};