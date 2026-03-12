#pragma once

#include <deque>
#include <memory>
#include "Segment.h"


enum class Direction {UP, DOWN, LEFT, RIGHT};

class Snake {
    std::deque<std::unique_ptr<Segment>> body;
    Direction currentDirection;
    int score;

public:
    Snake(int startX, int startY);

    Snake(const Snake&) = delete;
    Snake& operator=(const Snake&) = delete;

    Snake(Snake&&) = default;
    Snake& operator=(Snake&&) = default;

    const std::deque<std::unique_ptr<Segment>>& getBody() const;
    Direction getDirection() const;
    int getScore() const;
    std::pair<int, int> getHeadPosition() const;

    void setDirection(Direction dir);
    void move();
    void grow();
    void shrink();
    void die();

    bool collidesWith(int x, int y) const;
    bool collidesWithSelf() const;
    bool isAlive() const;

    void addScore(int points);

    void resetScore();
};

