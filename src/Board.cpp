#include "../include/Board.h"


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
}
