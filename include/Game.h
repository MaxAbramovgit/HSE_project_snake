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
    Game(int width = 20, int height = 15);

    void handleInput();

    void update();

    void render() const;

    bool isRunning();

    void run();
};