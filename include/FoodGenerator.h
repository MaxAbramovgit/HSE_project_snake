#pragma once
#include <memory>
#include <random>
#include <vector>
#include <utility>
#include "Food.h"
#include "Board.h"

class FoodGenerator {
public:
    std::unique_ptr<Food>generate(const Board& board);
};