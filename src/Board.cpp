#include "../include/Board.h"
#include "../include/Snake.h"


Board::Board(int x, int y)  : GameField(x, y) {
    std::make_unique<Snake>(x/2, y/2);
    food = nullptr;
    over = false;
    score = 0;
}

Snake& Board::getSnake() const {
    return *snake;
}

Food* Board::getFood() const {
    return food;
}

bool Board::isGameOver() const {
        return over;
}

void Board::setFood(std::unique_ptr<Food> food) {
    this->food = std::move(food);
}

int Board::getScore() const {
    return score;
}

void Board::update() {
    if (over == true || food == nullptr) {
        return;
    }
    snake->move();
    int headX = snake->getHeadX();
    int headY = snake->getHeadY();
    if (headX < 0 || headX >= getWidth() || headY < 0 || headY >= getHeight()) {
        over = true;
        return;
    }
    if (snake->collidesWithSelf()) {
        over = true;
        return;
    }
    if (headX == food->getX() && headY == food->getY()) {
        food->applyEffect(*snake);
        score += 10;
        food.reset();
    }
}
