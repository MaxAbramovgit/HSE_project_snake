#pragma once

class GameField {
protected:
    int height;
    int width;
public:
    GameField(int x, int y);

    virtual int GetWidth();

    virtual int GetHeight();

    virtual ~GameField() = default;
};
