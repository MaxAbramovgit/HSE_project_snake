#include "../include/Board.h"

Board::Board(int x, int y)  : GameField(x, y) {
    snake = std::make_unique<Snake>(x/2, y/2);
    food = std::vector<std::unique_ptr<Food>>();
    over = false;
    score = 0;
}

Snake& Board::getSnake() const {
    if (!snake) {
        throw std::runtime_error("SNAKE IS EMPTY");
    }
    return *snake;
}

void Board::addFood(std::unique_ptr<Food> newfood) {
    food.push_back(std::move(newfood));
}

const std::vector<std::unique_ptr<Food>>&  Board::getFood() const {
    return food;
}

bool Board::isGameOver() const {
    return over;
}

int Board::GetWidth() const {
    return width;
}

int Board::GetHeight() const {
    return height;
}


int Board::getScore() const {
    return score;
}

void Board::update() {
    if (over == true) {
        return;
    }
    if (snake) {
        snake->move();
    }

    auto p = snake->getHeadPosition();
    int headX = p.first;
    int headY = p.second;
    if (headX < 0 || headX >= width || headY < 0 || headY >= height) {
        over = true;
        return;
    }
    if (snake->collidesWithSelf()) {
        over = true;
        return;
    }
    for (auto it = food.begin(); it != food.end(); ) {
        if (headX == (*it)->getX() && headY == (*it)->getY()) {
            (*it)->applyEffect(*snake);
            score += (*it)->getPoints() + 5;
            it = food.erase(it);

            return;
        } else {
            ++it;
        }
    }
}



Board::~Board() {}
