#pragma once

class GameField {
protected:
    int height;
    int width;
public:
    GameField(int x, int y);

    virtual int GetWidth() const ;

    virtual int GetHeight() const;

    virtual ~GameField() = default;
};
