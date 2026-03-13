#pragma once

#include <deque>
#include <memory>
#include "Segment.h"

enum class Direction { UP, DOWN, LEFT, RIGHT }; // scoped enum for safe direction values

class Snake {
    std::deque<std::unique_ptr<Segment>> body; // deque of segments - perfect for snake: fast push_front (new head) and pop_back (remove tail)
    Direction currentDirection; // which way the snake is currently moving
    int score; // current score

public:
    Snake(int startX, int startY); // creates snake with 3 segments at given position

    // Rule of Five: explicitly manage copying/moving because of unique_ptr
    Snake(const Snake&) = delete; // prohibit copying (unique_ptr cannot be copied)
    Snake& operator=(const Snake&) = delete; // prohibit copy assignment

    Snake(Snake&&) = default; // allow moving (transfer ownership of segments)
    Snake& operator=(Snake&&) = default; // allow move assignment

    const std::deque<std::unique_ptr<Segment>>& getBody() const; // returns const reference to body (read-only for renderer)
    Direction getDirection() const; // returns current direction
    int getScore() const; // returns current score
    std::pair<int, int> getHeadPosition() const; // returns (x,y) coordinates of head as a pair

    void setDirection(Direction dir); // changes direction (with 180° turn protection)
    void move(); // moves snake one step in current direction
    void grow(); // increases snake length by one segment
    void shrink(); // decreases snake length by one segment
    void die(); // kills snake (clears body)

    bool collidesWith(int x, int y) const; // checks if any segment is at given coordinates
    bool collidesWithSelf() const; // checks if head collides with body
    bool isAlive() const; // returns true if snake has segments

    void addScore(int points); // adds (or subtracts if negative) points to score
    void resetScore(); // resets score to zero
};

