#pragma once

#include "GameField.h" //Я решил создать еще родительский класс, ибо в генераторе еды и просто поле нужны длина и ширина и также геттеры
#include <memory>
#include <vector>
#include <utility>
#include "Snake.h"
#incude "Food.h" //кто занимается едой, сделайте пж этот класс, у меня еще генератор еды будет

class Board : GameField {
    std::unique_ptr<Snake> snake;
    std::unique_ptr<Food> food;
    bool over;
    size_t score;
public:
    Board(int x, int y);

    int GetHeight() const override;
    int GetWidth() const override;

    Snake& getSnake() const;

    Food* getFood();

    bool isGameOver() const;

    void setFood(std::unique_ptr<Food> food);

    ~Board() = default;

    void update();

    int getScore() const;
    //сделаю еще пару главных методов попозже

};
