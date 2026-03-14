#pragma once

class GameField {
protected:
    int height;
    int width;
public:
    GameField(int x, int y); //constructor

    virtual int GetWidth() const; //return width

    virtual int GetHeight() const; //return height

    virtual ~GameField() = default; //destructor
};
