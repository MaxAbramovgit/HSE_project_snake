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
public:
    Board(int x, int y) : GameField(x, y) {
            std::make_unique<Snake>(x/2, y/2);
            food = nullptr;
            over = false;
    }

    int GetHeight() const override;
    int GetWidth() const override;

    Snake& getSnake() const {
        return *snake;
    }

    Food* getFood() const {
        return food;
    }

    bool isGameOver() const {
        return over;
    }

    void setFood(std::unique_ptr<Food> food) {
        this->food = std::move(food);
    }

    //сделаю еще пару главных методов попозже

};
