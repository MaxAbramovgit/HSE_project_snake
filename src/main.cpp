#include <iostream>
#include "../include/Game.h"


int main() {
    try
    {
        Game game(30, 25);
        game.run();
    }

    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}