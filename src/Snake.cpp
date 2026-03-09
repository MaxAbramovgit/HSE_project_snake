#include "../include/Snake.h"
#include <algorithm>

Snake::Snake(int startX, int startY)
    : currentDirection(Direction::RIGHT)
    , score(0) {

    body.push_back(std::make_unique<Segment>(startX, startY));
    body.push_back(std::make_unique<Segment>(startX - 1, startY));
    body.push_back(std::make_unique<Segment>(startX - 2, startY));
}

const std::deque<std::unique_ptr<Segment>>& Snake::getBody() const {
    return body;
}

Direction Snake::getDirection() const {
    return currentDirection;
}

int Snake::getScore() const {
    return score;
}

std::pair<int, int> Snake::getHeadPosition() const {
    return {body.front()->getX(), body.front()->getY()};
}

void Snake::setDirection(Direction dir) {
    if ((currentDirection == Direction::UP && dir == Direction::DOWN) ||
        (currentDirection == Direction::DOWN && dir == Direction::UP) ||
        (currentDirection == Direction::LEFT && dir == Direction::RIGHT) ||
        (currentDirection == Direction::RIGHT && dir == Direction::LEFT)) {
        return;
    }
    currentDirection = dir;
}

void Snake::move() {
    auto [headX, headY] = getHeadPosition();

    switch (currentDirection) {
        case Direction::UP:    headY--; break;
        case Direction::DOWN:  headY++; break;
        case Direction::LEFT:  headX--; break;
        case Direction::RIGHT: headX++; break;
    }

    auto newHead = std::make_unique<Segment>(headX, headY);

    body.push_front(std::move(newHead));
    body.pop_back();
}

void Snake::grow() {
    auto& tail = body.back();
    body.push_back(std::make_unique<Segment>(
        tail->getX(), tail->getY()
    ));
}

void Snake::shrink() {
    if (body.size() > 1) {
        body.pop_back();
    }
    if (body.size() <= 1) {
        die();
    }
}

void Snake::die() {
    body.clear();
}

bool Snake::collidesWith(int x, int y) const {
    return std::any_of(body.begin(), body.end(), [x, y](const auto& segment) {
        return segment->getX() == x && segment->getY() == y;
    });
}

bool Snake::collidesWithSelf() const {
    if (body.size() <= 1) return false;

    auto head = body.front().get();
    return std::any_of(body.begin() + 1, body.end(), [head](const auto& segment) {
        return segment->getX() == head->getX() && segment->getY() == head->getY();
    });
}

bool Snake::isAlive() const {
    return !body.empty();
}

void Snake::addScore(int points) {
    score += points;
}

void Snake::resetScore() {
    score = 0;
}
