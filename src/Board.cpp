#include "../include/Board.h"

Board::Board(int x, int y)  : GameField(x, y) {//constructor
    snake = std::make_unique<Snake>(x/2, y/2);
    food = std::vector<std::unique_ptr<Food>>();
    over = false;
    score = 0;
}

Snake& Board::getSnake() const {//getter of the reference of the snake
    if (!snake) {
        throw std::runtime_error("SNAKE IS EMPTY");
    }
    return *snake;
}

void Board::addFood(std::unique_ptr<Food> newfood) {//we add noew food to vector of all foods, which are on the board
    if (!isCellOccupiedByFood(newfood->getX(), newfood->getY())) {
        food.push_back(std::move(newfood));
        return;
    }
}

const std::vector<std::unique_ptr<Food>>&  Board::getFood() const {//returning the reference of vector
    return food;
}

bool Board::isGameOver() const { //return the field over (boolean value which show if game is over)
    return over;
}

int Board::GetWidth() const { //getter of height
    return width;
}

int Board::GetHeight() const { //getter of width
    return height;
}


int Board::getScore() const { //getter of the score
    return score;
}

void Board::update() {//this metod is called every change of frame and checks if game is over, if it collides with wall/itself, if it ate new food and move it to the next cell
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
            if (!snake->isAlive()) {
                over = true;
            }
            return;
        } else {
            ++it;
        }
    }
}

bool Board::isCellOccupiedByFood(int x, int y) const {//checks if the cell at these coordinates occupied by food
    for (const auto& f : food) {
        if (f->getX() == x && f->getY() == y) {
            return true;
        }
    }
    return false;
}



Board::~Board() {}
