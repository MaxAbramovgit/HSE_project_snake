#pragma once

class GameEntity {
protected:
    int x, y;

public:
    GameEntity(int startX, int startY);

    virtual ~GameEntity() = default;

    int getX() const;
    int getY() const;

    void setPosition(int newX, int newY);

    virtual char getSymbol() const;
};
