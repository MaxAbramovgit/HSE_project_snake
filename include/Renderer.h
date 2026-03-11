#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

class Renderer
{
private:
    const Board& board;
    int cellSize;
    sf::RenderWindow window;

    sf::Font font;
    sf::Text scoreText;
    sf::Text gameOverText;
    sf::Text gameOverText_score;

    sf::Texture bananaTex;
    sf::Texture burgerTex;
    sf::Texture bombTex;
    sf::Texture poisonTex;

    sf::Sprite foodSprite;

public:
    explicit Renderer(const Board& newboard, int cellSize = 30);

    void render();
    void renderGameOver();
    bool isOpen() const;
    void close();
    bool pollEvent(sf::Event& event);
};