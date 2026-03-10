//
// Created by max abramov on 26.02.2026.
//

#include "../include/GameField.h"

GameField::GameField(int w, int h) : width(w), height(h) {}

int GameField::GetWidth() const {
    return width;
}

int GameField::GetHeight() const {
    return height;
}