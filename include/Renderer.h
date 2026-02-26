#pragma once
#include "Board.h"

class Renderer
{
private:
    const Board& board;

public:
    Renderer(const Board& newboard);

    void render() const;

    void renderGameOver() const;

    void clearScreen();
};