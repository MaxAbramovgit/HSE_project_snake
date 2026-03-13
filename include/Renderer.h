#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "../include/FoodTypes.h"
#include <iostream>
#include <vector>

class Renderer
{
private:
    const Board& board;//renderer does not need to manage the game logic(needs just to look on it to draw)
    //- that is why we have only reference, not the exact element (it also saves the memory)
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
    explicit Renderer(const Board& newboard, int cellSize = 30); //чтобы нельзя было использовать конструктор с одним элементом

    void render();//draws everything - grid, food
    void renderGameOver();//shows "Game Over" and "score"
    bool isOpen() const;//checks if window is open
    void close();//closes the window
    bool pollEvent(sf::Event& event); //sf::event - its union structure, it represents interactions between user and window.
    //Shows that smth happened - for example game opened/closed

};