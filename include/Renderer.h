#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

class Renderer
{
private:
    sf::RenderWindow window;
    const Board& board;

    int cellSize;
    sf::Font font;
    sf::Text scoreText;
    sf::Text gameOverText;


public:
    explicit Renderer(const Board& newboard, int cellSize = 30);

    void render();
    void renderGameOver();
    bool isOpen() const;
    void close();
    bool pollEvent(sf::Event& event);
};