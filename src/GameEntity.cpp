#include "../include/GameEntity.h"

GameEntity::GameEntity(int startX, int startY) : x(startX), y(startY) {}

int GameEntity::getX() const { return x; }
int GameEntity::getY() const { return y; }

void GameEntity::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

char GameEntity::getSymbol() const { return '?'; }
